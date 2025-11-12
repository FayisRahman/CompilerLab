#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reghandling.h"

#define MAX_LABEL 1000

int regCount = 0;
int labelCount = -1;
int stackTop = -1;
int stack[MAX_LABEL]={0};
int stack_address = 0;
int funct_assign_reg = -1;

int dot_node_rec_codegen(FILE* fptr, tnode* t,char* tup, Gsymbol* ptr1,Lsymbol* ptr2);
void alloc_node_codegen(FILE* fptr, tnode* t);
void free_node_codegen(FILE* fptr, tnode* t);
void dealloc_codegen(FILE* fptr, int regNo);
int alloc_codegen(FILE* fptr, int size);
void initialize_heap_codegen(FILE* fptr); 

void make_header(FILE *fptr) {
    fprintf(fptr, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

int getReg() {
    if (regCount < 20) {
        return regCount++;
    } else {
        printf("Error: Out of registers\n");
        exit(1);
    }
}

void freeReg() {
    if (regCount > 0) {
        regCount--;
    }
}

int createLabel(){
	return ++labelCount;
}

void write_codegen(struct tnode* t,FILE* fptr){
	
	int p = arithemetic_expression_codegen(t,fptr);
	write_code_from_reg(fptr,p);
	freeReg();
	return;
}


void codeGen(struct tnode *t,int end_label, int cont_label, FILE* fptr){
	int start_label;
	if(!t) return;

    switch(t->nodetype){
	
        case ASSIGNMENT:
            assignment_expression_codegen(t,fptr);
            break;
        case READNODE:
            read_code_to_addr(fptr,t->left);
            break;
        case WRITENODE:
            write_codegen(t->left,fptr);
			break;
        case IFNODE:
			if_node_codegen(fptr,t,end_label,cont_label);
            break;
        case WHILENODE:
			while_node_codegen(fptr,t);
            break;
		case DOWHILENODE:
			do_while_node_codegen(fptr,t);
			break;
		case BREAKNODE:
			fprintf(fptr, "JMP L%d\n", end_label);
			break;
		case CONTINUENODE:
            fprintf(fptr, "JMP L%d\n", cont_label);
            break;
		case RETURNNODE:
			return_node_codegen(fptr,t);
			break;
		case BREAKPOINTNODE:
			fprintf(fptr,"BRKP\n");
			break;
		case ALLOCNODE:
			alloc_node_codegen(fptr, t);
			break;
		case FREENODE:
			free_node_codegen(fptr, t);
			break;
		case INITIALIZENODE:
			initialize_heap_codegen(fptr);
			break;
        case CONNECTOR:
            codeGen(t->left,end_label,cont_label,fptr);
            codeGen(t->right,end_label,cont_label,fptr);
            break;
    }
}

void boolean_expression_codegen(tnode* t, FILE* fptr, int trueLabel, int falseLabel) {
    if (t->nodetype == OPERATOR) {

        // Short-circuit logical AND
        if (strcmp(t->varname, "&&") == 0) {
            int midLabel = createLabel();
            boolean_expression_codegen(t->left, fptr, midLabel, falseLabel);
            fprintf(fptr, "L%d:", midLabel); // newline added
            boolean_expression_codegen(t->right, fptr, trueLabel, falseLabel);
        }
        // Short-circuit logical OR
        else if (strcmp(t->varname, "||") == 0) {
            int midLabel = createLabel();
            boolean_expression_codegen(t->left, fptr, trueLabel, midLabel);
            fprintf(fptr, "L%d:", midLabel); // newline added
            boolean_expression_codegen(t->right, fptr, trueLabel, falseLabel);
        }
        else {
            printf("Error: %s is not a recognised logical operator\n", t->varname);
            exit(0);
        }
    }else{ // Comparison operator
        int lReg = arithemetic_expression_codegen(t->left, fptr);
        int rReg = arithemetic_expression_codegen(t->right, fptr);

        if (strcmp(t->varname, "<") == 0) fprintf(fptr, "LT R%d, R%d\n", lReg, rReg);
        else if (strcmp(t->varname, "<=") == 0) fprintf(fptr, "LE R%d, R%d\n", lReg, rReg);
        else if (strcmp(t->varname, ">") == 0) fprintf(fptr, "GT R%d, R%d\n", lReg, rReg);
        else if (strcmp(t->varname, ">=") == 0) fprintf(fptr, "GE R%d, R%d\n", lReg, rReg);
        else if (strcmp(t->varname, "==") == 0) fprintf(fptr, "EQ R%d, R%d\n", lReg, rReg);
        else if (strcmp(t->varname, "!=") == 0) fprintf(fptr, "NE R%d, R%d\n", lReg, rReg);
        else {
            printf("Error: %s is not a recognised comparison operator\n", t->varname);
            exit(0);
        }

        freeReg(); // free rReg

        fprintf(fptr, "JZ R%d, L%d\n", lReg, falseLabel);
        fprintf(fptr, "JMP L%d\n", trueLabel);

        freeReg(); // free lReg
    }
}

int arithemetic_expression_codegen(struct tnode* t,FILE* fptr){
	int p,q;
	if(!t)return -1;
	if(t->nodetype == SELFNODE){
		printf("clas name %s\n",t->centry->Name);
		p = getReg();
		get_binding(find_gsymbol("self"),find_lsymbol("self"),"self",fptr, p);
		fprintf(fptr, "MOV R%d, [R%d]\n",p ,p);
		return p;
	}if(t->nodetype == PTRNODE){
		return ptr_node_codegen(fptr,t->left,1);
	}else if(t->nodetype == ADDRNODE){
		return addr_node_codegen(fptr,t);
	}else if(t->nodetype == FUNCTIONNODE){
		return function_node_codegen(fptr,t);
	}else if(t->nodetype == DOTNODE){
		return dot_node_codegen(fptr,t,0);
	}else if(t->nodetype == ARROWNODE){
		return arrow_node_codegen(fptr,t,0);
	}else if(t->nodetype == NULLNODE){
		p = getReg();
		fprintf(fptr, "MOV R%d, -1\n",p);
		return p;
	}else if(!t->left && !t->right){
		p = getReg();
		if(t->varname != NULL && t->varname[0] != '"'){
			Gsymbol* ptr1 = find_gsymbol(t->varname);
			Lsymbol* ptr2 = find_lsymbol(t->varname);
			int varType = get_var_type(ptr1,ptr2,t->varname);
			if(varType == TYPE_VAR || varType == TYPE_PTR){
				int temp1 = get_binding(ptr1,ptr2,t->varname,fptr,p);
				fprintf(fptr, "MOV R%d, [R%d]\n", p, p); // here temp1 contains same value as p
			}else if(varType == TYPE_STRING){
				fprintf(fptr, "MOV R%d, %s\n", p, t->varname);
			}else if(varType == TYPE_ARR){
				int temp1 = get_binding(ptr1,ptr2,t->varname,fptr,p); // here temp1 contains same value as p
				DimNode* dimlist = get_dimlist(ptr1,ptr2,t->varname);
				q = array_position_codegen(fptr,t->dimlist,dimlist);
				fprintf(fptr, "ADD R%d, R%d\n", p, q);
				fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
				freeReg();
			}
		}else if(t->type == TYPE_INT){
			fprintf(fptr, "MOV R%d, %d\n", p, t->val);
		}else if(t->type == TYPE_STRING){
			fprintf(fptr, "MOV R%d, %s\n", p, t->varname);
		}
        return p;
	}
	p = arithemetic_expression_codegen(t->left,fptr);
	q = arithemetic_expression_codegen(t->right, fptr);
	if(t->varname){
		if(strcmp(t->varname,"+") == 0){
			fprintf(fptr, "ADD R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"-") == 0){
			fprintf(fptr, "SUB R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"*") == 0){
			fprintf(fptr, "MUL R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"/") == 0){
			fprintf(fptr, "DIV R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"%") == 0){
			fprintf(fptr, "MOD R%d, R%d\n", p, q);
		}
	}
	freeReg();
	return p;
}

void assignment_expression_codegen(struct tnode* t, FILE* fptr){

	int p,q,addr;
	
	//this is for arrays and if its simply a variable then the value will be zero. here the value will be the offset

	q = arithemetic_expression_codegen(t->right, fptr);

	if(t->left->nodetype == PTRNODE){
		p = ptr_node_codegen(fptr,t->left->left,0);
	}else if(t->left->nodetype == DOTNODE){
		p = dot_node_codegen(fptr,t->left,1);
	}else if(t->left->nodetype == ARROWNODE){
		tnode* tup = t->left->left;
		Gsymbol* ptr1 = find_gsymbol(tup->varname);
		Lsymbol* ptr2 = find_lsymbol(tup->varname);
		TypeTable* type = t->typeEntry;
		int offset = typetable_lookup_id_offset(type,(char*)t->left->right->varname);
		p = ptr_node_codegen(fptr,t->left->left,0);
		fprintf(fptr, "ADD R%d, %d\n", p, offset);
	}else{
		p = getReg();
		Gsymbol* ptr1 = find_gsymbol(t->left->varname);
		Lsymbol* ptr2 = find_lsymbol(t->left->varname);
		int varType = get_var_type(ptr1,ptr2,t->left->varname);
		if(varType == TYPE_ARR){
			DimNode* dimlist = get_dimlist(ptr1,ptr2,t->left->varname);
			int r = array_position_codegen(fptr,t->left->dimlist, dimlist);
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,p); //here this function will be generating the code
			fprintf(fptr, "ADD R%d, R%d\n", p, r);
			freeReg();
		}else if(varType == TYPE_VAR || varType == TYPE_PTR){
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,p);
			//the above function has already geerated the code
		}
	}
	
	fprintf(fptr, "MOV [R%d], R%d\n", p, q);
	

	freeReg();
	freeReg();
}

void read_code_to_addr(FILE* fptr, struct tnode* t){

	for(int i=0;i<regCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	
	int reg;
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Read\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -1\n", p);
	fprintf(fptr, "PUSH R%d\n",p);
	if(t->nodetype == PTRNODE){
		reg = ptr_node_codegen(fptr,t,0);
		fprintf(fptr, "PUSH R%d\n",reg);
		freeReg();
	}else if(t->nodetype == DOTNODE){
		reg = dot_node_codegen(fptr,t,1);
		fprintf(fptr, "PUSH R%d\n",reg);
		freeReg();
	}else if(t->nodetype == ARROWNODE){
		reg = arrow_node_codegen(fptr,t,1);
		fprintf(fptr, "PUSH R%d\n",reg);
		freeReg();
	}
	else {
		Gsymbol* ptr1 = find_gsymbol(t->varname);
		Lsymbol* ptr2 = find_lsymbol(t->varname);
		int varType = get_var_type(ptr1,ptr2,t->varname);
		if(varType == TYPE_ARR){
			reg = getReg();
			get_binding(ptr1,ptr2,t->varname,fptr,reg);
			DimNode* dimlist = get_dimlist(ptr1,ptr2,t->varname);
			int q = array_position_codegen(fptr,t->dimlist,dimlist);
			fprintf(fptr, "ADD R%d,R%d\n", reg, q);
			fprintf(fptr, "PUSH R%d\n",reg);
			freeReg();
			freeReg();
		}else if(varType == TYPE_VAR){
			get_binding(ptr1,ptr2,t->varname,fptr,p);
			fprintf(fptr, "PUSH R%d\n",p);
		}else{
			printf("Error: %s can access it in this manner\n",t->varname);
			exit(1);
		}
	}
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	freeReg();
	for(int i=regCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}

void write_code_from_reg(FILE* fptr, int regNo){
	for(int i=0;i<regCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Write\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -2\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",regNo);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	freeReg();
	for(int i=regCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}

void exit_footer(FILE* fptr){
	int p = getReg();
	fprintf(fptr,"L100:");
	fprintf(fptr, "MOV R%d, \"Exit\"\n", p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
	freeReg();
}

void if_node_codegen(FILE* fptr, tnode* t, int end_label, int cont_label) {
    int label_true = createLabel();
    int label_false = createLabel();
	int label_finish = createLabel();

    // Evaluate condition — jump to true/false labels
    boolean_expression_codegen(t->middle, fptr, label_true, label_false);

    // True branch
    fprintf(fptr, "L%d:", label_true);
    codeGen(t->left, end_label, cont_label, fptr);
    fprintf(fptr, "JMP L%d\n", label_finish);

    // False branch (optional)
    fprintf(fptr, "L%d:", label_false);
    if (t->right != NULL) {
        codeGen(t->right, end_label, cont_label, fptr);
    }

    // End label
    fprintf(fptr, "L%d:", label_finish);
}


void while_node_codegen(FILE* fptr, tnode* t) {
    int start_label = createLabel();
    int end_label = createLabel();
	int begin_label = createLabel();

    fprintf(fptr, "L%d:", start_label);

    // Evaluate condition — jump to end_label if false
    boolean_expression_codegen(t->middle, fptr, begin_label, end_label);

	fprintf(fptr, "L%d:", begin_label);

    // Body of while
    codeGen(t->left, end_label, start_label, fptr);

    // Jump back to start
    fprintf(fptr, "JMP L%d\n", start_label);

    // End label
    fprintf(fptr, "L%d:", end_label);
}

void do_while_node_codegen(FILE* fptr, tnode* t) {
    int start_label = createLabel();
    int cont_label = createLabel();
    int end_label = createLabel();

    fprintf(fptr, "L%d:", start_label);

    // Body of the loop
    codeGen(t->left, end_label, cont_label, fptr);

    // Condition check — jump back to start_label if true
    boolean_expression_codegen(t->middle, fptr, start_label, end_label);

    // End label
    fprintf(fptr, "L%d:", end_label);
}

void setup_pointers_codegen(FILE* fptr,Gsymbol* gptr, Lsymbol* lptr){
	
	int p = getReg();
	int q = getReg();

	if(lptr){
		Lsymbol* temp = lptr;
		int r = getReg();
		while(temp){
			if(temp->varType == TYPE_PTR){
				fprintf(fptr, "MOV R%d, BP\n", r);
				fprintf(fptr, "MOV R%d, %d\n",p, temp->binding);
				fprintf(fptr, "ADD R%d, R%d\n", p, r);
				fprintf(fptr, "MOV R%d, %d\n",q, temp->binding+1);
				fprintf(fptr, "ADD R%d, R%d\n", q, r);
				fprintf(fptr, "MOV [R%d], R%d\n",p, q);
			}
			temp = temp->next;
		}
		freeReg();
	}else if(gptr){
		Gsymbol* temp = gptr;
		while(temp){
			if(temp->varType == TYPE_PTR){
				fprintf(fptr, "MOV R%d, %d\n",p, temp->binding);
				fprintf(fptr, "MOV R%d, %d\n",q, temp->binding+1);
				fprintf(fptr, "MOV [R%d], R%d\n",p, q);
			}
		temp = temp->next;
		}
	}
	
	freeReg();
	freeReg();

}

int addr_node_codegen(FILE* fptr,tnode* t){ //used on RHS of an assignment operator only

	int regNo = getReg();

	Gsymbol* ptr1 = find_gsymbol(t->left->varname);
	Lsymbol* ptr2 = find_lsymbol(t->left->varname);
	int varType = get_var_type(ptr1,ptr2,t->left->varname);
	if(varType == TYPE_PTR){
		printf("Error: Cannot access the address of pointer variable: %s\n",t->left->varname);
		exit(1);
	}else if(varType == TYPE_ARR){
		printf("Error: Cannot access the address of array variable: %s\n",t->left->varname);
		exit(1);
	}
	get_binding(ptr1,ptr2,t->left->varname,fptr,regNo);
	return regNo;

}

int ptr_node_codegen(FILE* fptr,tnode* t,int side){
	//side 0 -> LHS and 1->RHS
	int regNo = getReg();
	tnode* temp = t;
	if(strcmp(temp->varname,"*") == 0)temp = temp->left;
	Gsymbol* ptr1= find_gsymbol(temp->varname);
	Lsymbol* ptr2 = find_lsymbol(temp->varname);
	int varType = get_var_type(ptr1,ptr2,temp->varname);
	if(varType != TYPE_PTR){
		printf("Error: variable %s not POINTER type\n",temp->varname);
		exit(1);
	}
	get_binding(ptr1,ptr2,t->varname,fptr,regNo);
	fprintf(fptr, "MOV R%d, [R%d]\n", regNo, regNo);
	if(side == 1)fprintf(fptr, "MOV R%d, [R%d]\n", regNo, regNo);
	return regNo;

}

void index_overflow_check_codegen(FILE* fptr,int regNo, int size){
	int p = getReg();
	fprintf(fptr, "MOV R%d, %d\n",p, size);
	fprintf(fptr, "LE R%d, R%d\n",p,regNo);
	fprintf(fptr, "JNZ R%d, L101\n",p);
	freeReg();
}

int array_position_codegen(FILE* fptr, DimNode* d, DimNode* main) {

	// 1. Evaluate the index expression
    int regIndex = arithemetic_expression_codegen(d->id,fptr);

    // 2. Bounds check
    index_overflow_check_codegen(fptr, regIndex, main->size);

    // 3. Compute stride (product of remaining dims)
    int stride = 1;
    DimNode* temp = main->next;
    while (temp) {
        stride *= temp->size;
        temp = temp->next;
    }

    // 4. Multiply index * stride
    if (stride > 1) {
        fprintf(fptr, "MUL R%d, %d\n", regIndex, stride);
    }

    // 5. Recurse into next dimension
    if (d->next) {
        int regNext = array_position_codegen(fptr, d->next, main->next);
        fprintf(fptr, "ADD R%d, R%d\n", regIndex, regNext);
        freeReg(); // free regNext
    }

    return regIndex; // final offset
}

void create_label_with_message(FILE* fptr,int label_no,char* msg){
	fprintf(fptr,"L%d:",label_no);
	int reg_no = getReg();
	fprintf(fptr, "MOV R%d, \"%s\"\n",reg_no,msg);
	write_code_from_reg(fptr,reg_no);
	fprintf(fptr, "JMP L100\n");
	freeReg();
}

int function_node_codegen(FILE* fptr,tnode* t){
	
	Gsymbol* temp = find_gsymbol(t->left->varname);
	tnode* args = t->right;
	int currCount = regCount;
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n", i);
		freeReg();
	}
	int regNo = getReg();
	int offset = -1;
	fprintf(fptr, "PUSH R0\n");
	while(args){
		offset++;
		int q = arithemetic_expression_codegen(args,fptr);
		fprintf(fptr, "PUSH R%d\n", q);
		freeReg();
		args = args->middle;
	}

	fprintf(fptr, "MOV R%d, \"RETVAL\"\n",regNo);
	fprintf(fptr, "PUSH R%d\n",regNo);
	
	int p = getReg();
	fprintf(fptr, "CALL F%d\n", temp->flabel);
	
	
	int size = 0;
	args = t->right;
	offset = -1;
	while(args){
		offset++;
		size++;
		args = args->middle;
	}
	// printf("typeSize = %d\n",temp->typeEntry->size);
	fprintf(fptr, "MOV R%d, SP\n", currCount);
	fprintf(fptr, "SUB SP, %d\n", size + 2);
	freeReg();
	freeReg();
	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n", i);
		getReg();
	}
	regNo = getReg();
	if(regNo != currCount)fprintf(fptr, "MOV R%d, R%d\n",  regNo, currCount);
	fprintf(fptr, "MOV R%d, [R%d]\n",  regNo, regNo);
	return regNo;

}

int method_node_codegen(FILE* fptr,tnode* t){
	
	Classtable* class = t->centry;
	Memberfunclist* funct = Class_Mlookup(class,t->left->varname);
	tnode* args = t->middle;
	int currCount = regCount;
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n", i);
		freeReg();
	}
	
	int regNo = getReg();
	int reg1 = getReg();
	fprintf(fptr,"MOV R%d, R%d\n", reg1, currCount);
	int offset = -1;
	
	while(args){
		offset++;
		int q = arithemetic_expression_codegen(args,fptr);
		fprintf(fptr, "PUSH R%d\n", q);
		freeReg();
		args = args->middle;
	}
	fprintf(fptr,"PUSH R%d\n", reg1);
	freeReg();

	fprintf(fptr, "MOV R%d, \"RETVAL\"\n",regNo);
	fprintf(fptr, "PUSH R%d\n",regNo);
	
	int p = getReg();
	fprintf(fptr, "CALL F%d\n", funct->Flabel);
	
	
	int size = 0;
	args = t->middle;
	offset = -1;
	while(args){
		offset++;
		size++;
		args = args->middle;
	}
	// printf("typeSize = %d\n",temp->typeEntry->size);
	fprintf(fptr, "MOV R%d, SP\n", currCount);
	fprintf(fptr, "SUB SP, %d\n", size + 2);
	freeReg();
	freeReg();
	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n", i);
		getReg();
	}
	regNo = getReg();
	if(regNo != currCount)fprintf(fptr, "MOV R%d, R%d\n",  regNo, currCount);
	fprintf(fptr, "MOV R%d, [R%d]\n",  regNo, regNo);
	
	return regNo;

}

void return_node_codegen(FILE* fptr, tnode* t){
	char* returningType = t->typeEntry->name;
	char* returnType = curr_function_type->name;
	if(strcmp(returningType,returnType) != 0){
		if(t->nodetype == DOTNODE || t->right->nodetype != ARROWNODE){
			int type = t->type;
			if(type == TYPE_INT){
				returningType = "int";
			}else if(type == TYPE_STRING){
				returningType ="str";
			}else{
				printf("Error: invalid return type : %d-%s\n",t->type, type_to_string(t->type));
				exit(1);
			}
		}
		printf("Error: Incorrect function return type, return type is %s and returning type is %s\n", returnType, returningType);
		exit(1);
	}
	int q = getReg();
	fprintf(fptr, "MOV R%d, BP\n", q);
	
	int p = arithemetic_expression_codegen(t->left,fptr);
	fprintf(fptr, "SUB R%d, 2\n", q);
	fprintf(fptr, "MOV [R%d], R%d\n", q, p);
	
	int curr_offset = get_ltable_length(curr_lsymbol_table);
	fprintf(fptr, "SUB SP, %d\n", curr_offset);
	fprintf(fptr, "POP BP\n");
	fprintf(fptr, "RET\n");
	freeReg();
	freeReg();
}

void driver_codegen(FILE* fptr){

	fprintf(fptr, "MOV SP, %d\n",curr_stack_address);
	fprintf(fptr, "MOV BP, SP\n");
    fprintf(fptr, "MOV R0, \"RETVAL\"\n");
	fprintf(fptr, "PUSH R0\n");
    fprintf(fptr, "CALL MAIN\n");
    
    fprintf(fptr, "POP R0\n");
    fprintf(fptr, "JMP L100\n");

}

int dot_node_codegen(FILE* fptr, tnode* t,int is_read){

	tnode* tup = t->left;
	while(tup->left)tup = tup->left;
	
	Gsymbol* ptr1 = find_gsymbol(tup->varname);
	Lsymbol* ptr2 = find_lsymbol(tup->varname);

	int regNo = dot_node_rec_codegen(fptr,t->left,tup->varname, ptr1,ptr2);

	if(t->right->nodetype == METHODNODE){
			freeReg();
			return method_node_codegen(fptr,t->right);
	}else{
		int offset = !(t->left->typeEntry) ? Class_Flookup(t->left->centry, t->right->varname)->Fieldindex : typetable_lookup_id_offset(t->left->typeEntry,(char*)t->right->varname);
		fprintf(fptr, "ADD R%d, %d\n", regNo, offset);
	}

	if(is_read == 0) fprintf(fptr, "MOV R%d, [R%d]\n", regNo, regNo);

	return regNo;
}

int dot_node_rec_codegen(FILE* fptr, tnode* t,char* tup, Gsymbol* ptr1,Lsymbol* ptr2){

	if(!t)return -1;

	int left = dot_node_rec_codegen(fptr,t->left,tup,ptr1,ptr2);
	if(strcmp(t->varname,tup) == 0 && t->nodetype == SELFNODE){
		int regNo = getReg();
		get_binding(find_gsymbol("self"),find_lsymbol("self"),"self",fptr, regNo);
		fprintf(fptr, "MOV R%d, [R%d]\n", regNo,regNo);
		return regNo;
	}else if(strcmp(t->varname,tup) == 0){
		int regNo = getReg();
		get_binding(ptr1,ptr2,t->varname,fptr,regNo);
		fprintf(fptr, "MOV R%d, [R%d]\n", regNo,regNo);
		return regNo;
	}else if(left != -1){
		{	
			printf("left->name %s and right->name %s \n",t->left->varname, t->right->varname);
			int offset = t->left->centry != NULL ? Class_Flookup(t->left->centry, t->right->varname)->Fieldindex : typetable_lookup_id_offset(t->left->typeEntry,(char*)t->right->varname);
			fprintf(fptr, "ADD R%d, %d\n", left, offset);
			fprintf(fptr, "MOV R%d, [R%d]\n", left,left);
		}
	}

	return left;

}	

int arrow_node_codegen(FILE* fptr,tnode* t,int is_read){

	tnode* tup = t->left;
	Gsymbol* ptr1 = find_gsymbol(tup->varname);
	Lsymbol* ptr2 = find_lsymbol(tup->varname);

	TypeTable* type = t->typeEntry;
	int offset = typetable_lookup_id_offset(type,(char*)t->right->varname);

	int regNo = ptr_node_codegen(fptr,t->left,0);

	fprintf(fptr, "ADD R%d, %d\n", regNo, offset);

	if(is_read == 0 )fprintf(fptr, "MOV R%d, [R%d]\n", regNo, regNo);

	return regNo;
}

void alloc_node_codegen(FILE* fptr, tnode* t){

	int regNo;
	// TypeTable* type = NULL;
	if(t->left->nodetype == DOTNODE){
		regNo = dot_node_codegen(fptr,t->left,1);
		// type = t->left->typeEntry;
	}else{
		regNo = getReg();
		Gsymbol* ptr1 = find_gsymbol(t->left->varname);
		Lsymbol* ptr2 = find_lsymbol(t->left->varname);
		int varType = get_var_type(ptr1,ptr2,t->left->varname);
		if(varType == TYPE_VAR || varType == TYPE_PTR){
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,regNo);
			//the above function has already geerated the code
		}
		// type = get_typetable(ptr1,ptr2,t->left->varname);
	}
	int p = alloc_codegen(fptr, 8);
	fprintf(fptr, "MOV [R%d], R%d\n", regNo,p);
	freeReg();
	freeReg();

}

void free_node_codegen(FILE* fptr, tnode* t){
	int regNo;
	// TypeTable* type = NULL;
	if(t->left->nodetype == DOTNODE){
		regNo = dot_node_codegen(fptr,t->left,1);
		// type = t->left->typeEntry;
	}else{
		regNo = getReg();
		Gsymbol* ptr1 = find_gsymbol(t->left->varname);
		Lsymbol* ptr2 = find_lsymbol(t->left->varname);
		int varType = get_var_type(ptr1,ptr2,t->left->varname);
		if(varType == TYPE_VAR || varType == TYPE_PTR){
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,regNo);
			//the above function has already geerated the code
		}
		// type = get_typetable(ptr1,ptr2,t->left->varname);
	}
	int p = getReg();
	fprintf(fptr, "MOV R%d, [R%d]\n", p,regNo);
	
	dealloc_codegen(fptr,p);
	fprintf(fptr, "BRKP\n");
	fprintf(fptr, "MOV [R%d], -1\n", regNo);
	freeReg();
	freeReg();
}

int alloc_codegen(FILE* fptr, int size){

	int currCount = regCount;
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
		freeReg();
	}

	fprintf(fptr, "MOV R0,\"Alloc\"\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "MOV R%d, %d\n",currCount+1, size);   
	fprintf(fptr, "PUSH R%d\n",currCount+1);
	fprintf(fptr, "PUSH R%d\n",currCount+1);
	fprintf(fptr, "PUSH R%d\n",currCount+1);
	fprintf(fptr, "PUSH R%d\n",currCount+1);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n", currCount);
	fprintf(fptr, "POP R%d\n",currCount+1);
	fprintf(fptr, "POP R%d\n",currCount+1);
	fprintf(fptr, "POP R%d\n",currCount+1);
	fprintf(fptr, "POP R%d\n",currCount+1);

	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
		getReg();
	}

	int p = getReg();
	if(p!=currCount){
		printf("hello\n");
		fprintf(fptr,"MOV R%d, R%d\n",p,currCount);
	}

	return p;

}

void dealloc_codegen(FILE* fptr, int regNo){

	int currCount = regCount;
	fprintf(fptr, "MOV R%d, R%d\n",currCount, regNo);
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
		freeReg();
	}

	fprintf(fptr, "MOV R0,\"Free\"\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R%d\n",currCount);
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");

	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
		getReg();
	}

}

void initialize_heap_codegen(FILE* fptr){
	int currCount = regCount;
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
		freeReg();
	}
	fprintf(fptr, "MOV R0,\"Heapset\"\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "PUSH R0\n");
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");
	fprintf(fptr, "POP R0\n");

	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
		getReg();
	}
}


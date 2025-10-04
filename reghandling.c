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
    }
    else { // Comparison operator
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
	
	if(t->nodetype == PTRNODE){
		p = getReg();
		return ptr_node_codegen(fptr,t,p,1);
	}else if(t->nodetype == ADDRNODE){
		p = getReg();
		return addr_node_codegen(fptr,t,p);
	}else if(t->nodetype == FUNCTIONNODE){
		p = getReg();
		return function_node_codegen(fptr,t,p);
	}else if(!t->left && !t->right){
		p = getReg();
		if(t->varname != NULL && t->type != TYPE_STRING){
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
	p = getReg();
	 //this is for arrays and if its simply a variable then the value will be zero. here the value will be the offset
	
	if(t->left->nodetype == PTRNODE){
		ptr_node_codegen(fptr,t->left,p,0);
	}else{
		Gsymbol* ptr1 = find_gsymbol(t->left->varname);
		Lsymbol* ptr2 = find_lsymbol(t->left->varname);
		int varType = get_var_type(ptr1,ptr2,t->left->varname);
		if(varType == TYPE_ARR){
			DimNode* dimlist = get_dimlist(ptr1,ptr2,t->left->varname);
			int r = array_position_codegen(fptr,t->left->dimlist, dimlist);
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,p); //here this function will be generatign teh code
			fprintf(fptr, "ADD R%d, R%d\n", p, r);
			freeReg();
		}else if(varType == TYPE_VAR || varType == TYPE_PTR){
			int temp1 = get_binding(ptr1,ptr2,t->left->varname,fptr,p);
			//the above function has already geerated the code
		}
	}
	
	q = arithemetic_expression_codegen(t->right, fptr);
	
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
		reg = getReg(); 
		reg = ptr_node_codegen(fptr,t,reg,0);
		fprintf(fptr, "PUSH R%d\n",reg);
		freeReg();
	}else{
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

int addr_node_codegen(FILE* fptr,tnode* t,int regNo){ //used on RHS of an assignment operator only

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

int ptr_node_codegen(FILE* fptr,tnode* t,int regNo,int side){
	//side 0 -> LHS and 1->RHS
	Gsymbol* ptr1= find_gsymbol(t->left->varname);
	Lsymbol* ptr2 = find_lsymbol(t->left->varname);
	int varType = get_var_type(ptr1,ptr2,t->left->varname);
	if(varType != TYPE_PTR){
		printf("Error: variable %s not POINTER type\n",t->left->varname);
		exit(1);
	}
	get_binding(ptr1,ptr2,t->left->varname,fptr,regNo);
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

int function_node_codegen(FILE* fptr,tnode* t,int regNo){
	Gsymbol* temp = find_gsymbol(t->left->varname);
	tnode* args = t->right;
	int currCount = regCount;
	for(int i=0;i<currCount;i++){
		fprintf(fptr, "PUSH R%d\n", i);
		freeReg();
	}
	while(args){
		int q = arithemetic_expression_codegen(args,fptr);
		fprintf(fptr, "PUSH R%d\n",q);
		freeReg();
		args = args->middle;
	}
	fprintf(fptr, "MOV R%d, \"RETVAL\"\n", regNo);
	fprintf(fptr, "PUSH R%d\n", regNo);
	fprintf(fptr, "CALL F%d\n", temp->flabel);
	fprintf(fptr, "POP R%d\n", regNo);
	fprintf(fptr, "MOV R%d, R%d\n", currCount, regNo);
	int p = getReg();
	args = t->right;
	while(args){
		fprintf(fptr, "POP R%d\n",p);
		args = args->middle;
	}
	freeReg();
	for(int i=currCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n", i);
		getReg();
	}

	fprintf(fptr, "MOV R%d, R%d\n",  regNo, currCount);

	return regNo;

}

void return_node_codegen(FILE* fptr, tnode* t){
	int p = arithemetic_expression_codegen(t->left,fptr);
	int q = getReg();
	fprintf(fptr, "MOV R%d, BP\n", q);
	fprintf(fptr, "SUB R%d, 2\n", q);
	fprintf(fptr, "MOV [R%d], R%d\n", q, p);
	int curr_offset = get_curr_offset(curr_lsymbol_table);
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





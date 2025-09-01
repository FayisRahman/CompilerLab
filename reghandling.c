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
	
        case EQUAL:
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
        case CONNECTOR:
            codeGen(t->left,end_label,cont_label,fptr);
            codeGen(t->right,end_label,cont_label,fptr);
            break;
    }
}

int boolean_expression_codegen(struct tnode* t,FILE* fptr){

	int lReg = arithemetic_expression_codegen(t->left,fptr);
	int rReg = arithemetic_expression_codegen(t->right,fptr);

	if (strcmp(t->varname, "<") == 0) {
		fprintf(fptr, "LT R%d, R%d\n", lReg, rReg);
	}
	else if (strcmp(t->varname, "<=") == 0) {
		fprintf(fptr, "LE R%d, R%d\n", lReg, rReg);
	}
	else if (strcmp(t->varname, ">") == 0) {
		fprintf(fptr, "GT R%d, R%d\n", lReg, rReg);
	}
	else if (strcmp(t->varname, ">=") == 0) {
		fprintf(fptr, "GE R%d, R%d\n", lReg, rReg);
	}
	else if (strcmp(t->varname, "!=") == 0) {
		fprintf(fptr, "NE R%d, R%d\n", lReg, rReg);
	}
	else if (strcmp(t->varname, "==") == 0) {
		fprintf(fptr, "EQ R%d, R%d\n", lReg, rReg);
	}
	freeReg();

	//lReg contains the value 0(if wrong) and 1(if correct)
	return lReg;	
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
	}else if(!t->left && !t->right){
		p = getReg();
		if(t->varname != NULL && t->type != TYPE_STRING){
			Gsymbol* ptr = find_symbol(t->varname);
			if(ptr->varType == TYPE_VAR || ptr->varType == TYPE_PTR){
				int addr = ptr->binding;
				fprintf(fptr, "MOV R%d, %d\n", p, addr);
				fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
			}else if(ptr->varType == TYPE_STRING){
				fprintf(fptr, "MOV R%d, %s\n", p, t->varname);
			}else if(ptr->varType == TYPE_ARR){
				int addr = ptr->binding;
				fprintf(fptr, "MOV R%d, %d\n", p, addr);
				q = array_position_codegen(fptr,t->dimlist,ptr->dimlist);
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
		Gsymbol* ptr = find_symbol(t->left->varname);
		addr = ptr->binding;
		if(ptr->varType == TYPE_ARR){
			int r = array_position_codegen(fptr,t->left->dimlist, ptr->dimlist);
			fprintf(fptr, "MOV R%d, %d\n", p,ptr->binding);
			fprintf(fptr, "ADD R%d, R%d\n", p, r);
			freeReg();
		}else if(ptr->varType == TYPE_VAR || ptr->varType == TYPE_PTR){
			fprintf(fptr, "MOV R%d, %d\n", p, ptr->binding);
		}
	}
	
	q = arithemetic_expression_codegen(t->right, fptr);
	
	fprintf(fptr, "MOV [R%d], R%d\n", p, q);
	freeReg();
	freeReg();
}

void read_code_to_addr(FILE* fptr, struct tnode* t){
	fprintf(fptr, "MOV SP, %d\n", stack_address);
	for(int i=0;i<regCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	
	int reg;
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Read\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -1\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	if(t->nodetype == PTRNODE){
		reg = getReg(); 
		reg = ptr_node_codegen(fptr,t,reg,0);
		fprintf(fptr, "PUSH R%d\n",reg);
		freeReg();
	}else{
		Gsymbol* ptr = find_symbol(t->varname);
		int addr = ptr->binding;
		if(ptr->varType == TYPE_ARR){
			reg = getReg();
			fprintf(fptr, "MOV R%d, %d\n", reg, ptr->binding);
			int q = array_position_codegen(fptr,t->dimlist,ptr->dimlist);
			fprintf(fptr, "ADD R%d,R%d\n", reg, q);
			fprintf(fptr, "PUSH R%d\n",reg);
			freeReg();
			freeReg();
		}else if(ptr->varType == TYPE_VAR){
			fprintf(fptr, "MOV R%d, %d\n",p, addr);
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

void write_code_from_addr(FILE* fptr, tnode* t){
	fprintf(fptr, "MOV SP, 4122\n");
	for(int i=0;i<regCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	Gsymbol* ptr = find_symbol(t->varname);
	int addr = ptr->binding;
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Write\"\n",p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "MOV R%d, -2\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "MOV R%d, %d\n",p, addr);
	fprintf(fptr, "MOV R%d, [R%d]\n", p , p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	freeReg();
	for(int i=regCount-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}

void write_code_from_reg(FILE* fptr, int regNo){
	fprintf(fptr, "MOV SP, %d\n",stack_address);
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

void if_node_codegen(FILE* fptr,tnode* t,int end_label,int cont_label){
	int label_1 = createLabel();
	int label_2 = createLabel();
	int reg = boolean_expression_codegen(t->middle,fptr);
	freeReg();
	fprintf(fptr, "JZ R%d, L%d\n", reg, label_1);
	codeGen(t->left,end_label,cont_label,fptr);
	fprintf(fptr, "JMP L%d\n", label_2);
	fprintf(fptr, "L%d:", label_1);
	codeGen(t->right,end_label,cont_label,fptr);
	fprintf(fptr, "L%d:", label_2);
}

void while_node_codegen(FILE* fptr,tnode* t){
	int start_label = createLabel();
	int cont_label = start_label;
	int end_label = createLabel();
	fprintf(fptr, "L%d:", start_label);
	int reg = boolean_expression_codegen(t->middle,fptr);
	fprintf(fptr, "JZ R%d, L%d\n", reg, end_label);
	freeReg();
	codeGen(t->left,end_label,cont_label,fptr);
	fprintf(fptr, "JMP L%d\n", start_label);
	fprintf(fptr, "L%d:", end_label);
}

void do_while_node_codegen(FILE* fptr,tnode* t){
	int start_label = createLabel();
	int cont_label = createLabel();
	int end_label = createLabel();

	fprintf(fptr, "L%d:", start_label);
	codeGen(t->left,end_label,cont_label,fptr);
	fprintf(fptr, "L%d:", cont_label);
	int reg = boolean_expression_codegen(t->middle,fptr);
	freeReg();
	fprintf(fptr, "JNZ R%d, L%d\n", reg, start_label);
	fprintf(fptr,"L%d:", end_label);
}

void setup_pointers_codegen(FILE* fptr){
	Gsymbol* temp = top;
	int p = getReg();
	int q = getReg();
	while(temp){
		if(temp->varType == TYPE_PTR){
			fprintf(fptr, "MOV R%d, %d\n",p, temp->binding);
			fprintf(fptr, "MOV R%d, %d\n",q, temp->binding+1);
			fprintf(fptr, "MOV [R%d], R%d\n",p, q);
		}
		temp = temp->next;
	}
	freeReg();
	freeReg();
}

int addr_node_codegen(FILE* fptr,tnode* t,int regNo){ //used on RHS of an assignment operator only

	Gsymbol* ptr = find_symbol(t->left->varname);
	if(ptr->varType == TYPE_PTR){
		printf("Error: Cannot access the address of pointer variable: %s\n",t->left->varname);
		exit(1);
	}else if(ptr->varType == TYPE_ARR){
		printf("Error: Cannot access the address of array variable: %s\n",t->left->varname);
		exit(1);
	}
	int addr = ptr->binding;
	fprintf(fptr, "MOV R%d, %d\n", regNo, addr);
	return regNo;

}

int ptr_node_codegen(FILE* fptr,tnode* t,int regNo,int side){
	//side 0 -> LHS and 1->RHS
	Gsymbol* ptr = find_symbol(t->left->varname);
	if(ptr->varType != TYPE_PTR){
		printf("Error: variable %s not POINTER type\n",t->left->varname);
		exit(1);
	}
	int addr = ptr->binding;
	fprintf(fptr, "MOV R%d, %d\n", regNo, addr);
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








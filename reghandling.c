#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reghandling.h"
#include "symbol_table.h"
#include "AST.h"

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
            read_code_to_addr(fptr,t->left->varname);
            break;
        case WRITENODE:
            write_codegen(t->left,fptr);
			break;
        case IFNODE: {
			int label_1 = createLabel();
			int label_2 = createLabel();
            int reg = boolean_expression_codegen(t->middle,fptr);
			fprintf(fptr, "JZ R%d, L%d\n", reg, label_1);
        	codeGen(t->left,end_label,cont_label,fptr);
			fprintf(fptr, "JMP L%d\n", label_2);
			fprintf(fptr, "L%d:", label_1);
            codeGen(t->right,end_label,cont_label,fptr);
			fprintf(fptr, "L%d:", label_2);
            break;
        }
        case WHILENODE:{
			start_label = createLabel();
			cont_label = start_label;
			end_label = createLabel();
			fprintf(fptr, "L%d:", start_label);
            int reg = boolean_expression_codegen(t->middle,fptr);
			fprintf(fptr, "JZ R%d, L%d\n", reg, end_label);
            codeGen(t->left,end_label,cont_label,fptr);
			fprintf(fptr, "JMP L%d\n", start_label);
			fprintf(fptr, "L%d:", end_label);
            break;
		}
		case DOWHILENODE:{
			start_label = createLabel();
			cont_label = createLabel();
			end_label = createLabel();

			fprintf(fptr, "L%d:", start_label);
			codeGen(t->left,end_label,cont_label,fptr);
			fprintf(fptr, "L%d:", cont_label);
			int reg = boolean_expression_codegen(t->middle,fptr);
			freeReg();
			fprintf(fptr, "JNZ R%d, L%d\n", reg, start_label);
			fprintf(fptr,"L%d:", end_label);
			break;
		}
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
	p = getReg();
	if(!t)return -1;
	if(!t->left && !t->right){
		if(t->varname != NULL){
			if(t->type == TYPE_VAR){
				Gsymbol* ptr = find_symbol(t->varname);
				int addr = ptr->binding;
				fprintf(fptr, "MOV R%d, %d\n", p, addr);
				fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
			}else if(t->type == TYPE_STRING){
				fprintf(fptr, "MOV R%d, %s\n", p, t->varname);
			}
		}else{
			fprintf(fptr, "MOV R%d, %d\n", p, t->val);
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
	}
	freeReg();
	return p;
}

void assignment_expression_codegen(struct tnode* t, FILE* fptr){

	int p,q;
	p = getReg();
	Gsymbol* ptr = find_symbol(t->left->varname);
	int addr = ptr->binding;
	fprintf(fptr, "MOV R%d, %d\n", p, addr);
	q = arithemetic_expression_codegen(t->right, fptr);
	fprintf(fptr, "MOV [R%d], R%d\n", p, q);
	freeReg();
	freeReg();
}

void read_code_to_addr(FILE* fptr, char* var){
	fprintf(fptr, "MOV SP, %d\n", stack_address);
	for(int i=0;i<regCount;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	Gsymbol* ptr = find_symbol(var);
	int addr = ptr->binding;
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Read\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -1\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, %d\n",p, addr);
	fprintf(fptr, "PUSH R%d\n",p);
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
	fprintf(fptr, "MOV R%d, \"Exit\"\n", p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
}






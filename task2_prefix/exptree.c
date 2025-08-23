#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

int count = 0;
FILE* fptr;
int ans = 0;

/* Make a leaf tnode and set the value of val field */
struct tnode* makeLeafNode(int n) {
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = n;
    temp->op = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Make a tnode with operator, left and right branches set */
struct tnode* makeOperatorNode(char *op, struct tnode *l, struct tnode *r) {
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = 0;
    temp->op = strdup(op);
    temp->left = l;
    temp->right = r;
    return temp;
}

FILE* openFile(char* fileName){
    fptr = fopen(fileName, "w");
    if(fptr == NULL){
        printf("Error! Could not open file\n");
        exit(1);
    }
    return fptr;
}

void makeHeader(FILE *fptr) {
    fprintf(fptr, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

int getReg() {
    if (count < 20) {
        return count++;
    } else {
        printf("Error: Out of registers\n");
        exit(1);
    }
}

void freeReg() {
    if (count > 0) {
        count--;
    }
}

int codeGen(struct tnode *t,FILE* fptr){
    int p,q;
    if(!t->left && !t->right){
        p = getReg();
        fprintf(fptr, "MOV R%d, %d\n", p, t->val);
        return p;
    }
    p = codeGen(t->left,fptr);
    q = codeGen(t->right,fptr);
    if(strcmp(t->op,"+") == 0){
        fprintf(fptr, "ADD R%d, R%d\n", p, q);
    }else if(strcmp(t->op,"-") == 0){
        fprintf(fptr, "SUB R%d, R%d\n", p, q);
    }else if(strcmp(t->op,"*") == 0){
        fprintf(fptr, "MUL R%d, R%d\n", p, q);
    }else if(strcmp(t->op,"/") == 0){
        fprintf(fptr, "DIV R%d, R%d\n", p, q);
    }
    freeReg();
    return p;
}

void writeFooter(FILE *fptr){
	int d =getReg();
	fprintf(fptr, "MOV SP, 4095\n");
	fprintf(fptr, "MOV R%d, \"Write\"\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "MOV R%d, -2\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d-1);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "MOV R%d, \"Exit\"\n", d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");

}

void writeFooterFromAddr(FILE *fptr,int addr){
	int d = getReg();
    int q = getReg();
	fprintf(fptr, "MOV SP, %d\n",addr);
	fprintf(fptr, "MOV R%d, \"Write\"\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "MOV R%d, -2\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
    fprintf(fptr, "MOV R%d, %d\n",q, addr);
    fprintf(fptr, "MOV R%d, [R%d]\n",d , q);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "MOV R%d, \"Exit\"\n", d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");

}

void storeResult(FILE* fptr,int reg,int storeAddr){
    int d = getReg();
    fprintf(fptr, "MOV R%d, %d\n", d, storeAddr);
    fprintf(fptr, "MOV [R%d], R%d\n", d, reg);
}




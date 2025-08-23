#ifndef EXPTREE_H
#define EXPTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode {
    int val;              
    char *op;             
    struct tnode *left;
    struct tnode *right;
} tnode;


struct tnode* makeLeafNode(int n);

struct tnode* makeOperatorNode(char *op, struct tnode *l, struct tnode *r);

void makeHeader(FILE *fptr);
int getReg();
void freeReg();
int codeGen(struct tnode *t, FILE *fptr);
FILE* openFile(char* fileName);
void writeFooter(FILE* fptr);
void storeResult(FILE*fptr,int regNo, int storeAddr);
void writeFooterFromAddr(FILE* fptr, int addr);




#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

int count = 0;
File* fptr;

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

void openFile(char* fileName){
    fptr = fopen(fileName.c_str(), "w");
    if(fptr == NULL){
        printf("Error! Could not open file\n");
        exit(1);
    }
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

int codeGen(struct tnode *t,File* fptr){
    int p,q;
}


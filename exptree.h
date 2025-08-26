#ifndef EXPTREE_H
#define EXPTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
}tnode;

enum NodeType {
    READNODE,
    WRITENODE,
    CONNECTOR,
    OPERATOR,
    EQUAL,
    LEAFNODE
    
};

enum DataType {
    NONE,
    INT,
    STRING,
    BOOL,
};


struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char *op, struct tnode *l, struct tnode *r);
struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *r);
void makeHeader(FILE *fptr);
int getReg();
void freeReg();
int codeGen(struct tnode *t, FILE *fptr,enum NodeType prevNodeType);
FILE* openFile(char* fileName);
void writeFooter(FILE* fptr);
void storeResult(FILE*fptr,int regNo, int storeAddr);
void writeFooterFromAddr(FILE* fptr, int addr);
void readCodeToAddr(FILE* fptr, char* var);
void writeCodeFromAddr(FILE* fptr, char* var);
void writeCodeFromReg(FILE* fptr, int regNo);
void exitFooter(FILE* fptr);
int codeIntrepret(struct tnode *t,enum NodeType prevNodeType);




#endif

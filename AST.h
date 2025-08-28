#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right,*middle;  // left and right branches
} tnode;

enum NodeType {
    READNODE,
    WRITENODE,
    CONNECTOR,
    OPERATOR,
    EQUAL,
    IFNODE,
    EXPRESSION,
    WHILENODE,
    DOWHILENODE,
    BREAKNODE,
    CONTINUENODE,
    LEAFNODE,
    
};

enum DataType {
    NONE,
    INT,
    STRING,
    BOOL,
};


struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *m,struct tnode *r);

struct tnode* createWhileNode(struct tnode* l,struct tnode* m);

struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m);

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r);

struct tnode* createJumpNode(int nodeType);

#endif
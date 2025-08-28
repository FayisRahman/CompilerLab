#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;     // pointer to GST entry for global variables and functions
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
    VARNODE,
    LEAFNODE,
    
};

enum DataType {
    TYPE_NULL,
    TYPE_INT,
    TYPE_STRING,
    TYPE_BOOL,
};


struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *m,struct tnode *r);

struct tnode* createWhileNode(struct tnode* l,struct tnode* m);

//The repeat-until semantics uses the same logic as do-while so we club them both as a single entity in the backend 
struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m);

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r);

struct tnode* createJumpNode(int nodeType);

struct tnode* createVarNode(int type, char* c, struct tnode *l,struct tnode *r);



#endif
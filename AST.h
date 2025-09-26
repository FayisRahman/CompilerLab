#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_symbol_table.h"

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;    // pointer to GST entry for global variables and functions
    struct tnode *left,*right,*middle;  // left and right branches
    struct DimNode* dimlist;
} tnode;

typedef enum NodeType {
    READNODE,           // 0
    WRITENODE,          // 1
    CONNECTOR,          // 2
    OPERATOR,           // 3
    EQUAL,              // 4
    IFNODE,             // 5
    EXPRESSION,         // 6
    WHILENODE,          // 7
    DOWHILENODE,        // 8
    BREAKNODE,          // 9
    CONTINUENODE,       // 10
    VARNODE,            // 11
    LEAFNODE,           // 12
    ADDRNODE,           // 13
    PTRNODE,            // 14   
} NodeType;

typedef enum DataType {
    TYPE_NULL,      // 0
    TYPE_INT,       // 1
    TYPE_STRING,    // 2
    TYPE_BOOL,      // 3
    TYPE_VAR,       // 4 
    TYPE_ARR,       // 5
    TYPE_PTR,       // 6
    TYPE_ADDR,      // 7
    TYPE_FUNCT,     // 8
} DataType;


struct tnode* createTree(int val, int type, char* c, int nodeType, struct Gsymbol* Gentry, struct tnode *l, struct tnode *m,struct tnode *r);

struct tnode* createWhileNode(struct tnode* l,struct tnode* m);

//The repeat-until semantics uses the same logic as do-while so we club them both as a single entity in the backend 
struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m);

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r);

struct tnode* createJumpNode(int nodeType);

struct tnode* createVarNode(int type, char* c, struct tnode *l,struct tnode *r);

//to check that during operations and assignments the data types are correct
void check_data_types(int t,int q,int type);
#endif
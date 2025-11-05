#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_symbol_table.h"
#include "dim_node.h"
#include "param_list.h"
#include "type_table.h"
#include "exptree.h"


typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;    // pointer to GST entry for global variables and functions
    struct tnode *left,*right,*middle;  // left and right branches
    struct DimNode* dimlist;
    struct ParamList* plist; 
    struct TypeTable* typeEntry;
} tnode;




struct tnode* createTree(int val, int type, char* c, int nodeType, struct Gsymbol* Gentry, struct tnode *l, struct tnode *m,struct tnode *r);

struct tnode* createWhileNode(struct tnode* l,struct tnode* m);

//The repeat-until semantics uses the same logic as do-while so we club them both as a single entity in the backend 
struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m);

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r);

struct tnode* createJumpNode(int nodeType);

struct tnode* createVarNode(int type, char* c, struct tnode *l,struct tnode *r);

void ast_destroy(struct tnode* head);
//to check that during operations and assignments the data types are correct
void check_data_types(int t,int q,int type,int line);

void print_ast_node(struct tnode* head);

const char* nodetype_to_string(int nodetype);
const char* type_to_string(int type);

void print_gsymbol(struct Gsymbol* g);
void print_paramlist(struct ParamList* plist);
void print_dimlist(struct DimNode* dimlist);



#endif
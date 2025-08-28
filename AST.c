#include <stdio.h>
#include <stdlib.h>

#include "AST.h"

struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *m,struct tnode *r){
	if(nodeType == OPERATOR || nodeType == EQUAL){
		if(l->type != INT || r->type != INT){
			yyerror("type mismatch");
        }
	}
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    if(c != NULL) temp->varname = strdup(c);
    else temp->varname = NULL;
    temp->nodetype = nodeType;
    temp->left = l;
    temp->middle = m;
    temp->right = r;
    return temp;
}

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r){
	if(m->type == BOOL){
		return createTree(0, NONE, NULL, IFNODE, l, m, r);
    }else{
		yyerror("Type mismatch");
		exit(1);
	}
}

struct tnode* createWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == BOOL){
		return createTree(0, NONE, NULL, WHILENODE, l, m,NULL);
    }else{
		yyerror("Type mismatch");
		exit(1);
	}
}

struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == BOOL){
		return createTree(0, NONE, NULL, DOWHILENODE, l, m,NULL);
    }else{
		yyerror("Type mismatch");
		exit(1);
	}
}

struct tnode* createJumpNode(int nodeType){
    return createTree(0, NONE, NULL, nodeType, NULL, NULL,NULL);
}
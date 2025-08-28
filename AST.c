#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AST.h"

struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *m,struct tnode *r){
	if(nodeType == OPERATOR || nodeType == EQUAL){
        if(l->type == TYPE_INT || l->type == TYPE_STRING){
            if(l->type != r->type){
                printf("type mismatch");
                exit(1);
            }
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
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, IFNODE, l, m, r);
    }else{
		printf("Type mismatch");
		exit(1);
	}
}

struct tnode* createWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, WHILENODE, l, m,NULL);
    }else{
		printf("Type mismatch");
		exit(1);
	}
}

struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, DOWHILENODE, l, m,NULL);
    }else{
		printf("Type mismatch");
		exit(1);
	}
}

struct tnode* createJumpNode(int nodeType){
    return createTree(0, TYPE_NULL, NULL, nodeType, NULL, NULL,NULL);
}

struct tnode* createVarNode(int type, char* c, struct tnode *l,struct tnode *r){
    return createTree(0, type, c, VARNODE, l, NULL,r);
}
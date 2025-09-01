#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AST.h"

struct tnode* createTree(int val, int type, char* c, int nodeType,struct Gsymbol* Gentry, struct tnode *l, struct tnode *m,struct tnode *r){
	if(nodeType == OPERATOR || nodeType == EQUAL){
        if(get_type(l->Gentry) == TYPE_INT || get_type(l->Gentry) == TYPE_STRING){
            if(get_type(l->Gentry) != get_type(l->Gentry)){
                printf("Error: Type Mismatch %s->%d and %s->%d\n",l->varname,get_type(l->Gentry),r->varname,get_type(l->Gentry));
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
    temp->Gentry = NULL;
    temp->left = l;
    temp->middle = m;
    temp->right = r;
    return temp;
}

struct tnode* createIfNode(struct tnode* l,struct tnode* m, struct tnode* r){
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, IFNODE,NULL, l, m, r);
    }else{
		printf("Error: Type mismatch\n");
		exit(1);
	}
}

struct tnode* createWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, WHILENODE,NULL, l, m,NULL);
    }else{
		  printf("Error: Type mismatch\n");
		  exit(1);
	}
}

struct tnode* createDoWhileNode(struct tnode* l,struct tnode* m){
	if(m->type == TYPE_BOOL){
		return createTree(0, TYPE_NULL, NULL, DOWHILENODE,NULL, l, m,NULL);
    }else{
		  printf("Error: Type mismatch\n");
		  exit(1);
	}
}

struct tnode* createJumpNode(int nodeType){
    return createTree(0, TYPE_NULL, NULL, nodeType,NULL, NULL, NULL,NULL);
}

struct tnode* createVarNode(int type, char* c, struct tnode *l,struct tnode *r){
    return createTree(0, type, c, VARNODE,NULL, l, NULL,r);
}

void check_data_types(int t,int q,int type){
    if(t!=q || t != type){
        printf("Error: assignment with different data types\n");
        exit(1);
    }
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "evaluator.h"
#include "AST.h"

int memory[26] = {0};

int arithemetic_expression_eval(struct tnode* t){
	int p,q;
	if(!t->left && !t->right){
		if(t->varname != NULL){
			return memory[t->varname[0]-'a'];
		}else{
			return t->val;
		}
	}
	p = arithemetic_expression_eval(t->left);
	q = arithemetic_expression_eval(t->right);
	if(strcmp(t->varname,"+") == 0){
		return p + q;
	}else if(strcmp(t->varname,"-") == 0){
		return p - q;
	}else if(strcmp(t->varname,"*") == 0){
		return p * q;
	}else if(strcmp(t->varname,"/") == 0){
		return p / q;
	}
	return t->val;
}

void assignment_expression_eval(struct tnode* t){

	int q = arithemetic_expression_eval(t->right);
    memory[t->left->varname[0]-'a'] = q;
	
}

void codeIntrepret(struct tnode *t){
	
	if(!t) return;

    switch(t->nodetype){
	
        case ASSIGNMENT:
            assignment_expression_eval(t);
            break;
        case READNODE:
            scanf("%d", memory + t->left->varname[0]-'a');
            break;
        case WRITENODE:
            if(t->left->nodetype == OPERATOR){
                printf("%d\n", arithemetic_expression_eval(t->left));
            }else if(t->left->varname != NULL){
                printf("%d\n", memory[t->left->varname[0]-'a']);
            }else{
                printf("%d\n", t->left->val);
            }
            break;
        case IFNODE: {
            bool res;
            res = boolean_expression_eval(t->middle);
            if(res){
                codeIntrepret(t->left);
            }else{
                codeIntrepret(t->right);
            }
            break;
        }
        case WHILENODE:
            while(boolean_expression_eval(t->middle)){
                codeIntrepret(t->left);
            }
            break;
        case DOWHILENODE:
            do{
                codeIntrepret(t->left);
            }while(boolean_expression_eval(t->middle));
            break;
        case CONNECTOR:
            codeIntrepret(t->left);
            codeIntrepret(t->right);
            break;
    }
}

bool boolean_expression_eval(struct tnode* t){
    if(!t)return 0;
    int p = arithemetic_expression_eval(t->left);
    int q = arithemetic_expression_eval(t->right);
    

    if(strcmp(t->varname,">") == 0) return p > q;
    else if(strcmp(t->varname,">=") == 0) return p >= q;
    else if(strcmp(t->varname,"<") == 0) return p < q;
    else if(strcmp(t->varname,"<=") == 0) return p <= q;
    else if(strcmp(t->varname,"!=") == 0) return p != q;
    else if(strcmp(t->varname,"==") == 0) return p == q;
}
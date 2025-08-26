#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.h"

int count = 0;
FILE* fptr;
int ans = 0;
int memory[27] = {0};

struct tnode* createTree(int val, int type, char* c, int nodeType, struct tnode *l, struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    if(c != NULL) temp->varname = strdup(c);
    else temp->varname = NULL;
    temp->nodetype = nodeType;
    temp->left = l;
    temp->right = r;
    return temp;
}

FILE* openFile(char* fileName){
    fptr = fopen(fileName, "w");
    if(fptr == NULL){
        printf("Error! Could not open file\n");
        exit(1);
    }
    return fptr;
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

int codeGen(struct tnode *t,FILE* fptr,enum NodeType prevNodeType){
    int p,q;
	if(!t)return -1;
	if(prevNodeType == READNODE) return -1;
    if(!t->left && !t->right){
		if(prevNodeType == WRITENODE && t->varname != NULL)return -1;
        p = getReg();
		if(t->varname != NULL && prevNodeType == EQUAL)return -1;
		if(t->varname != NULL){
			int addr = 4096 + t->varname[0] - 'a';
			fprintf(fptr, "MOV R%d, %d\n", p, addr);
			fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
		}else{
			fprintf(fptr, "MOV R%d, %d\n", p, t->val);
		}
        return p;
    }
	
    if(t->nodetype != EQUAL) p = codeGen(t->left,fptr,t->nodetype);
    q = codeGen(t->right,fptr,t->nodetype);
	if(t->nodetype == OPERATOR){
		if(strcmp(t->varname,"+") == 0){
			fprintf(fptr, "ADD R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"-") == 0){
			fprintf(fptr, "SUB R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"*") == 0){
			fprintf(fptr, "MUL R%d, R%d\n", p, q);
		}else if(strcmp(t->varname,"/") == 0){
			fprintf(fptr, "DIV R%d, R%d\n", p, q);
		}
	}else if(t->nodetype == READNODE){
		readCodeToAddr(fptr, t->left->varname);
	}else if(t->nodetype == WRITENODE){
		if(t->left->nodetype == OPERATOR){
			writeCodeFromReg(fptr, p);
		}else{
			writeCodeFromAddr(fptr, t->left->varname);
		}
	}else if(t->nodetype == EQUAL){
		int r = getReg();
		int addr = 4096 + t->left->varname[0] - 'a';
		if(t->right->nodetype == OPERATOR){
			fprintf(fptr, "MOV R%d, %d\n", r, addr);
			fprintf(fptr, "MOV [R%d], R%d\n", r, q);
		}else if(t->right->varname != NULL){
			int k = getReg();
			int rightAddr = 4096 + t->left->varname[0] - 'a';
			fprintf(fptr, "MOV R%d, %d\n", k, rightAddr);
			fprintf(fptr, "MOV R%d, [R%d]\n", k, k);
			fprintf(fptr, "MOV R%d, %d\n", r, addr);
			fprintf(fptr, "MOV [R%d], R%d\n", r, k);
			freeReg();
		}else if(t->right->nodetype == LEAFNODE){
			fprintf(fptr, "MOV R%d, %d\n", r, addr);
			fprintf(fptr, "MOV [R%d], R%d\n", r, q);
		}
		freeReg();
	}
    freeReg();
    return p;
}

void readCodeToAddr(FILE* fptr, char* var){
	fprintf(fptr, "MOV SP, 4122\n");
	for(int i=0;i<count;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	int addr = 4096 + var[0] - 'a';
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Read\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -1\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, %d\n",p, addr);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	freeReg();
	for(int i=count-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}
void writeCodeFromAddr(FILE* fptr, char* var){
	fprintf(fptr, "MOV SP, 4122\n");
	for(int i=0;i<count;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	int addr = 4096 + var[0] - 'a';
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Write\"\n",p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "MOV R%d, -2\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "MOV R%d, %d\n",p, addr);
	fprintf(fptr, "MOV R%d, [R%d]\n", p , p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "PUSH R%d\n", p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	fprintf(fptr, "POP R%d\n", p);
	freeReg();
	for(int i=count-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}
void writeCodeFromReg(FILE* fptr, int regNo){
	fprintf(fptr, "MOV SP, 4122\n");
	for(int i=0;i<count;i++){
		fprintf(fptr, "PUSH R%d\n",i);
	}
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Write\"\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "MOV R%d, -2\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",regNo);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	fprintf(fptr, "POP R%d\n",p);
	freeReg();
	for(int i=count-1;i>=0;i--){
		fprintf(fptr, "POP R%d\n",i);
	}	
}

void writeFooterFromAddr(FILE *fptr,int addr){
	int d = getReg();
    int q = getReg();
	fprintf(fptr, "MOV SP, %d\n",addr);
	fprintf(fptr, "MOV R%d, \"Write\"\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "MOV R%d, -2\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
    fprintf(fptr, "MOV R%d, %d\n",q, addr);
    fprintf(fptr, "MOV R%d, [R%d]\n",d , q);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "MOV R%d, \"Exit\"\n", d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "PUSH R%d\n",d);
	fprintf(fptr, "CALL 0\n");

}

void storeResult(FILE* fptr,int reg,int storeAddr){
    int d = getReg();
    fprintf(fptr, "MOV R%d, %d\n", d, storeAddr);
    fprintf(fptr, "MOV [R%d], R%d\n", d, reg);
}

void exitFooter(FILE* fptr){
	int p = getReg();
	fprintf(fptr, "MOV R%d, \"Exit\"\n", p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "PUSH R%d\n",p);
	fprintf(fptr, "CALL 0\n");
}

int codeIntrepret(struct tnode *t,enum NodeType prevNodeType){
	int p,q;
	if(!t)return -1;
	if(prevNodeType == READNODE) return -1;
    if(!t->left && !t->right){
		if(prevNodeType == WRITENODE && t->varname != NULL)return -1;
		if(t->varname != NULL && prevNodeType == EQUAL)return -1;
		if(t->varname != NULL){
			return memory[t->varname[0]-'a'];
		}else{
			return t->val;
		}
        return p;
    }
	
    if(t->nodetype != EQUAL) p = codeIntrepret(t->left,t->nodetype);
    q = codeIntrepret(t->right,t->nodetype);
	if(t->nodetype == OPERATOR){
		if(strcmp(t->varname,"+") == 0){
			return p + q;
		}else if(strcmp(t->varname,"-") == 0){
			return p - q;
		}else if(strcmp(t->varname,"*") == 0){
			return p * q;
		}else if(strcmp(t->varname,"/") == 0){
			return p / q;
		}
	}else if(t->nodetype == READNODE){
		scanf("%d", &memory[t->left->varname[0]-'a']);
	}else if(t->nodetype == WRITENODE){
		if(t->left->nodetype == OPERATOR){
			printf("%d\n", p);
		}else{
			printf("%d\n", memory[t->left->varname[0]-'a']);
		}
	}else if(t->nodetype == EQUAL){
		if(t->right->nodetype == OPERATOR){
			memory[t->left->varname[0]-'a'] = q;
		}else if(t->right->varname != NULL){
			memory[t->left->varname[0]-'a'] = memory[t->right->varname[0]-'a'];
		}else if(t->right->nodetype == LEAFNODE){
			memory[t->left->varname[0]-'a'] = q;
		}
	}
    return t->val;
}




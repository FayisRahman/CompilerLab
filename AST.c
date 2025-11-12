#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AST.h"


struct tnode* createTree(int val, int type, char* c, int nodeType,struct Gsymbol* Gentry, struct tnode *l, struct tnode *m,struct tnode *r){
	if(nodeType == OPERATOR || nodeType == ASSIGNMENT){
        if(get_gtype(l->Gentry) == TYPE_INT || get_gtype(l->Gentry) == TYPE_STRING){
            if(get_gtype(l->Gentry) != get_gtype(l->Gentry)){
                printf("Error: Type Mismatch %s->%d and %s->%d\n",l->varname,get_gtype(l->Gentry),r->varname,get_gtype(l->Gentry));
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
    temp->typeEntry = NULL;
    temp->centry = NULL;
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

void check_data_types(int t,int q,int type,int line){
    if(t!=q || t != type){
        printf("Error: Incorrect data type %s but requires %s %d\n",type_to_string(t), type_to_string(q),line);
        exit(1);
    }
}

void ast_destroy(struct tnode* head){
    if(!head)return;
    ast_destroy(head->left);
    head->left = NULL;
    ast_destroy(head->middle);
    head->middle = NULL;
    ast_destroy(head->right);
    head->right = NULL;
    // if(head->dimlist){
    //     dimnode_destroy(head->dimlist);
    //     head->dimlist = NULL;
    // }
    if(head->plist){
        paramlist_destroy(head->plist);
        head->plist = NULL;
    }
    free(head->varname);
    head->varname = NULL;
    free(head);
    head = NULL;

}

void print_ast_node(tnode* node) {
    if (!node) {
        printf("NULL node\n");
        return;
    }

    printf("======= AST NODE =======\n");
    printf("Address     : %p\n", (void*)node);
    printf("NodeType    : %s (%d)\n", nodetype_to_string(node->nodetype), node->nodetype);
    printf("VarName     : %s\n", node->varname ? node->varname : "(none)");
    printf("Type        : %s (%d)\n", type_to_string(node->type), node->type);

    if (node->type == TYPE_INT)
        printf("Value       : %d\n", node->val);

    if (node->dimlist) {
        printf("DimList     : ");
        print_dimlist(node->dimlist);
        printf("\n");
    }

    if (node->plist) {
        printf("ParamList   : ");
        print_paramlist(node->plist);
        printf("\n");
    }

    if (node->typeEntry)
        printf("TypeEntry   : %s\n", node->typeEntry->name);
    
    if (node->Gentry) {
        printf("GSymbol     : ");
        print_gsymbol(node->Gentry);
        printf("\n");
    }

    printf("Left ptr    : %p\n", (void*)node->left);
    printf("Middle ptr  : %p\n", (void*)node->middle);
    printf("Right ptr   : %p\n", (void*)node->right);

    printf("========================\n\n");
}


const char* nodetype_to_string(int nodetype) {
    switch (nodetype) {
        case READNODE: return "READ";
        case WRITENODE: return "WRITE";
        case CONNECTOR: return "CONNECTOR";
        case OPERATOR: return "OPERATOR";
        case ASSIGNMENT: return "ASSIGNMENT";
        case IFNODE: return "IF";
        case EXPRESSION: return "EXPRESSION";
        case WHILENODE: return "WHILE";
        case DOWHILENODE: return "DO-WHILE";
        case BREAKNODE: return "BREAK";
        case CONTINUENODE: return "CONTINUE";
        case VARNODE: return "VAR";
        case LEAFNODE: return "LEAF";
        case ADDRNODE: return "ADDR";
        case PTRNODE: return "PTR";
        case FUNCTIONNODE: return "FUNCTION";
        case RETURNNODE: return "RETURN";
        case BREAKPOINTNODE: return "BREAKPOINT";
        case DOTNODE: return "DOT";
        case ARROWNODE: return "ARROW";
        case ALLOCNODE: return "ALLOC";
        case FREENODE: return "FREE";
        case NULLNODE: return "NULL";
        case INITIALIZENODE: return "INIT";
        case METHODNODE: return "METHOD";
        case SELFNODE: return "SELF";
        default: return "UNKNOWN_NODE";
    }
}

const char* type_to_string(int type) {
    switch (type) {
        case TYPE_NULL: return "NULL";
        case TYPE_INT: return "INT";
        case TYPE_STRING: return "STRING";
        case TYPE_BOOL: return "BOOL";
        case TYPE_VAR: return "VAR";
        case TYPE_ARR: return "ARRAY";
        case TYPE_PTR: return "PTR";
        case TYPE_ADDR: return "ADDR";
        case TYPE_FUNCT: return "FUNCTION";
        case TYPE_FUNCT_PTR: return "PTRFUNCT";
        case TYPE_TUPLE: return "TUPLE";
        case TYPE_VOID: return "VOID"; 
        case TYPE_CLASS: return "CLASS";
        default: return "UNKNOWN_TYPE";
    }
}

/*---------------------------------------------------------
 * Helpers to print DimList, ParamList, and Gsymbol details
 *--------------------------------------------------------*/
void print_dimlist(DimNode* dimlist) {
    printf("Dims:[");
    while (dimlist) {
        printf("%d ", dimlist->size);
        dimlist = dimlist->next;
    }
    printf("] ");
}

void print_paramlist(ParamList* plist) {
    printf("Params:[");
    while (plist) {
        printf("%s:%s ", plist->name, type_to_string(plist->type));
        plist = plist->next;
    }
    printf("] ");
}

void print_gsymbol(Gsymbol* g) {
    if (!g) return;
    printf("Gentry:{name:%s type:%s varType:%d size:%d bind:%d flabel:%d} ",
           g->name,
           type_to_string(g->type),
           g->varType,
           g->size,
           g->binding,
           g->flabel);
}


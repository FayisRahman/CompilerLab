%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "exptree.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    
%}

%union{
    struct tnode* node;
    char character;
}
%token<node> PLUS MINUS DIV MUL NUM ID WRITE READ '='
%token begin end 

%type<node> E Program Slist Stmt InputStmt OutputStmt AsgStmt

%left PLUS MINUS
%left MUL DIV

%%

Program : begin Slist end {
            $$ = $2;
            head = $2;
        }
        | begin end {
            exit(0);
        }
        ;

Slist   : Slist Stmt {
            struct tnode* temp = createTree(0,NONE,NULL,CONNECTOR,$1,$2);
            $$ = temp;
        }
        | Stmt {
            $$ = $1;
        }
        ;

InputStmt : READ '(' ID ')' ';' {
            $1->left = $3;
            $$ = $1;
        }
        ;

OutputStmt : WRITE '(' E ')' ';' {
            $1->left = $3;
            $$ = $1;
        }
        ;

AsgStmt : ID '=' E ';' {
            $2->left = $1;
            $2->right = $3;
            $$ = $2;
        }
        ;

Stmt    : InputStmt { $$ = $1;}
        | OutputStmt { $$ = $1;}
        | AsgStmt { $$ = $1;}
        ;

E   : E PLUS E {
        $2->left = $1;
        $2->right = $3;
        $$ = $2;
    }
    | E MINUS E {
        $2->left = $1;
        $2->right = $3;
        $$ = $2;
    }
    | E DIV E {
        $2->left = $1;
        $2->right = $3;
        $$ = $2;
    }
    | E MUL E {
        $2->left = $1;
        $2->right = $3;
        $$ = $2;
    }
    | '('E')'{
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    | ID {
        $$ = $1;
    }
    ;
%%



void printNode(struct tnode* node) {
    if (node == NULL) return;
    switch (node->nodetype) {
        case READNODE:
            printf("READ Node\n");
            break;
        case WRITENODE:
            printf("WRITE Node\n");
            break;
        case CONNECTOR:
            printf("CONNECTOR Node\n");
            break;
        case OPERATOR:
            printf("OPERATOR Node: %s\n", node->varname); // e.g. "+"
            break;
        case EQUAL:
            printf("ASSIGNMENT Node (=)\n");
            break;
        case LEAFNODE:
            if (node->varname != NULL) {
                printf("LEAF Node (Variable): %s\n", node->varname);
            } else {
                printf("LEAF Node (Constant): %d\n", node->val);
            }
            break;
        default:
            printf("Unknown Node Type\n");
    }
}

void yyerror(char* s){
    printf("Error encountered: %s\n", s);
}

void postfixPrint(struct tnode* head){
    if(!head)return;
    if(!head->left && !head->right){
        if (head->varname != NULL) printf("%s ", head->varname);
        else printf("%d ", head->val);
        return;
    }
    postfixPrint(head->left);
    postfixPrint(head->right);
    printf("%s ", head->varname);
}

/* void prefixPrint(struct tnode* head){
    if(!head)return;
    if(!head->left && !head->right){
        if (head->op) printf("%s ", head->op);
        else printf("%d ", head->val);
        return;
    }
    printf("%s ", head->op);
    prefixPrint(head->left);
    prefixPrint(head->right);
    
} */



int main() {
    yyin = fopen("a.txt", "r");
    yyparse();
    /* FILE* fptr = openFile("a.xsm");
    makeHeader(fptr);
    int a = codeGen(head,fptr,CONNECTOR);
    exitFooter(fptr); */
    codeIntrepret(head,CONNECTOR);
    return 0;
}
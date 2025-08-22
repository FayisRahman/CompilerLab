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
%token<node> PLUS MINUS DIV MUL NUM VARIABLE
%token LPAREN RPAREN NL

%type<node> E program

%left PLUS MINUS
%left MUL DIV

%%
program : E NL{
    $$ = $1;
    head = $1;
}
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
    | LPAREN E RPAREN{
        $$ = $2;
    }
    | NUM {
        $$ = $1;
    }
    ;
%%

void yyerror(char* s){
    printf("Error encountered: %s", s);
}

void postfixPrint(struct tnode* head){
    if(!head)return;
    if(!head->left && !head->right){
        if (head->op) printf("%s ", head->op);
        else printf("%d ", head->val);
        return;
    }
    postfixPrint(head->left);
    postfixPrint(head->right);
    printf("%s ", head->op);
}

void prefixPrint(struct tnode* head){
    if(!head)return;
    if(!head->left && !head->right){
        if (head->op) printf("%s ", head->op);
        else printf("%d ", head->val);
        return;
    }
    printf("%s ", head->op);
    prefixPrint(head->left);
    prefixPrint(head->right);
    
}



int main() {
    yyin = fopen("a.txt", "r");
    yyparse();
    postfixPrint(head);
    printf("\n");
    prefixPrint(head);
    return 0;
}
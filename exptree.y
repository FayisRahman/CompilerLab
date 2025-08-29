%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "reghandling.h"
    #include "AST.h"
    #include "evaluator.h"
    #include "symbol_table.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    
%}

%union{
    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* symbol;
}
%token<node> WRITE READ INT STR ID NUM
%token<string>  STRING
%token begin end DECL ENDDECL 
%token PLUS MINUS DIV MUL 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL CONTINUE BREAK
%token GT GE LT LE NE EQ 

%type<node> E Program Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt
%type<node>  Whilestmt DoWhilestmt RepeatUntiltstmt Jumpstmt Type
%type<symbol>  Decl VarList
%type DeclList Declarations

%left  GT GE LT LE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

Program : begin Declarations Slist end ';' {
            $$ = $3;
            head = $3;
        }
        | begin end ';' {
            exit(0);
        }
        ;


Slist   : Slist Stmt {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,$1, NULL, $2);
            $$ = temp;
        }
        | Stmt {
            $$ = $1;
        }
        ;

Declarations    : DECL DeclList ENDDECL {stack_address = curr_stack_address;}
                | DECL ENDDECL {stack_address = curr_stack_address;}
                ;

DeclList    : DeclList Decl 
            | Decl
            ;

Decl        : Type VarList ';' {
                Gsymbol* temp = $2;
                Gsymbol* temp1 = $2;
                while(temp){
                    temp1 = temp->next;
                    temp->next = NULL;
                    add_symbol(temp,$1->type);
                    temp = temp1;
                }
            }
            ;   

Type        : INT {$$ = createVarNode(TYPE_INT,NULL,NULL,NULL); }
            | STR {$$ = createVarNode(TYPE_STRING,NULL,NULL,NULL); }
            ;

VarList     : VarList ',' ID {
                Gsymbol* temp = create_symbol_id($3->varname,1);
                $$ = append_symbol_id_list($1,temp);         
            }
            | ID {
                Gsymbol* temp = create_symbol_id($1->varname,1);
                $1->Gentry = temp;
                $$ = temp;
            }

InputStmt   : READ '(' ID ')' ';' {
                $1->left = $3;
                $$ = $1;
            }
            ;

OutputStmt  : WRITE '(' E ')' ';' {
                $1->left = $3;
                $$ = $1;
            }
            ;

AsgStmt : ID '=' E ';' {
            int type = get_type($1->Gentry);
            $$ = createTree(0,type, "=", EQUAL,NULL,$1, NULL, $3);
        }
        ;

Stmt    : InputStmt         { $$ = $1; }
        | OutputStmt        { $$ = $1; }
        | AsgStmt           { $$ = $1; }
        | Ifstmt            { $$ = $1; }
        | Whilestmt         { $$ = $1; }
        | DoWhilestmt       { $$ = $1; }
        | RepeatUntiltstmt  { $$ = $1; }
        | Jumpstmt          { $$ = $1; }
        ;

Ifstmt  : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {
            $$ = createIfNode($6,$3,$8);
        }   
        | IF '(' E ')' THEN Slist ENDIF ';' {
            $$ = createIfNode($6,$3,NULL);
        }
        ;

Whilestmt   : WHILE '(' E ')' DO Slist ENDWHILE ';' {
                $$ = createWhileNode($6,$3);
            }
            ;

DoWhilestmt : DO Slist WHILE '(' E ')'';' {
                $$ = createDoWhileNode($2,$5);
            }
            ;

RepeatUntiltstmt    : REPEAT Slist UNTIL '(' E ')'';' {
                        $$ = createDoWhileNode($2,$5);
                    }
                    ;

Jumpstmt    : CONTINUE ';' {
                $$ = createJumpNode(CONTINUENODE);
            }
            | BREAK ';' {
                $$ = createJumpNode(BREAKNODE);
            }
            ;


E   : E PLUS E {
        $$ = createTree(0, $1->type, "+", OPERATOR,NULL,$1, NULL, $3);
    }
    | E MINUS E {
        $$ =  createTree(0, $1->type , "-", OPERATOR,NULL,$1, NULL, $3);
    }
    | E DIV E {
        $$ = createTree(0, $1->type, "/", OPERATOR,NULL,$1, NULL, $3);
    }
    | E MUL E {
        $$ = createTree(0, $1->type, "*", OPERATOR,NULL,$1, NULL, $3);
    }
    | '(' E ')' {
        $$ = $2;
    }
    | E GT E {
        
        $$ = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LT E {
        
        $$ = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E GE E {
        $$ = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LE E {
        $$ = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E NE E {
        $$ = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E EQ E {
        $$ = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,$1,NULL,$3);
    }
    | NUM {
        $$ = createTree($1->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
    }
    | ID {
        Gsymbol* temp = find_symbol($1->varname);
        $$ = createTree(0, temp->type, $1->varname, LEAFNODE, temp,NULL, NULL,NULL);
    }
    | STRING {
        $$ = createTree(0, TYPE_STRING, $1, LEAFNODE,NULL, NULL, NULL,NULL);
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
    if(!head->middle && !head->right){
        if (head->varname != NULL) printf("%s ", head->varname);
        else printf("%d ", head->val);
        return;
    }
    postfixPrint(head->middle);
    postfixPrint(head->right);
    printf("%s ", head->varname);
}



int main() {
    yyin = fopen("a.txt", "r");
    yyparse();
    print_symbol_table();
    FILE* fptr = fopen("a.xsm", "w");
    make_header(fptr);
    codeGen(head,0,0,fptr);
    exit_footer(fptr);
    /* codeIntrepret(head); */
    return 0;
}
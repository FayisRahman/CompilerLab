%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "reghandling.h"
    #include "AST.h"
    #include "evaluator.h"
    #include "global_symbol_table.h"
    #include "local_symbol_table.h"
    #include "dim_node.h"
    #include "param_list.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    
%}

%union{
    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
}
%token<node> WRITE READ INT STR ID NUM
%token<string>  STRING
%token begin end MAIN DECL ENDDECL 
%token PLUS MINUS DIV MUL 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL CONTINUE BREAK
%token GT GE LT LE NE EQ 

%type<integer> Type
%type<node> E Program Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt
%type<node>  Whilestmt DoWhilestmt RepeatUntiltstmt Jumpstmt
%type<node>  GDeclBlock FDefBlock MainBlock
%type<gsymbol>  Decl VarList Var Gid GidList
%type<DimList> DimList DimAccess 
%type<plist> Paramlist Param
%type<lsymbol> IdList LDecList LDecl LdeclBlock
%type DeclList Declarations

%left  GT GE LT LE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%%

Program : GDeclBlock FDefBlock MainBlock {}
        | GDeclBlock MainBlock {}
        | MainBlock {}
        | Declarations Slist ';' {
            $$ = $2;
            head = $2;
        }
        | begin end ';' {
            exit(0);
        }
        ;

GDeclBlock  : DECL GDeclList ENDDECL {}
            | DECL ENDDECL {}
            ;

GDeclList   : GDeclList GDecl {stack_address = curr_stack_address;}
            | GDecl{stack_address = curr_stack_address;}
            ;

GDecl   : Type GidList ';' {
            Gsymbol* temp = $2;
            Gsymbol* temp1 = $2;
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                add_gsymbol(temp,$1);
                temp = temp1;
            }
        }
        ;

GidList : GidList ',' Gid{
            $$ = append_gsymbol_id_list($1,$3);    
        } 
        | Gid { $$ = $1;}
        ;

Gid     : ID DimList {
            Gsymbol* temp = create_symbol_id_with_dims($1->varname, $2);
            $1->Gentry = temp;
            $1->type = TYPE_ARR;
            $1->Gentry->varType = TYPE_ARR;
            if(!$2){
                $1->type = TYPE_VAR;
                $1->Gentry->varType = TYPE_VAR;
            }
            $$ = temp;
        }
        | MUL ID {
            Gsymbol* temp = create_gsymbol_id($2->varname, 2);
            $2->Gentry = temp;
            $2->type = TYPE_PTR;
            temp->varType = TYPE_PTR;
            $$ = temp;
        } //here i used MUL because lex returnes MUL when the it captures '*' 
        | ID '(' Paramlist ')' {
            int size = get_paramlist_length($3);
            Gsymbol* temp = create_gsymbol_id($1->varname, size);
            temp->plist = $3;
            temp->varType = TYPE_FUNCT;
        }
        ;

// ------------------------------------------------------------------------//

FDefBlock   : FDefBlock Fdef 
            | Fdef
            ;

Fdef        : Type ID '(' Paramlist ')' '{' LdeclBlock Slist '}' {
                Gsymbol* temp = find_gsymbol($2->varname);
                if($1 != temp->type){
                    printf("Error: Incorrect return type for the Function %s\n", $2->varname);
                    exit(0);
                }
                is_paramlist_correct(temp->plist,$4);
                
            }
            ;

Paramlist   : Paramlist ',' Param {
                $$ = append_param_to_list($1,$3);
            }
            | Param {$$ = $1;}
            |   /*param can be empty */ {$$ = NULL;}
            ;

Param       : Type ID {
                $$ = create_param($2->varname,$1);
            }
            ;

//-------------------------------------------------------------------------//

LdeclBlock  : DECL LDecList ENDDECL {
                Lsymbol* temp = $2;
                int addr = 0;
                while(temp){
                    temp->binding = addr++;
                    temp = temp->next;
                }
                $$ = $2;
            }
            | DECL ENDDECL { $$ = NULL;}
            ;

LDecList    : LDecList LDecl {
                Lsymbol* temp = $2;
                while(temp){
                    check_lpresent($1,temp->name);
                    temp = temp->next;
                }
                $1->next = $2;
                $$ = $1;
            }
            | LDecl {
                $$ = $1;
            }
            ;

LDecl       : Type IdList ';' {
                Lsymbol* temp = $2;
                while(temp){
                    check_lpresent($2,temp->name);
                    temp->type = $1;
                    temp = temp->next;
                }
                $$ = $2;
            }
            ;

IdList      : IdList ',' ID {
                $$ = append_lsymbol_id_list($1, create_lsymbol_id($3->varname, 1));
            }
            | ID {
                $$ = create_lsymbol_id($1->varname, 1);
            }
            ;

ArgList     : ArgList ',' E 
            | E
            ;

//-------------------------------------------------------------------------//

MainBlock : Type MAIN '(' ')' '{' LdeclBlock Slist '}'

//-------------------------------------------------------------------------//

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
                    add_gsymbol(temp,$1);
                    temp = temp1;
                }
            }
            ;   

Type        : INT {$$ = TYPE_INT; }
            | STR {$$ = TYPE_STRING; }
            ;

VarList     : VarList ',' Var {
                $$ = append_gsymbol_id_list($1,$3);         
            }
            | Var {
                $$ = $1;
            }
            ;

Var     : ID DimList {
            Gsymbol* temp = create_symbol_id_with_dims($1->varname, $2);
            $1->Gentry = temp;
            $1->type = TYPE_ARR;
            $1->Gentry->varType = TYPE_ARR;
            if(!$2){
                $1->type = TYPE_VAR;
                $1->Gentry->varType = TYPE_VAR;
            }
            $$ = temp;
        }
        | MUL ID {
            Gsymbol* temp = create_gsymbol_id($2->varname, 2);
            $2->Gentry = temp;
            $2->type = TYPE_PTR;
            temp->varType = TYPE_PTR;
            $$ = temp;
        } //here i used MUL because lex returnes MUL when the it captures '*' 
        ;

DimList : DimList '[' NUM ']' {
            $$ = append_dim($1, $3->val);
        }
        | /* empty */   { $$ = create_dimlist(NULL); }
        ;

InputStmt   : READ '(' ID  ')' ';' {
                Gsymbol* temp = find_gsymbol($3->varname);
                $3->Gentry = temp;
                $1->left = $3;
                $$ = $1;
            }
            | READ '(' ID DimAccess ')' ';' {
                Gsymbol* temp = find_gsymbol($3->varname);
                $3->Gentry = temp;
                check_not_out_of_bounds($4,$3->Gentry->dimlist);
                $1->left = $3;
                $3->dimlist = $4;
                $$ = createTree(0,TYPE_NULL, "Read", READNODE,NULL,$3, NULL, NULL);
            }
            | READ '(' MUL ID ')' ';' {
                Gsymbol* entry = find_gsymbol($4->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,$4, NULL,NULL);
                $$ = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
            ;

OutputStmt  : WRITE '(' E ')' ';' {
                $1->left = $3;
                $$ = $1;
            }
            ;

AsgStmt : ID '=' E ';' {
            Gsymbol* temp = find_gsymbol($1->varname);
            if(temp->varType != TYPE_VAR && temp->varType != TYPE_PTR){
                printf("Error: %s is not of variable type\n",$1->varname);
                exit(1);
            }
            check_data_types(temp->type,$3->type,temp->type);
            $$ = createTree(0,TYPE_VAR, "=", EQUAL,temp,$1, NULL, $3);
        }
        | ID DimAccess '=' E ';'{
            Gsymbol* temp = find_gsymbol($1->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",$1->varname);
                exit(1);
            }
            check_data_types(temp->type,$4->type,temp->type);
            $1->Gentry = temp;
            $1->dimlist = $2;
            check_not_out_of_bounds($2,$1->Gentry->dimlist);
            $$ = createTree(0,TYPE_ARR, "=", EQUAL,$1->Gentry,$1, NULL, $4);
        }
        | MUL ID '=' E ';' {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* temp = find_gsymbol($2->varname);
            if(temp->varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",$2->varname);
                exit(1);
            }
            check_data_types(temp->type,$4->type,temp->type);
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, temp,$2, NULL, NULL);
            $$ = createTree(0,TYPE_PTR, "=", EQUAL,NULL,t, NULL, $4);
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

DoWhilestmt : DO Slist WHILE '(' E ')' ';' {
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
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0, $1->type, "+", OPERATOR,NULL,$1, NULL, $3);
    }
    | E MINUS E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ =  createTree(0, $1->type , "-", OPERATOR,NULL,$1, NULL, $3);
    }
    | E DIV E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0, $1->type, "/", OPERATOR,NULL,$1, NULL, $3);
    }
    | E MUL E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0, $1->type, "*", OPERATOR,NULL,$1, NULL, $3);
    }
    | E MOD E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0, $1->type, "%", OPERATOR,NULL,$1, NULL, $3);
    }
    | '(' E ')' {
        $$ = $2;
    }
    | E GT E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LT E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E GE E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LE E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E NE E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E EQ E {
        check_data_types($1->type,$3->type,TYPE_INT);
        $$ = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,$1,NULL,$3);
    }
    | ID '(' ')' {}
    | ID '(' ArgList ')' {}
    | ID {
        Gsymbol* temp = find_gsymbol($1->varname);
        if(temp->varType != TYPE_VAR && temp->varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",$1->varname);
            exit(1);
        }
        $$ = createTree(0, temp->type, $1->varname, LEAFNODE, temp,NULL, NULL,NULL);
    }
    | ID DimAccess {
        Gsymbol* temp = find_gsymbol($1->varname);
        if(!$2){
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is of array type but using it as variable type here\n",$1->varname);
                exit(1);
            }
        }
        $1->Gentry = temp;
        check_not_out_of_bounds($2,$1->Gentry->dimlist);
        int val = get_pos($2,$1->Gentry->dimlist);
        $$ = createTree(val, temp->type, $1->varname, LEAFNODE, temp,NULL, NULL,NULL);
        $$->dimlist = $2;
    }
    | MUL ID { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* temp = find_gsymbol($2->varname);
        $2->Gentry = temp;

        $$ = createTree(0, TYPE_INT, "*", PTRNODE, temp,$2, NULL,NULL);
    }
    | '&' ID {
        Gsymbol* temp = find_gsymbol($2->varname);
        $2->Gentry = temp;
        $$ = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,$2, NULL,NULL);
    }
    | STRING {
        $$ = createTree(0, TYPE_STRING, $1, LEAFNODE,NULL, NULL, NULL,NULL);
    }
    | NUM {
        $$ = createTree($1->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
    }
    ;
DimAccess   : DimAccess '[' E ']' {
                check_data_types($3->type,TYPE_INT,TYPE_INT);
                $$ = append_dim_with_id($1,$3);
            }
            | '[' E ']' {
                check_data_types($2->type,TYPE_INT,TYPE_INT);
                $$ = append_dim_with_id(NULL,$2);
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
    exit(1);
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
    print_gsymbol_table();
    FILE* fptr = fopen("a.xsm", "w");
    make_header(fptr);
    setup_pointers_codegen(fptr);
    codeGen(head,0,0,fptr);
    exit_footer(fptr);
    create_label_with_message(fptr,101,"IndexOutOfBounds");
    /* codeIntrepret(head); */
    return 0;
}
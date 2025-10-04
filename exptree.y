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
    #include "tree_visualization.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    
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
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL CONTINUE BREAK RETURN BREAKPOINT
%token GT GE LT LE NE EQ AND OR

%type<integer> Type
%type<node> E  ArgList Program Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt body 
%type<node>  Whilestmt DoWhilestmt RepeatUntiltstmt Jumpstmt Debugstmt
%type<node>  FDefBlock MainBlock
%type<gsymbol> Gid GidList
%type<DimList> DimList DimAccess 
%type<plist> Paramlist Param ParamDecl
%type<lsymbol> IdList LDecList LDecl LdeclBlock IdDecl

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%%

Program : GDeclBlock FDefBlock MainBlock {}
        | GDeclBlock MainBlock {}
        | MainBlock {stack_address = curr_stack_address;driver_codegen(fptr);}
        ;

GDeclBlock  : DECL GDeclList ENDDECL {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                printf("------Global Variables Declared-----\n");
                driver_codegen(fptr);
            }
            | DECL ENDDECL {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                driver_codegen(fptr);
            }
            ;

GDeclList   : GDeclList GDecl {}
            | GDecl{}
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
            Gsymbol* temp = create_gsymbol_id($1->varname, 1);
            temp->plist = $3;
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            $$ = temp;
        }
        | MUL ID '(' Paramlist ')' {
            int size = get_paramlist_length($4);
            Gsymbol* temp = create_gsymbol_id($2->varname, 1);
            temp->plist = $4;
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            $$ = temp;
        }
        ;

// ------------------------------------------------------------------------//

FDefBlock   : FDefBlock Fdef {} 
            | Fdef {}
            ;

Fdef        :   Type ID '(' Paramlist ')' '{' LdeclBlock body '}' {    

                function_block($1,$2,$4,$8,TYPE_FUNCT);

            }
            |   Type MUL ID '(' Paramlist ')' '{' LdeclBlock body '}' {

                function_block($1, $3,$5,$9, TYPE_FUNCT_PTR);

            }
            ;

Paramlist   : Paramlist ',' ParamDecl {
                $$ = append_param_to_list($1,$3);
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id($3->name, 1, $3->varType);
                    t1->type = $3->type;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
            | ParamDecl {
                $$ = $1;
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id($1->name, 1, $1->varType);
                    t1->type = $1->type;
                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
            |   /*paramDecl can be empty */ {$$ = NULL;curr_lsymbol_table= NULL;}
            ;

ParamDecl   : Type Param {
                $2->type = $1;
                $$ = $2;
            }
            ;

Param       : ID {
                $$ = create_param($1->varname,TYPE_NULL);
                $$->size = 1;
                $$->varType = TYPE_VAR;
            }
            | MUL ID {
                $$ = create_param($2->varname,TYPE_NULL);
                $$->size = 1;
                $$->varType = TYPE_PTR;
                
            }

//-------------------------------------------------------------------------//

LdeclBlock  : DECL LDecList ENDDECL {
                Lsymbol* temp = curr_lsymbol_table;
                while(temp && temp->next){
                    temp = temp->next;
                }
                if(temp) temp->next = $2;
                else curr_lsymbol_table = $2;
                lst_set_bindings(curr_lsymbol_table);
                $$ = curr_lsymbol_table;
            }
            |  {$$ = NULL;lst_set_bindings(curr_lsymbol_table);}
            ;

LDecList    : LDecList LDecl {
                Lsymbol* temp = $2;
                while(temp){
                    check_lpresent($1,temp->name);
                    temp = temp->next;
                }
                temp = $1;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = $2;
                $$ = $1;
            }
            | LDecl {
                $$ = $1;   
            }
            ;

LDecl       : Type IdList ';' {
                Lsymbol* temp = $2;
                while(temp){
                    temp->type = $1;
                    temp = temp->next;
                }
                $$ = $2;
            }
            ;

IdList      : IdList ',' IdDecl  {
                check_lpresent($1,$3->name);
                $$ = append_lsymbol_id_list($1, $3);
            }
            | IdDecl {
                $$ = $1;
            }
            ;

IdDecl      : ID {
                $$ = create_lsymbol_id($1->varname, 1, TYPE_VAR);
            }
            | MUL ID{
                $$ = create_lsymbol_id($2->varname, 2, TYPE_PTR);
                printf("ptr name: %s\n",$2->varname);
            }
ArgList     : ArgList ',' E {
                $1->middle = $3;
                $$ = $1;
            }
            | E { $$ = $1;}
            ;

//-------------------------------------------------------------------------//

MainBlock : Type MAIN '(' ')' '{' LdeclBlock body '}' {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        tree_visual_printTree($7);

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_curr_offset(curr_lsymbol_table);

        fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen($7,0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}

//-------------------------------------------------------------------------//

body : begin Slist end {$$ = $2;}

Slist   : Slist Stmt {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,$1, NULL, $2);
            $$ = temp;
        }
        | Stmt {
            $$ = $1;
        }
        ;

Type        : INT { $$ = TYPE_INT; }
            | STR { $$ = TYPE_STRING; }
            ;

DimList : DimList '[' NUM ']' {
            $$ = append_dim($1, $3->val);
        }
        | /* empty */   { $$ = create_dimlist(NULL); }
        ;

InputStmt   : READ '(' ID  ')' ';' {
                Gsymbol* ptr1 = find_gsymbol($3->varname);
                Lsymbol* ptr2 = find_lsymbol($3->varname);
                int varType = get_var_type(ptr1,ptr2,$3->varname);
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
            Gsymbol* ptr1 = find_gsymbol($1->varname);
            Lsymbol* ptr2 = find_lsymbol($1->varname);
            int varType = get_var_type(ptr1,ptr2,$1->varname);
            if(varType != TYPE_VAR && varType != TYPE_PTR){
                printf("Error: %s is not of variable type\n",$1->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,$3->type,ptr2->type);
            }else if(ptr1){
                check_data_types(ptr1->type,$3->type,ptr1->type);
            }else{
                printf("Error: Variable %s Not Declared\n", $1->varname);
                exit(0);
            }
            $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,$1, NULL, $3);
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
            $$ = createTree(0,TYPE_ARR, "=", ASSIGNMENT,$1->Gentry,$1, NULL, $4);
        }
        | MUL ID '=' E ';' {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* ptr1 = find_gsymbol($2->varname);
            Lsymbol* ptr2 = find_lsymbol($2->varname);
            int varType = get_var_type(ptr1,ptr2,$2->varname);
            if(varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",$2->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,$4->type,ptr2->type);
            }else if(ptr1){
                check_data_types(ptr1->type,$4->type,ptr1->type);
            }else{
                printf("Error: Variable %s Not Declared\n", $2->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,$2, NULL, NULL);
            $$ = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, $4);
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
        | Debugstmt         { $$ = $1; }
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
            | RETURN E ';' {  
                $$ = createTree(0, TYPE_NULL, NULL, RETURNNODE, NULL,$2, NULL,NULL);
            }
            ;

Debugstmt : BREAKPOINT ';' {
                $$ = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
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
    | E AND E {
        check_data_types($1->type,$3->type,TYPE_BOOL);
        $$ = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,$1,NULL,$3);
    }
    | E OR E {
        check_data_types($1->type,$3->type,TYPE_BOOL);
        $$ = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,$1,NULL,$3);
    }
    | ID '(' ')' {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        if(!ptr1 || ptr1->varType != TYPE_FUNCT || ptr1->varType != TYPE_FUNCT_PTR){
            printf("Error: No function with name %s declared\n",$1->varname);
            exit(0);
        }
        param_list_is_input_args_correct(ptr1->plist, NULL);
        $$ = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,$1,NULL,NULL);
    }
    | ID '(' ArgList ')' {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",$1->varname);
            exit(0);
        }
        param_list_is_input_args_correct(ptr1->plist, $3);
        $$ = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,$1,NULL,$3);
    }
    | ID {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        Lsymbol* ptr2 = find_lsymbol($1->varname);
        int varType = get_var_type(ptr1,ptr2,$1->varname);
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",$1->varname);
            exit(1);
        }
        $$ = createTree(0, get_type(ptr1,ptr2,$1->varname), $1->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
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
    | MINUS NUM {
        $$ = createTree(-$2->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
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


void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType){
    Gsymbol* temp = find_gsymbol($2->varname);
    if($1 != temp->type || functionType != temp->varType){
        printf("Error: Incorrect return type for the Function %s\n", $2->varname);
        exit(0);
    }

    is_paramlist_correct(temp->plist,$4);

    print_lsymbol_table();

    
    
    //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome 
    // curr_lsymbol_table = $7;

    ParamList* t = $4;
    int p = getReg();
    fprintf(fptr,"F%d:", temp->flabel);
    fprintf(fptr, "MOV R%d, BP\n", p);
    fprintf(fptr, "PUSH R%d\n", p);
    fprintf(fptr, "MOV BP, SP\n");
    
    int param_list_size = get_paramlist_length($4);

    //setting up the argument values into the respective addresses in the from the local symbol table
    
    while(t){
        fprintf(fptr, "MOV R%d, SP\n", p);
        fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 3 - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                    // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
        fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
        fprintf(fptr, "PUSH R%d\n", p);
        t = t->next;
    }

    // This is to set up space for the locally declared variables in the function
    int curr_offset = get_curr_offset(curr_lsymbol_table) - param_list_size;

    fprintf(fptr, "ADD SP, %d\n", curr_offset);

    freeReg();

    tree_visual_printTree($8);

    Lsymbol* temp1 = curr_lsymbol_table;

    while(param_list_size-- > 0){
        temp1 = temp1->next;
    }

    setup_pointers_codegen(fptr,NULL,temp1);

    codeGen($8,0,0,fptr);
    Lsymbol* a = curr_lsymbol_table;
    // lst_destroy(a);
    curr_lsymbol_table = NULL;
    // ast_destroy($8);
}


void yyerror(char* s){
    printf("Error encountered: %s\n", s);
    exit(1);
}





int main() {
    yyin = fopen("a.txt", "r");
    fptr = fopen("a.xsm", "w");
    make_header(fptr);
    yyparse();
    print_gsymbol_table();
    exit_footer(fptr);
    create_label_with_message(fptr,101,"IndexOutOfBounds");
    fclose(fptr);
    fclose(yyin);
    /* codeIntrepret(head); */
    return 0;
}
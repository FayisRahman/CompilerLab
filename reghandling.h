#ifndef REGHANDLING_H
#define REGHANDLING_H

#include <stdio.h>
#include <string.h>
#include "global_symbol_table.h"
#include "local_symbol_table.h"
#include "AST.h"
#include "exptree.h"
#include "type_table.h"

extern int stack_address;

//GET THE HIGHEST LOWEST CURRENTLY UNUSED REGISTER
int getReg();

//FREE THE HIGHEST CURRENTLY USED REGISTER
void freeReg();

//CREATE LABEL
int createLabel();

//GENERATE THE HEADER PART OF THE XSM FILE
void make_header(FILE *fptr);

//Generate the code for arithemetic operations and in the end returns the lastly used register number
int arithemetic_expression_codegen(struct tnode *t, FILE *fptr);

//Generate the code for assignement operations when t->nodetype is EQUAL
void assignment_expression_codegen(struct tnode *t, FILE *fptr);

//GENERATE the code for boolean expression when t->nodetype == EXPRESSION

/*
     _____________________________________
    | Integer           Means             |
    |    0       is not a do while loop   |         -|____ is for is_do_while arg
    |    1       is a do while loop       |         -|   
    |                                     | 
    |    0       is AND Operator          |         -|____ is for is_dor arg
    |    1       is OR opeartor           |         -|
    |_____________________________________|

*/
void boolean_expression_codegen(struct tnode *t, FILE *fptr, int trueLabel, int falseLabel); 

//READ FROM STDIN
void read_code_to_addr(FILE* fptr, struct tnode* t);

//SELECTS THE APPROPRIATE WRITE CODEGEN FUNCTION BASED ON : the t->left->nodetype is operator or variable
void write_codegen(struct tnode* t,FILE* fptr);

//WRITING TO THE TERMINAL FROM AN ADDRESS
void write_code_from_addr(FILE* fptr, struct tnode* t);

//WRITING TO THE TERMINAL FROM A REGISTER
void write_code_from_reg(FILE* fptr, int regNo);

//MAIN CODE GENERATION FILE THAT GENRATE THE XSM CODE ACCORDING TO THE AST
void codeGen(struct tnode *t, int end_label, int count_label,FILE *fptr);

//GENERATE THE EXIT CALL CODE
void exit_footer(FILE* fptr);

//GENERATE THE CODE FOR IF ELSE.(IT EXPECTS TO RECIEVE THE LABELS OF LOOP JUST OUT OF THE IF ELSE)
void if_node_codegen(FILE* fptr,tnode* t,int end_label,int cont_label);

//GENERATE THE CODE FOR WHILE LOOP
void while_node_codegen(FILE* fptr,tnode* t);

//GENERATE THE CODE FOR DO WHILE LOOP AND REPEAT UNTIL LOOP AS THEY HAVE THE SAME FUNCTIONALITY
void do_while_node_codegen(FILE* fptr,tnode* t);

//THIS SETUP THE VALUE IN THE POINTER VARIABLE'S ADDRESS 
void setup_pointers_codegen(FILE* fptr,Gsymbol* gptr, Lsymbol* lptr);

//---THE BELOW TWO FUNCTION IS TO HANDLE POINTERS AND ADDRESS AS ADDRESS RETURNS A POINTER TYPE---

/*
    THIS RETURNS THE ADDRESS OF TEH VARIABLE AND IN THE SCOPE OF THIS STAGE I HAVE MADE IT POSSIBLE ONLY TO
    GET THE ADDRESS OF VARIABLES AND WE CANT GET THE ADDRESS OF ARRAYS AND POINTER DATA TYPE
*/
int addr_node_codegen(FILE* fptr,tnode* t); //used on RHS of an assignment operator only

/*
    THIS FUNCTION RETURNS THE POINTER DATA BASED ON ITS SIDE AND IF ITS ON LHS THE side ARG IS 0 AND IF ITS ON RHS THE side ARG is 1
    IF ON LHS WE GET THE ADDRESS THAT THE POINTER IT POINTING TO AND IF ITS ON RHS WE GET THE VALUE INSIDE THE ADDRESS THAT THE POINTER
    IS POINTING TO.
     __________________
    | Integer    Side  |
    |    0       LHS   |
    |    1       RHS   |
    |__________________|
*/
int ptr_node_codegen(FILE* fptr,tnode* t,int side); 

// TO CHECK IF THE ARRAY ACCESS IS IN BOUND
void index_overflow_check_codegen(FILE* fptr, int regNo, int size);

// TO GET THE OFFSET FOR ARRAY ACCESS
int array_position_codegen(FILE* fptr, DimNode* d, DimNode* main);

/*
    CREATING A LABEL WITH A PRINT MESSAGE THAT PRINTS ERRORS ETC...
    AT THIS POINT I HAVE ONLY IMPLEMENTED THE INDEX OUT OF BOUNDS PART
    
*/
void create_label_with_message(FILE* fptr,int label_no,char* msg);


//TO GENERATE THE CODE FOR A FUNCTION AND SET UP THE ACTIVATION RECORD
int function_node_codegen(FILE* fptr,tnode* t);

int method_node_codegen(FILE* fptr,tnode* t);

//TO GENERATE THE RETURN CODE AND TO REMOVE THE UNNECESSARY STACK CONTENTS AND REMOVE THE ACTIVATION RECORD OF THE FUNCTION
void return_node_codegen(FILE* fptr, tnode* t);

//THIS IS THE DRIVER CODE THAT CALLS THE MAIN FUNCTION AND STORES THE RETURN VALUE SO THAT IT CAN BE LATER USED FOR FURTHER PROCCESSING IF NESCCESSARY AND ALL WITH THIS WE CAN CONSIDER MAIN AS A FUNCTION ITSELF AND NOT AS A SPECIAL FUCNTION
void driver_codegen(FILE* fptr);

//THIS GENERATES THE CODE FOR THE DOT OPERATOR WHICH IS TUPLE_VAR_NAME.ATTRIBUTE AND RETURNS THE REGISTER NO. IT STORES THE VALUE IN
int dot_node_codegen(FILE* fptr, tnode* t,int is_read);

//THIS GENERATES THE CODE FOR THE ARROW OPERATOR WHICH IS TUPLE_VAR_NAME->ATTRIBUTE AND RETURNS THE REGISTER NO. IT STORES THE VALUE IN
int arrow_node_codegen(FILE* fptr,tnode* t, int is_read);

#endif

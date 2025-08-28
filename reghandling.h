#ifndef REGHANDLING_H
#define REGHANDLING_H

#include <stdio.h>
#include <string.h>
#include "AST.h"

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
int boolean_expression_codegen(struct tnode *t, FILE *fptr);

//READ FROM STDIN
void read_code_to_addr(FILE* fptr, char* var);

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





#endif

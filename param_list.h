#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "AST.h"

typedef struct ParamList{
    char* name;
    DataType type;
    int size;
    int varType;
    struct ParamList* next;
}ParamList;

ParamList* create_param(char* name,DataType type);
ParamList* append_param_to_list(ParamList* main,ParamList* t);
int get_paramlist_length(ParamList* list);
void is_paramlist_correct(ParamList* main, ParamList* t);
void param_list_is_input_args_correct(ParamList* main, tnode* t);
void paramlist_destroy(ParamList* head);

void display(ParamList* head);

#endif
#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "AST.h"

typedef struct ParamList{
    char* name;
    DataType type;
    struct ParamList* next;
}ParamList;

ParamList* create_param(char* name,DataType type);
ParamList* append_param_to_list(ParamList* main,ParamList* t);
int get_paramlist_length(ParamList* list);
void is_paramlist_correct(ParamList* main, ParamList* t);

void display(ParamList* head);

#endif
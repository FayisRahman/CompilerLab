#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "AST.h"
#include "exptree.h"
#include "type_table.h"
#include "class_table.h"

struct tnode;
struct TypeTable;

typedef struct ParamList{
    char* name;
    DataType type;
    int size;
    int varType;
    struct TypeTable* typeEntry;
    struct Classtable* centry;
    struct ParamList* next;
}ParamList;

ParamList* create_param(char* name,DataType type);
ParamList* append_param_to_list(ParamList* main,ParamList* t);
int get_paramlist_length(ParamList* list);
void is_paramlist_correct(ParamList* main, ParamList* t);
void paramlist_is_input_args_correct(ParamList* main, struct tnode* t);
void paramlist_destroy(ParamList* head);

void paramlist_display(ParamList* head);

ParamList* paramlist_deepcopy(const ParamList* src);

int paramlist_get_size(ParamList* plist);

#endif
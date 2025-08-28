#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "AST.h"

int curr_stack_address = 4095;
struct Gsymbol *top = NULL;



void add_symbol(Gsymbol *id, int type){

    Gsymbol *tail = top;
    while(tail->next){
        if(strcmp(tail->name, id->name) == 0){
           printf("variable already declared");
           exit(1);
        }
        tail = tail->next;
    }
    if(strcmp(tail->name, id->name) == 0){
        printf("variable already declared");
        exit(1);
    }
    curr_stack_address++;
    id->type = type;
    id->binding = curr_stack_address;
    if(!top){
        top = id;
    }else{
        tail->next = id;
    }
}

struct Gsymbol *Lookup(char * name){
    Gsymbol *tail = top;
    while(tail){
        if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }
    printf("variable not declared");
    exit(0);
}

Gsymbol* create_symbol_id(char *name, int size){

    Gsymbol *temp = malloc(sizeof(struct Gsymbol));
    temp->name = strdup(name);
    temp->type = TYPE_NULL;
    temp->size = size;
    temp->binding = 0;
    return temp;
}

Gsymbol* append_symbol_id_list(Gsymbol *list,Gsymbol *id){
    list->next = id;
    return list;
}
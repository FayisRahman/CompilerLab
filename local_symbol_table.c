#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local_symbol_table.h"

struct Lsymbol* curr_lsymbol_table = NULL;
int curr_addr_offset = 0;
int curr_funct = 0;


Lsymbol* add_lsymbol(Lsymbol *id, int type) {
    if(is_gpresent(id->name)!=NULL){
        printf("Error: Variable %s already Declared\n", id->name);
        exit(0);
    }

    if(curr_stack_address > 1024){
        printf("Error: Memory Overflow\n");
        exit(0);
    }

    Lsymbol* t = curr_lsymbol_table;
    if(!t){
        curr_lsymbol_table = id;
    }else{
        while(t->next){
            t=t->next;
        }
        t->next = id;
    }
}

void check_lpresent(Lsymbol* main,char* name){
    Lsymbol *tail = main;
    while(tail){
        if(strcmp(tail->name, name) == 0){
            printf("Error: Variable %s already declared in the scope\n",name);
            exit(0);
        }
        tail = tail->next;
    }
}

struct Lsymbol *find_lsymbol(char * name){
    if (!name) {
        fprintf(stderr, "find_lsymbol called with NULL name!\n");
        exit(1);
    }
    Lsymbol *tail = curr_lsymbol_table;
    while(tail){
        if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }

}

struct Lsymbol* create_lsymbol_id(char *name, int size,int varType){
    printf("create_lsymbol_id: name=%s size=%d\n", name ? name : "NULL", size);
    if (!name) {
        fprintf(stderr, "ERROR: create_lsymbol_id got NULL name!\n");
        exit(1);
    }
    Lsymbol *temp = malloc(sizeof(struct Lsymbol));
    temp->name = strdup(name);
    temp->type = TYPE_NULL;
    temp->varType = varType;
    temp->size = size;
    temp->next = NULL;
    temp->binding = 0;
    return temp;
}

Lsymbol* append_lsymbol_id_list(Lsymbol *list, Lsymbol *id){
    
    if (list == NULL) {
        list = id;
        id->binding = 0;
        return list;
    }
    Lsymbol *temp = list;
    while (temp->next) temp = temp->next;
    printf("name: %s, binding: %d, size: %d\n",temp->name,temp->binding,temp->size);
    id->binding = temp->binding + temp->size;
    temp->next = id;
    id->next = NULL;
    return list;
}

int get_ltype(Lsymbol* entry){
    if(!entry)return TYPE_NULL;
    return entry->type;
}


int get_curr_offset(Lsymbol* head){
    int ans = 0;
    Lsymbol* temp = head;
    while(temp){
        ans += temp->size;
        // printf("%s->",temp->name);
        temp = temp->next;
    }
    return ans;
}

void lst_destroy(Lsymbol* head){

    if(!head)return;
    lst_destroy(head->next);
    free(head->name);
    free(head);

}

Lsymbol* lst_set_bindings(Lsymbol* head){
    int binding = 1;
    Lsymbol* temp = head;
    while(temp){
        temp->binding = binding;
        binding += temp->size;
        temp = temp->next;
    }
    return head;

}

void print_lsymbol_table() {
    struct Lsymbol *temp = curr_lsymbol_table;

    if (temp == NULL) {
        printf("lSymbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType" , "Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", 
               temp->name,
               temp->varType,
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}


void print_lsymbol_list(Lsymbol* t) {
    struct Lsymbol *temp = t;

    if (temp == NULL) {
        printf("lSymbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType","Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", 
               temp->name,
               temp->varType,
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}



//--------------------GET SYMBOL TABLE DATAS-----------------------------START-------//

int get_var_type(Gsymbol* gentry, Lsymbol* lentry,char* varname){
    if(lentry){
        return lentry->varType;
    }else if(gentry){
        return gentry->varType;
    }else{
        printf("Error: Variable %s not declared\n",varname);
        exit(0);
    }
}

int get_type(Gsymbol* gentry, Lsymbol* lentry,char* varname){
    if(lentry){
        return lentry->type;
    }else if(gentry){
        return gentry->type;
    }else{
        printf("Error: Variable %s not declared\n",varname);
        exit(0);
    }
}

DimNode* get_dimlist(Gsymbol* gentry, Lsymbol* lentry,char* varname){
    //as of stage 5 we are not going for array in local symbol table and only gsymbol table is required for array 
    if(gentry){
        return gentry->dimlist;
    }else{
        printf("Error: Variable %s not declared\n",varname);
        exit(0);
    }
}

int get_binding(Gsymbol* gentry, Lsymbol* lentry,char* varname,FILE* fptr, int regNo){
    //as of stage 5 we are not going for array in local symbol table and only gsymbol table is required for array 
    if(lentry){
        fprintf(fptr, "MOV R%d, %d\n", regNo, lentry->binding);
        fprintf(fptr, "ADD R%d, BP\n", regNo);
        return regNo;
    }else if(gentry){
        fprintf(fptr, "MOV R%d, %d\n", regNo, gentry->binding);
        return regNo;
    }else{
        printf("Error: Variable %s not declared\n",varname);
        exit(0);
    }
}



//--------------------GET SYMBOL TABLE DATAS-----------------------------END---------//
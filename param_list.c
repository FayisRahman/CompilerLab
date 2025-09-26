#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "param_list.h"

ParamList* create_param(char* name, DataType type) {
    ParamList* node = (ParamList*)malloc(sizeof(ParamList));
    if (!node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    node->name = strdup(name); // copies the string
    node->type = type;
    node->next = NULL;
    return node;
}

ParamList* append_param_to_list(ParamList* main, ParamList* t) {
    if (!main) return NULL; // safety check
    ParamList* curr = main;
    while (curr->next) {
        if(strcmp(curr->name,t->name) == 0){
            printf("Error: Variable %s already present as function argument\n", curr->name);
            exit(0);
        }
        curr = curr->next;
    }
    curr->next = t;
    return main;
}

int get_paramlist_length(ParamList* list){
    ParamList* temp = list;
    int a = 0;
    while(temp){
        a++;
        temp = temp->next;
    }
    return a;
}

void display(ParamList* head) {
    ParamList* curr = head;
    while (curr) {
        printf("Name: %s, Type: %d\n", curr->name, curr->type);
        curr = curr->next;
    }
}

void is_paramlist_correct(ParamList* main, ParamList* t){
    ParamList* t1 = main;
    ParamList* t2 = t;
    while(t1){
        if(t2){
            if(strcmp(t1->name,t2->name) != 0 || t1->type != t2->type){
                printf("Error:Incorrect set of arguments for the function\n");
                exit(0);
            }
        }else{
            printf("Error:Too few Arguments for the function\n");
            exit(0);
        }
    }
    if(t2){
        printf("Error:Too many Arguments for the function\n");
        exit(0);
    }
}
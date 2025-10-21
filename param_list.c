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
    node->varType = TYPE_VAR;
    node->next = NULL;
    return node;
}

ParamList* append_param_to_list(ParamList* main, ParamList* t) {
    if (!main) return NULL; // safety check
    ParamList* curr = main;
    while (curr->next) {
        if(strcmp(curr->name,t->name) == 0){
            printf("Error: Variable %s already present as (function argument or in tuple declaration)\n", curr->name);
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

void paramlist_display(ParamList* head) {
    ParamList* curr = head;
    while (curr) {
        printf("Type: %s Name: %s\n", type_to_string(curr->type), curr->name);
        curr = curr->next;
    }
}

void is_paramlist_correct(ParamList* main, ParamList* t){
    ParamList* t1 = main;
    ParamList* t2 = t;
    while(t1){
        if(t2){
            if(t1->typeEntry != t2->typeEntry){
                printf("Error:Incorrect set of arguments for the function->%s-%d and %s-%d\n",t1->name,t1->type,t2->name,t2->type);
                exit(0);
            }
        }else{
            printf("Error:Too few Arguments for the function\n");
            exit(0);
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    if(t2){
        printf("Error:Too many Arguments for the function\n");
        printf("%s\n",t2->name);
        printf("%d-%d\n", get_paramlist_length(main),get_paramlist_length(t));
        exit(0);
    }
}

void paramlist_is_input_args_correct(ParamList* main, tnode* t){
    ParamList* t1 = main;
    tnode* t2 = t;
    int count = 0;
    while(t1){
        if(t2){
            if(t1->type != t2->type ){
                printf("Error:Incorrect set of arguments for the function->%s->%d and %s->%d\n",t1->name,t1->type,t2->varname,t2->type);
                exit(0);
            }
        }else{
            printf("Error:Too few Arguments for the function\n");
            exit(0);
        }
        t1 = t1->next;
        t2 = t2->middle;
    }
    if(t2){
        printf("Error:Too many Arguments for the function\n");
        printf("%s",t2->varname);
        printf("%d-%d\n", get_paramlist_length(main),count+1);
        exit(0);
    }
}

void paramlist_destroy(struct ParamList* head) {
    struct ParamList* curr = head;
    while (curr != NULL) {
        ParamList* next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
    head = NULL;
}

ParamList* paramlist_deepcopy(const ParamList* src) {
    if (!src) return NULL;

    ParamList* head = NULL;
    ParamList* tail = NULL;

    while (src) {
        ParamList* node = malloc(sizeof(ParamList));
        node->name = strdup(src->name);   // duplicate name string
        node->type = src->type;
        node->size = src->size;
        node->typeEntry = src->typeEntry;
        node->varType = src->varType;
        node->next = NULL;

        if (!head)
            head = node;
        else
            tail->next = node;

        tail = node;
        src = src->next;
    }

    return head;
}

int paramlist_get_size(ParamList* plist){
    int ans = 0;
    int count = -1;
    while(plist){
        count++;
        if(plist->varType != TYPE_PTR){
            ans += plist->typeEntry->size;
        }else{
            ans += 1;
        }
        plist = plist->next;
    }
    return ans;
}


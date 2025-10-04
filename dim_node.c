#include "dim_node.h"

DimNode* create_dimlist(DimNode* rest) {
    return NULL; // for scalar
}

int get_pos(DimNode* list,DimNode* main){
    if(!main)return 1;
    DimNode* t = list;
    DimNode* t1 = main;
    int size = get_length(main);
    int tsize = get_length(list);
    if(size != tsize){
        printf("Error: Illegal memory access\n");
        exit(1);
    }
    if(size == 0)return 1;
    int lsize[MAX_DIM_SIZE];
    for(int i=0;i<size;i++){
        lsize[i] = t1->size;
        t1 = t1->next;
    }
    for(int i=size-2;i>=0;i--){
        lsize[i] *= lsize[i+1];
    }
    int a = 0;
    for(int i=1;i<size;i++){
        a += t->size*lsize[i];
        t = t->next;
    }
    a+=t->size;
    return a;
}

int get_size(DimNode* list){
    DimNode* t = list;
    int a = 1;
    while(t){
        a *= t->size;
        t = t->next;
    }
    return a;
}

int get_length(DimNode* list){
    DimNode* t = list;
    int a = 0;
    while(t){
        a++;
        t = t->next;
    }
    return a;
}

DimNode* append_dim(DimNode* list, int size) {
    DimNode* node = malloc(sizeof(DimNode));
    node->size = size;
    node->next = NULL;

    if(list == NULL) return node;

    DimNode* temp = list;
    while(temp->next) temp = temp->next;
    temp->next = node;
    return list;
}

DimNode* append_dim_with_id(DimNode* list, tnode* t) {
    DimNode* node = malloc(sizeof(DimNode));
    node->size = 1;
    node->id = t;
    node->next = NULL;

    if(list == NULL) return node;

    DimNode* temp = list;
    while(temp->next) temp = temp->next;
    temp->next = node;
    return list;
}

Gsymbol* create_symbol_id_with_dims(char* name, DimNode* dims) {
    Gsymbol* g = create_gsymbol_id(name,get_size(dims));
    g->dimlist = dims;
    // calculate total size (product of dims) here
    return g;
}

void check_not_out_of_bounds(DimNode* t, DimNode* main){
    DimNode* t1 = t;
    DimNode* t2 = main;

    int msize = get_length(main);
    int tsize = get_length(t);

    if(msize != tsize){
        printf("Error: Array is of %d-D but bro trying to access %d-D..learn to CODE chigga\n",msize,tsize);
        exit(1);
    }
    while(t1){
        if(!t2 || t1->size >= t2->size){
            printf("Error: Illegal Memory Access as bro is trying to access index %d while maximum possible value is %d\n",t1->size,t2->size-1);
            exit(1);
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    if(t2){
        printf("Error:Syntax Error on array variable\n");
        exit(1);
    }
}

void dimnode_destroy(DimNode* node) {
    if(!node){
        printf("helloooo");    
    }
    while (node) {
        DimNode* next = node->next;

        // free AST node if DimNode owns it
        if (node->id) {
            ast_destroy(node->id);  // only if ownership is here!
        }

        free(node);
        node = next;
    }
}


#ifndef DIM_NODE_H
#define DIM_NODE_H

#include "symbol_table.h"

#define MAX_DIM_SIZE 100

typedef struct tnode tnode;

//THIS DATA STRUCTURE IS THERE FOR MULTI DIMENSIONAL ARRAY AND ALL THE FUNCTIONALITIES ARE FOR CREATING AND ACCESSING THE DATA INSIDE THE MULTI-DIMENSIONAL ARRAY

typedef struct DimNode {
    int size;
    char* name;
    struct tnode* id;
    struct DimNode* next;
} DimNode;

//THIS IS USED TO CREATE A NULL DATA TO JUST RETURN IT(prolly no use but kept it there cause it looks good ":)" )
DimNode* create_dimlist(DimNode* rest);

//THIS APPENDS A NEW ALLOCATED NODE WITH THE SIZE DATA AND APPENDS TO THE LIST
DimNode* append_dim(DimNode* list, int size);

//THIS APPENDS A NEW ALLOCATED NODE WITH THE SIZE DATA AND APPENDS TO THE LIST
DimNode* append_dim_with_id(DimNode* list, tnode* t);

//AFTER APPENDING ALL NODES THIS FUNCTION FINALLY CREATES THE Gsymbol entry REQUIRED FOR THE "GST" (Global Symbol Table)
struct Gsymbol* create_symbol_id_with_dims(char* name, DimNode* dims);


//WHILE ACCESSING THE DATA IT WILL CHECK IF IT ARRAY INDEX ACCESS IS VALID OR NOT
void check_not_out_of_bounds(DimNode* t, DimNode* main);

//RETURNS THE OFFSET FOR DATA ACCESSING
int get_pos(DimNode* list, DimNode* main);

//RETURN THE TOTAL SIZE OF THE GIVE LIST
int get_size(DimNode* list);

//RETURNS THE DIMENSION OF THE LIST (basically length of the given linked list)
int get_length(DimNode* list);


#endif
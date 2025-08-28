#ifndef LABEL_TABLE_H
#define LABEL_TABLE_H

#define MAX_LABELS 1000

typedef struct Label {
    char name[50];
    int address;
}Label;

extern int label_count;

extern struct Label labelTable[MAX_LABELS];

//add label into the labelTable list in the first run
void addLabel(char* name, int addr);

//find the corresponding label address in the second run
int findLabel(const char *name);

//print all the label currently present
void printLabels();


#endif
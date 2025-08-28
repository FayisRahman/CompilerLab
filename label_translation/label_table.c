#include <stdio.h>
#include <string.h>
#include "label_table.h"

int label_count = 0;

struct Label labelTable[MAX_LABELS];

void addLabel(char* name,int addr) {
    size_t len = strlen(name);
    if (name[len - 1] == ':') {
        name[len - 1] = '\0';  // chop off colon
    }
    strcpy(labelTable[label_count].name, name);
    labelTable[label_count].address = addr;
    label_count++;
}


int findLabel(const char *name) {

    for (int i = 0; i < label_count; i++) {
        if (strcmp(labelTable[i].name, name) == 0) {
            return labelTable[i].address;  // Found → return address
        }
    }
    return -1; // Not found
}

void printLabels() {
    if (label_count == 0) {
        printf("No labels found.\n");
        return;
    }

    printf("Label Table:\n");
    printf("-----------------------\n");
    for (int i = 0; i < label_count; i++) {
        printf("%-10s -> %d\n", labelTable[i].name, labelTable[i].address);
    }
    printf("-----------------------\n");
}
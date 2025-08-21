#include <iostream>

int main() {
    FILE *fp = fopen("a.xsm", "w");
    fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fp, "MOV R0, 1\n");
    fprintf(fp, "MOV R1, 2\n");
    fprintf(fp, "MOV R2, 3\n");
    fprintf(fp, "MOV R4, 0\n");
    fprintf(fp, "MOV R5, R0\n");
    fprintf(fp, "GT R5, R1\n");
    fprintf(fp, "JNZ R5, L1\n");
    fprintf(fp, "MOV R5, R1\n");
    fprintf(fp, "GT R5, R2\n");
    fprintf(fp, "JNZ R5, L2\nBRKP\nRET\n");
    fprintf(fp, "L1:\nMOV R5, R0\n");
    return 0;
}
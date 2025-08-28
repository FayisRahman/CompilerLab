
%{
    
    #include <stdio.h>
    #include <unistd.h>
    #include "label_table.h"

    #define MAX_LABELS 1000

    int current_address = 2048;
    FILE* out;
 
%}


%%

L[0-9]+: {
    addLabel(yytext,current_address);
}

L[0-9]+ {
    
    int addr = findLabel(yytext);
    if(addr != -1){
        fprintf(out, "%d", addr);
    }else{
        fprintf(out, "%s", yytext);
    }
}

\n {
    fputs("\n", out);
    if(current_address < 2056)current_address++;
    else current_address += 2;
}

. {
    fputs(yytext, out);
}


%%



int yywrap(){
    return 1;
}

int translate(){
    FILE* fptr = fopen("../a.xsm", "r");
    yyin = fptr;
    if (!yyin) {
        perror("input file");
        return 1;
    }

    out = fopen("temp.xsm", "w");
    if (!out) {
        perror("output file");
        fclose(fptr);
        return 1;
    }

    yylex();

    rewind(out);
    fclose(out);
    fclose(fptr);

    rename("temp.xsm", "../a.xsm");
}

int main() {

    

    translate();
    translate();

    
}
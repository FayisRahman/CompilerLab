%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "exptree.c"

%}


%%

[0-9]+ {
    
    yylval.node = createTree(atoi(yytext), INT, NULL, LEAFNODE, NULL, NULL);
    return NUM;
}

"begin" {
    return begin;
}

"end" {
    return end;
}

"read" {
    yylval.node = createTree(0, NONE, NULL, READNODE, NULL, NULL);
    return READ;
}

"write" {
    yylval.node = createTree(0, NONE, NULL, WRITENODE, NULL, NULL);
    return WRITE;
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.node = createTree(0, INT, yytext, LEAFNODE, NULL, NULL);
    return ID;
}

"+" {
    yylval.node = createTree(0, NONE, yytext, OPERATOR, NULL, NULL);
    return PLUS;
}
"-" {
    yylval.node = createTree(0, NONE, yytext, OPERATOR, NULL, NULL);
    return MINUS;
}
"/" {
    yylval.node = createTree(0, NONE, yytext, OPERATOR, NULL, NULL);
    return DIV;
}
"*" {
    yylval.node = createTree(0, NONE, yytext, OPERATOR, NULL, NULL);
    return MUL;
}
"(" {
    return '(';
}

")" {
    return ')';
}

";" {
    return ';';
}

"=" {
    yylval.node = createTree(0, NONE, yytext, EQUAL, NULL, NULL);
    return '=';
}

[ \t\n]+   { /* skip whitespace */ }

. { /* ignore unrecognized characters */ }

%%

int yywrap() {
    return 1;
}


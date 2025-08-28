%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "AST.h"

%}


%%

[0-9]+ {

    yylval.node = createTree(atoi(yytext), TYPE_INT, NULL, LEAFNODE, NULL, NULL,NULL);
    return NUM;
}

"begin" {return begin;}
"end" {return end;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"int" {return INT;}
"str" {return STR;}

"read" {
    yylval.node = createTree(0, TYPE_NULL, NULL, READNODE, NULL, NULL,NULL);
    return READ;
}

"write" {
    yylval.node = createTree(0, TYPE_NULL, NULL, WRITENODE, NULL, NULL,NULL);
    return WRITE;
}

"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"endwhile" {return ENDWHILE;}
"do" {return DO;}
"repeat" {return REPEAT;}
"until" {return UNTIL;}
"break" {return BREAK;}
"continue" {return CONTINUE;}

[a-zA-Z][a-zA-Z0-9]* {
    
    yylval.node = createTree(atoi(yytext), TYPE_INT, NULL, LEAFNODE, NULL, NULL,NULL);
    return ID;
}

\"[^"\n]*\" {
    yylval.string = (char*)malloc(sizeof(char)*32);
    strcpy(yylval.string,yytext);
    return STRING;
}

"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIV;}
"*" {return MUL;}

"(" {return '(';}
")" {return ')';}
";" {return ';';}
"," {return ',';}

"=" {return '=';}

">=" { return GE; }
"<=" { return LE; }
"==" { return EQ; }
"!=" { return NE; }
">"  { return GT; }
"<"  { return LT; }

[ \t\n]+   { /* skip whitespace */ }

. { /* ignore unrecognized characters */ }

%%

int yywrap() {
    return 1;
}


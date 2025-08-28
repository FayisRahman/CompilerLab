%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "AST.h"

%}


%%

[0-9]+ {
    
    yylval.node = createTree(atoi(yytext), INT, NULL, LEAFNODE, NULL, NULL,NULL);
    return NUM;
}

"begin" {
    return begin;
}

"end" {
    return end;
}

"read" {
    yylval.node = createTree(0, NONE, NULL, READNODE, NULL, NULL,NULL);
    return READ;
}

"write" {
    yylval.node = createTree(0, NONE, NULL, WRITENODE, NULL, NULL,NULL);
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
    yylval.node = createTree(0, INT, yytext, LEAFNODE, NULL, NULL,NULL);
    return ID;
}

"+" {
    return PLUS;
}
"-" {
    return MINUS;
}
"/" {
    return DIV;
}
"*" {
    
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
    
    return '=';
}

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


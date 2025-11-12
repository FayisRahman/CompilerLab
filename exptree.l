%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "AST.h"
    int currLine = 0;

%}


%%

[0-9]+ {

    yylval.node = createTree(atoi(yytext), TYPE_INT, NULL, LEAFNODE, NULL, NULL, NULL,NULL);
    return NUM;
}

"begin" {return begin;}
"end" {return end;}
"main" {return MAIN;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"int" {return INT;}
"str" {return STR;}
"read" {
    yylval.node = createTree(0, TYPE_NULL, NULL, READNODE, NULL, NULL, NULL,NULL);
    return READ;
}
"write" {
    yylval.node = createTree(0, TYPE_NULL, NULL, WRITENODE, NULL, NULL, NULL,NULL);
    return WRITE;
}
"new" {return NEW;}
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
"return" { return RETURN;}
"AND" { return AND;}
"OR" { return OR;}
"breakpoint" { return BREAKPOINT;}
"tuple" { return TUPLE;}
"type" { return TYPE; }
"endtype" { return ENDTYPE;}
"struct" {return STRUCT;}
"free" {return FREE;}
"Free" {return FREE;}
"Alloc" {return ALLOC;}
"alloc" {return ALLOC;}
"initialize" {return INITIALIZE;}
"class" {return CLASS;}
"endclass" {return ENDCLASS;}
"extends" {return EXTENDS;}
"self" {
    yylval.node = createTree(0, TYPE_NULL, strdup(yytext), NULLNODE,NULL, NULL, NULL,NULL);
    return SELF;
}
"delete" {return DELETE;}
(null|NULL|nullptr) {
    yylval.node = createTree(0, TYPE_INT, strdup(yytext), NULLNODE,NULL, NULL, NULL,NULL);
    return NILL;
}



[a-zA-Z][a-zA-Z0-9_]* {
    yylval.node = createTree(0, TYPE_VAR, strdup(yytext), LEAFNODE,NULL, NULL, NULL,NULL);
    return ID;
}

\"[^"\n]*\" {
    size_t len = strlen(yytext);
    yylval.string = malloc(len + 1);
    if (!yylval.string) { perror("malloc"); exit(1); }
    strcpy(yylval.string, yytext);
    return STRING;
}

"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIV;}
"*" {return MUL;}
"%" {return MOD;}

"&" {return '&';}
"(" {return '(';}
")" {return ')';}
"[" {return '[';}
"]" {return ']';}
"{" {return '{';}
"}" {return '}';}
";" {return ';';}
"," {return ',';}
"." {return '.';}
"->" {return ARROW;}

"=" {return '=';}

">=" { return GE; }
"<=" { return LE; }
"==" { return EQ; }
"!=" { return NE; }
">"  { return GT; }
"<"  { return LT; }

[ \t]+   { /* skip whitespace */ }

[\n]+ { /* skip whitespace */ currLine++;
        // printf("%d\n",currLine);
        { yylloc.last_line++; yylloc.first_line++; }
    }

. { /* ignore unrecognized characters */ }

%%

int yywrap() {
    return 1;
}


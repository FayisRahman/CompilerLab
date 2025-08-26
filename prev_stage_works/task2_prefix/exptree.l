%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "exptree.h"
    #include "exptree.c"

%}


%%

[0-9]+ {
    yylval.node = makeLeafNode(atoi(yytext));
    return NUM;
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.node = makeOperatorNode(yytext,NULL,NULL);
    return VARIABLE;
}

"+" {
    yylval.node = makeOperatorNode(yytext,NULL,NULL);
    return PLUS;
}
"-" {
    yylval.node = makeOperatorNode(yytext,NULL,NULL);
    return MINUS;
}
"/" {
    yylval.node = makeOperatorNode(yytext,NULL,NULL);
    return DIV;
}
"*" {
    yylval.node = makeOperatorNode(yytext,NULL,NULL);
    return MUL;
}
"(" {
    return LPAREN;
}

")" {
    return RPAREN;
}
[ \t]+   { /* skip whitespace */ }
\n {
    return NL;
}
. { /* ignore unrecognized characters */ }

%%

int yywrap() {
    return 1;
}


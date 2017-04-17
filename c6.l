%option caseless

%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
char text[500];
%}

%x S

%%

0               {
                    yylval.conValue = (long) atoi(yytext);
                    return INTEGER;
                }

[1-9][0-9]*     {
                    yylval.conValue = (long) atoi(yytext);
                    return INTEGER;
                }

\"              { BEGIN S; *text = 0; }
<S>[^"\\]*      { strcat(text, yytext); }
<S>\"           { strcpy(yylval.conStrValue, text); BEGIN 0; return STRING; }
<S>\\\"         { strcat(text, "\""); }
<S>\\n          { strcat(text, "\n"); }
<S>\\t          { strcat(text, "\t"); }
<S>\\           { strcat(text, "\\"); }

'\\n'           { yylval.conValue = (int) '\n'; return CHAR; }
'\\t'           { yylval.conValue = (int) '\t'; return CHAR; }
'\\''           { yylval.conValue = (int) '\''; return CHAR; }
''              { yylval.conValue = 0; return CHAR; }
'[^']'          { yylval.conValue = (int) yytext[1]; return CHAR; }


[-()<>=+*/;{}.%\[\]]    {
                            return *yytext;
                        }

">="        return GE;
"<="        return LE;
"=="        return EQ;
"!="        return NE;
"for"       return FOR;
"while"     return WHILE;
"if"        return IF;
"else"      return ELSE;
"print"     return PRINT;
"read"      return READ;
"&&"        return AND;
"||"        return OR;
"break"     return BREAK;
"continue"  return CONTINUE;

@?[a-z]+[a-z0-9]*   { 
                        strcpy(yylval.sKey, yytext);
                        return VARIABLE;
                    }

\/\/.*\n	;	/* skip comments */

[ \t\n]+    ;   /* ignore whitespace */

.               yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}

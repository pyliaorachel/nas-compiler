%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
%}

%%

[a-z]       { 
                yylval.sIndex = *yytext - 'a';
                return VARIABLE;
            }

0           {
                yylval.conValue = (long) atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.conValue = (long) atoi(yytext);
                return INTEGER;
            }

'.?'         {
                if (yyleng == 2) yylval.conValue = 0;        // empty char
                else yylval.conValue = (long) yytext[1]; 
                return CHAR;
            }

\".*\"      {
                yytext[yyleng-1] = '\0';
                yylval.conValue = (long) (yytext + 1);
                return STRING;
            }

[-()<>=+*/;{}.%\[\]] {
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

\/\/.*\n	;	/* skip comments */

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}

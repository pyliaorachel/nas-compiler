%option caseless

%{
#include <ctype.h>
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
char text[CONST_STRING_L];
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
'\\0'           { yylval.conValue = 0; return INTEGER; }
''              { yylval.conValue = 0; return CHAR; }
'[^']'          { yylval.conValue = (int) yytext[1]; return CHAR; }


">="        return GE;
"<="        return LE;
"=="        return EQ;
"!="        return NE;
"<<<"       return SLA;
">>>"       return SRA;
"for"       return FOR;
"while"     return WHILE;
"if"        return IF;
"else"      return ELSE;
"geti"      return GETI;
"gets"      return GETS;
"getc"      return GETC;
"puti"      return PUTI;
"puts"      return PUTS;
"putc"      return PUTC;
"puti_"     return PUTI_;
"puts_"     return PUTS_;
"putc_"     return PUTC_;
"&&"        return AND;
"||"        return OR;
"break"     return BREAK;
"continue"  return CONTINUE;
"return"    return RETURN;
"array"    	return DECL_ARRAY;
"struct"    return DEF_STRUCT_TYPE;

[-()<>=+*/;{}.%\[\],&^|]   {
                            return *yytext;
                        }

^[ \t\n]*[a-z]+[a-z0-9]*    { 
                                // remove leading zeros
                                int i = 0;
                                while (isspace(yytext[i])) i++;

                                // lowercase
                                char* p = yytext + i;
                                for ( ; *p; ++p) *p = tolower(*p);

                                strcpy(yylval.sKey, yytext+i);
                                return DECL_VARIABLE;
                            }

@?[a-z]+[a-z0-9]*           { 
                                // lowercase
                                char* p = yytext;
                                for ( ; *p; ++p) *p = tolower(*p);

                                strcpy(yylval.sKey, yytext);
                                return VARIABLE;
                            }

\/\/.*(\n)+	; /* skip comments */

[ \t\n]+    ; /* ignore whitespace */

.               yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}

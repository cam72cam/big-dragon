%{
#include <stdio.h>
#include "y.tab.h"
#define MAX_IDENT 40
%}

%%


[0-9]+		{ yylval = make_tree(NUM, NULL, NULL); yylval->attribute.ival = atof(yytext); return NUM; }

\(			return RPAREN;
\)			return LPAREN;

[+]			return ADDOP;
[-]			return SUBOP;
[*]			return MULOP;
[;]			return ENDSTMT;

[=]			return ASSIGNOP;
[>]			return PRINTOP;

[program]	return PROGRAM;
[var]		return VAR;
[function]	return FUNCTION;
[procedure]	return PROCEDURE;
[begin]		return BEGIN;
[end]		return END;
[array]		return ARRAY;
[..]		return ARRAY_SEPERATOR;
[of]		return ARRAY_TYPE;

[if]		return IF;
[then]		return THEN;
[else]		return ELSE;

[while]		return WHILE;
[do]		return DO;


 // types:
[integer]	return INTEGER;
[real]		return REAL;

[.]			return PERIOD;
[,]			return COMMA;

[a-zA-Z]+	{ 
				yylval = make_tree(IDENT, NULL, NULL);
				yylval->attribute.sval = malloc(sizeof(char) * (strnlen(yytext, MAX_IDENT) + 1));
				strncpy(yylval->attribute.sval, yytext, strnlen(yytext, MAX_IDENT)); return IDENT;
			}


\n                      /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;
%%



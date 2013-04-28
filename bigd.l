%{
#include <stdio.h>
#include "y.tab.h"
#define MAX_IDENT 40
%}



/* regular expressions */

letter		[a-zA-Z]
word		{letter}+
digit		[0-9]
int 		{digit}+

%%

 /* tokens */

{int}+		{ yylval = make_tree(INTEGER, NULL, NULL); yylval->attribute.ival = atof(yytext); return INTEGER; }

[(]			fprintf(stderr, "rparen"); return RPAREN;
[)]			return LPAREN;

[+]			return ADDOP;
[-]			return SUBOP;

[*]			return MULOP;
[;]			return ENDSTMT;

[=]			return ASSIGNOP;

program		return PROGRAM;
var			return VAR;
function	return FUNCTION;
procedure	return PROCEDURE;
begin		return BEGIN_SEC;
end			return END_SEC;
array		return ARRAY;
\.\.		return ARRAY_SEPERATOR;
of			return ARRAY_TYPE;

if			return IF;
then		return THEN;
else		return ELSE;

while		return WHILE;
do			return DO;

integer		return INTEGER;
real		return REAL;

[.]			return PERIOD;
[,]			return COMMA;

{word}	{
			yylval = make_tree(IDENTIFIER, NULL, NULL);
			yylval->attribute.sval = malloc(sizeof(char) * (strnlen(yytext, MAX_IDENT) + 1));
			strncpy(yylval->attribute.sval, yytext, strnlen(yytext, MAX_IDENT));
			return IDENTIFIER;
		}


[\n]			/* ignore end of line */;
[ \t]+		/* ignore whitespace */;
%%



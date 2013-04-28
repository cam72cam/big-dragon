%{
#include <stdio.h>
#include "y.tab.h"
#define MAX_IDENT 40
%}



/* regular expressions */

letter		[a-zA-Z]
digit		[0-9]
ident		{letter}({letter}|{digit})*
int 		{digit}+

relop		[=|<>|<|<=|>|>=]
mulop		[*|/]|div|mod|and
sign		[+|-]
addop		[{sign}|or]

colon		[:]
assignop	{colon}=

%%

 /* tokens */

{int}+		{ yylval = make_tree(INTEGER, NULL, NULL); yylval->attribute.ival = atof(yytext); return INTEGER; }

[(]			return RPAREN;
[)]			return LPAREN;

{relop}		return RELOP;
{mulop}		return MULOP;
{sign}		return SIGN;
{addop}		return ADDOP;

[;]			return ENDSTMT;
{colon}		return COLON;
{assignop}	return ASSIGNOP;


program		return PROGRAM;
var			return VAR;
function	return FUNCTION;
procedure	return PROCEDURE;
begin		return BEGIN_SEC;
end			return END_SEC;

array		return ARRAY;
\[			return ARRAY_START;
\.\.		return ARRAY_SEPERATOR;
\]			return ARRAY_END;
of			return ARRAY_TYPE;

if			return IF;
then		return THEN;
else		return ELSE;

while		return WHILE;
do			return DO;

not			return NOT;

integer		return INTEGER_TYPE;
real		return REAL_TYPE;

[.]			return PERIOD;
[,]			return COMMA;

{ident}	{
			yylval = make_tree(IDENTIFIER, NULL, NULL);
			yylval->attribute.sval = malloc(sizeof(char) * (strnlen(yytext, MAX_IDENT) + 1));
			strncpy(yylval->attribute.sval, yytext, strnlen(yytext, MAX_IDENT));
			return IDENTIFIER;
		}


[\n]			/* ignore end of line */;
[ \t]+		/* ignore whitespace */;
%%



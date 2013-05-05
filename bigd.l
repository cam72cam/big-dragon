%{
#include "y.tab.h"
#include "scope.h"
#include "syntax_tree/tree.h"

int line_number;
%}



/* regular expressions */

letter		[a-zA-Z]
digit		[0-9]
ident		{letter}({letter}|{digit})*
int 		{digit}+

relop		[=|<>|<]|<=|>|>=
mulop		[*|/]|div|mod|and
sign		[+|-]
addop		{sign}|or

colon		[:]
assignop	{colon}=

%%

 /* tokens */

{int}+	{
				yylval = make_integer(atoi(yytext));
				return INTEGER;
		}

[(]				return RPAREN;
[)]				return LPAREN;

{relop}	{
				yylval = make_relop(yytext);
				return RELOP;
		}
{mulop}	{
				yylval = make_mulop(yytext);
				return MULOP;
		}
{sign}	{
				yylval = make_addop(yytext);
				return SIGN;
		}
{addop}	{
				yylval = make_addop(yytext);
				return SIGN;
		}
[;]				return ENDSTMT;
{colon}			return COLON;
{assignop}		return ASSIGNOP;


program			return PROGRAM;
var				return VAR;
function		return FUNCTION;
procedure		return PROCEDURE;
begin			return BEGIN_SEC;
end				return END_SEC;

array			return ARRAY;
\[				return ARRAY_START;
\.\.			return ARRAY_SEPERATOR;
\]				return ARRAY_END;
of				return ARRAY_TYPE;

if				return IF;
then			return THEN;
else			return ELSE;

while			return WHILE;
do				return DO;

not				return NOT;

integer			return INTEGER_TYPE;
real			return REAL_TYPE;

[.]				return PERIOD;
[,]				return COMMA;

{ident}	{
				yylval = make_identifier(yytext);
				return IDENTIFIER;
		}


[\n]			{line_number++;}/* ignore end of line */;
[ \t]+			/* ignore whitespace */;
%%



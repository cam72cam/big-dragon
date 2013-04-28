%code requires
{
#include "tree.h"
}

%{
#include <stdio.h>
#include <string.h>
#define YYSTYPE tree_t*

void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
}

main()
{
	yyparse();
} 

%}

%token RPAREN LPAREN ADDOP SUBOP MULOP ASSIGNOP IDENTIFIER ENDSTMT 
%token PROGRAM VAR FUNCTION PROCEDURE BEGIN_SEC END_SEC COLON
%token ARRAY ARRAY_SEPERATOR ARRAY_TYPE ARRAY_START ARRAY_END
%token IF THEN ELSE WHILE DO
%token INTEGER REAL
%token PERIOD COMMA
%token INTEGER_TYPE REAL_TYPE

%%

program:
	PROGRAM IDENTIFIER 
	RPAREN identifier_list LPAREN ENDSTMT
	declarations
	PERIOD 
	{
		printf("AWESOME"); 
	}
	;

identifier_list:
	IDENTIFIER | IDENTIFIER COMMA identifier_list   { }
	;

declarations:
	/* empty */ | VAR identifier_list COLON type ENDSTMT declarations {}
	;
type:
	standard_type | ARRAY ARRAY_START ARRAY_SEPERATOR ARRAY_END ARRAY_TYPE standard_type {}
	;
standard_type:
	INTEGER_TYPE | REAL_TYPE {};
	;

/*
commands:
	/*empty*//* | commands command ENDSTMT { printf("=========================================\n"); }
	;
command:
	print | expr | stmt;

print:
	 PRINTOP expr { print_tree($2, 0); }
stmt:
	IDENT ASSIGNOP expr { $$ = $1; $$ -> left = $3; print_tree($$, 0); }
	;
expr:
	term expr_
	{
		if($2 == NULL) {
			$$ = $1;
		} else {
			$$=$2;
			$$->left = $1;
		}
	}
	;
expr_:
	/*empty*//*{ $$ = NULL; }
	|
	ADDOP term expr_
	{
		if($3 == NULL) {
			$$ = make_tree(ADDOP, NULL, $2);
		} else {
			$3 -> left = $2;
			$$ = make_tree(ADDOP, NULL, $3);
		}
	}
	|
	SUBOP term expr_
	{
		if($3 == NULL) {
			$$ = make_tree(SUBOP, NULL, $2);
		} else {
			$3 -> left = $2;
			$$ = make_tree(SUBOP, NULL, $3);
		}
	}
	;
term:
	factor term_
	{
		if($2 == NULL) {
			$$ = $1;
		} else {
			$2 -> left = $1;
			$$ = $2;
		}
	}
	;
term_:
	/*empty*//* { $$=NULL; }
	|
	MULOP term
	{
		$$=make_tree(MULOP, NULL, $2);
	}
	;
factor:
	RPAREN expr LPAREN { $$=$2; }
	|
	NUM { $$=$1; }
	|
	IDENT { $$=$1; }
	;
*/
%%

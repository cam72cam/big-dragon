%code requires
{
#include "syntax_tree/tree.h"
}

%{
#include <stdio.h>
#include <string.h>
#include "syntax_tree/tree.h"
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

%token RPAREN LPAREN ASSIGNOP IDENTIFIER ENDSTMT 
%token PROGRAM VAR FUNCTION PROCEDURE BEGIN_SEC END_SEC COLON
%token ARRAY ARRAY_SEPERATOR ARRAY_TYPE ARRAY_START ARRAY_END
%token IF THEN ELSE WHILE DO
%token INTEGER REAL
%token PERIOD COMMA
%token INTEGER_TYPE REAL_TYPE
%token ADDOP MULOP RELOP SIGN
%token NOT

%%

program:
	PROGRAM IDENTIFIER 
	RPAREN identifier_list LPAREN ENDSTMT
	declarations
	subprogram_declarations
	compound_statement
	PERIOD 
	{
		$$ = make_program(IDENTIFIER_N($2), IDENTIFIER_LIST_N($4), DECLARATIONS_N($7));
		print_program(PROGRAM_N($$), 4);
	}
	;

identifier_list:
	IDENTIFIER 
	{
		$$ = make_identifier_list(IDENTIFIER_N($1), NULL);
	}
	| IDENTIFIER COMMA identifier_list   
	{
		$$ = make_identifier_list(IDENTIFIER_N($1), IDENTIFIER_LIST_N($3));
	}
	;

declarations:
	/* empty */ 
	{
		$$ = make_declarations(NULL,NULL,NULL);
	} 
	| VAR identifier_list COLON type ENDSTMT declarations 
	{
		$$ = make_declarations(IDENTIFIER_LIST_N($2), TYPE_N($4), DECLARATIONS_N($6));
	}
	;
type:
	standard_type
	{
		$$ = $1;
	}
	| ARRAY ARRAY_START ARRAY_SEPERATOR ARRAY_END ARRAY_TYPE standard_type {}
	;
standard_type:
	INTEGER_TYPE
	{
		$$ = make_type(INTEGER_TYPE);
	} 
	| REAL_TYPE 
	{
		$$ = make_type(REAL_TYPE);
	}
	;

subprogram_declarations: 
	/* empty */ | subprogram_declarations subprogram_declaration ENDSTMT {}
	;
subprogram_declaration:
	subprogram_head declarations compound_statement {}
	;
subprogram_head:
	FUNCTION IDENTIFIER arguments COLON standard_type ENDSTMT {}
	;
arguments:
	/* empty */ | RPAREN parameter_list LPAREN {}
	;
parameter_list:
	identifier_list COLON type | parameter_list ENDSTMT identifier_list COLON type
compound_statement:
	BEGIN_SEC optional_statements END_SEC
	;
optional_statements:
	/* empty */ | statement_list
	;
statement_list:
	statement | statement_list ENDSTMT statement
	;
statement:
	variable ASSIGNOP expression |
	procedure_statement |
	compound_statement |
	IF expression THEN statement elsey |
	WHILE expression DO statement
	;
elsey:
	/*empty*/ | ELSE statement
	;
variable:
	IDENTIFIER | IDENTIFIER ARRAY_START expression ARRAY_END
	;
procedure_statement:
	IDENTIFIER | IDENTIFIER RPAREN expression_list LPAREN {	}
	;
expression_list:
	expression | expression_list COMMA expression
	;
expression:
	simple_expression | simple_expression RELOP simple_expression
	;
simple_expression:
	term | SIGN term | simple_expression ADDOP term
	;
term:
	factor | term MULOP factor
	;
factor:
	IDENTIFIER 
	| IDENTIFIER RPAREN expression_list LPAREN
	| INTEGER
	| RPAREN expression LPAREN
	| NOT factor
	;
%%

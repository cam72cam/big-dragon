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

int main()
{
	yyparse();
	return 0;
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
		$$ = make_program(IDENTIFIER_N($2), IDENTIFIER_LIST_N($4), DECLARATIONS_N($7), SUBPROGRAM_DECLARATIONS_N($8), STATEMENT_LIST_N($9));
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
	/* empty */
	{
		$$ = make_subprogram_declarations(NULL,NULL);
	}
	| subprogram_declarations subprogram_declaration ENDSTMT 
	{
		$$ = make_subprogram_declarations(SUBPROGRAM_DECLARATION_N($2), SUBPROGRAM_DECLARATIONS_N($1));
	}
	;
subprogram_declaration:
	subprogram_head declarations compound_statement 
	{
		$$ = make_subprogram_declaration(SUBPROGRAM_HEAD_N($1), DECLARATIONS_N($2), STATEMENT_LIST_N($3));
	}
	;
subprogram_head:
	FUNCTION IDENTIFIER arguments COLON standard_type ENDSTMT 
	{
		$$ = make_subprogram_head(IDENTIFIER_N($2), PARAMETER_LIST_N($3), TYPE_N($5));
	}
	;
arguments:
	/* empty */ 
	{
		$$ = make_parameter_list(NULL, NULL, NULL);
	}
	| RPAREN parameter_list LPAREN 
	{
		$$ = $2;
	}
	;
parameter_list:
	identifier_list COLON type
	{
		print_identifier_list(IDENTIFIER_LIST_N($1), 0);
		$$ = make_parameter_list(IDENTIFIER_LIST_N($1), TYPE_N($3), NULL);
	}
	| parameter_list ENDSTMT identifier_list COLON type
	{
		$$ = make_parameter_list(IDENTIFIER_LIST_N($3), TYPE_N($5), PARAMETER_LIST_N($1));
	}
	;
compound_statement: //statement_list
	BEGIN_SEC optional_statements END_SEC
	{
		$$ = $2;
	}
	;
optional_statements: //statement_list
	/* empty */
	{
		$$ = make_statement_list(NULL, NULL);
	}
	| statement_list
	{
		$$ = $1;
	}
	;
statement_list:
	statement 
	{
		$$ = make_statement_list(STATEMENT_N($1), NULL);
	}
	| statement ENDSTMT statement_list
	{
		$$ = make_statement_list(STATEMENT_N($1), STATEMENT_LIST_N($3));
	}
	;
statement:
	variable ASSIGNOP expression 
	{
		
		$$ = make_statement(make_assignment(VARIABLE_N($1), EXPRESSION_N($3)));
	}
	| procedure_statement 
	{
		$$ = make_statement($1);
	}
	| compound_statement 
	{
		$$ = make_statement($1);
	}
	| IF expression THEN statement elsey
	{
		$$ = make_statement(make_if(EXPRESSION_N($2), STATEMENT_N($4))); //TODO
	}
	| WHILE expression DO statement
	{
		$$ = make_statement(make_while(EXPRESSION_N($2), STATEMENT_N($4)));
	}
	;
elsey:
	/*empty*/ | ELSE statement
	;
variable:
	IDENTIFIER 
	{
		$$ = make_variable(IDENTIFIER_N($1), NULL);
	}
	| IDENTIFIER ARRAY_START expression ARRAY_END
	{
		$$ = make_variable(IDENTIFIER_N($1), EXPRESSION_N($3));
	}
	;
procedure_statement:
	IDENTIFIER 
	{
		$$ = make_procedure_statement(IDENTIFIER_N($1), NULL);
	}
	| IDENTIFIER RPAREN expression_list LPAREN 
	{
		$$ = make_procedure_statement(IDENTIFIER_N($1), EXPRESSION_LIST_N($3));
	}
	;
expression_list:
	expression
	{
		$$ = make_expression_list(EXPRESSION_N($1), NULL);
	}
	| expression_list COMMA expression
	{
		$$ = make_expression_list(EXPRESSION_N($3), EXPRESSION_LIST_N($1));
	}
	;
expression:
	simple_expression
	{
		$$ = make_expression(SIMPLE_EXPRESSION_N($1), NULL, NULL);
	}
	| simple_expression RELOP simple_expression
	{
		$$ = make_expression(SIMPLE_EXPRESSION_N($1),RELOP_N($2),SIMPLE_EXPRESSION_N($3));
	}
	;
simple_expression:
	term
	{
		$$ = make_simple_expression(NULL,NULL,TERM_N($1));
	}
	| SIGN term
	{
		$$ = make_simple_expression(NULL,ADDOP_N($1),TERM_N($2));
	}
	| simple_expression ADDOP term
	{
		$$ = make_simple_expression(SIMPLE_EXPRESSION_N($1),ADDOP_N($2),TERM_N($3));
	}
	;
term:
	factor
	{
		$$ = make_term(NULL, NULL, FACTOR_N($1));
	}
	| term MULOP factor
	{
		$$ = make_term(TERM_N($1), MULOP_N($2), FACTOR_N($3));
	}
	;
factor:
	IDENTIFIER
	{
		$$ = make_factor($1);
	}
	| IDENTIFIER RPAREN expression_list LPAREN
	{
		$$ = make_factor(PROCEDURE_STATEMENT_N(make_procedure_statement(IDENTIFIER_N($1), EXPRESSION_LIST_N($3))));
	}
	| INTEGER
	{
		$$ = make_factor($1);
	}
	| RPAREN expression LPAREN
	{
		$$ = make_factor($1);
	}
	| NOT factor
	{
		$$ = $1;
		factor_t * factor = FACTOR_N($$);
		factor->not = true;
	}
	;
	
%%

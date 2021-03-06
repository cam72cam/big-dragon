%code requires
{
#include "syntax_tree/tree.h"
}

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scope.h"
#include "syntax_tree/tree.h"
#include <stdio.h>
extern FILE* yyin;
#define YYSTYPE tree_t*

extern line_number;

void yyerror(const char *str)
{
        fprintf(stderr, "Error at line %d: %s\n", line_number ,str);
        exit(-1);
}
 
int yywrap()
{
        return 1;
}

tree_t * main_fn;

int main(int argc, char ** argv)
{

	 if(argc >= 2)
     {
         yyin = fopen(argv[1], "r");
         if(!yyin)
         {
             fprintf(stderr, "can't read file %s\n", argv[1]);
             return 1;
         }
     }


	fprintf(stderr, ".text\n");
    fprintf(stderr, ".align 4\n");
    fprintf(stderr, ".globl main\n");



	line_number = 1;

	identifier_t * tmp;
	push_scope("global");
	push_scope("read");
		tmp = IDENTIFIER_N(make_identifier("variable"));
		tmp->type = TYPE_N(make_type(INTEGER_TYPE));
		register_identifier(tmp, true);
	pop_scope();
	push_scope("writeln");
		tmp = IDENTIFIER_N(make_identifier("variable"));
		tmp->type = TYPE_N(make_type(INTEGER_TYPE));
		register_identifier(tmp, true);
	pop_scope();
	yyparse();
	
	
	fprintf(stderr, "writeln:\n");
	fprintf(stderr, "ret\n");
	fprintf(stderr, "read:\n");
	fprintf(stderr, "ret\n");
	if(argc == 3 && 0 == strcmp("--tree", argv[2])) {
		print_program(PROGRAM_N(main_fn), 4);
	}
	
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
	{
		identifier_t * ident = IDENTIFIER_N($2);
		push_scope(ident->ident);
	}
	RPAREN identifier_list LPAREN ENDSTMT
	declarations
	subprogram_declarations
	compound_statement
	PERIOD 
	{
		$$ = make_program(IDENTIFIER_N($2), IDENTIFIER_LIST_N($5), DECLARATIONS_N($8), SUBPROGRAM_DECLARATIONS_N($9), STATEMENT_LIST_N($10));
		main_fn = $$;
		gencode_program(PROGRAM_N($$));
		
	
		if(find_identifier("main") == NULL) {
			fprintf(stderr, "main:\n");
			fprintf(stderr, "call %s", IDENTIFIER_N($2)->ident);
			fprintf(stderr, "ret\n");
		}
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
		scope_add_declarations(DECLARATIONS_N($$));
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
	|  subprogram_declaration ENDSTMT subprogram_declarations
	{
		$$ = make_subprogram_declarations(SUBPROGRAM_DECLARATION_N($1), SUBPROGRAM_DECLARATIONS_N($3));
	}
	;
subprogram_declaration:
	subprogram_head declarations compound_statement 
	{
		$$ = make_subprogram_declaration(SUBPROGRAM_HEAD_N($1), DECLARATIONS_N($2), STATEMENT_LIST_N($3));
		gencode_subprogram_declaration(SUBPROGRAM_DECLARATION_N($$));
		pop_scope();
	}
	;
subprogram_head:
	FUNCTION IDENTIFIER {
		push_scope(IDENTIFIER_N($2)->ident);
	} arguments COLON standard_type ENDSTMT 
	{
		$$ = make_subprogram_head(IDENTIFIER_N($2), PARAMETER_LIST_N($4), TYPE_N($6));
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
		$$ = make_parameter_list(IDENTIFIER_LIST_N($1), TYPE_N($3), NULL);
		set_identifier_list_type(IDENTIFIER_LIST_N($1), TYPE_N($3));
		scope_add_parameter_list(PARAMETER_LIST_N($$));
	}
	| parameter_list ENDSTMT identifier_list COLON type
	{
		$$ = make_parameter_list(IDENTIFIER_LIST_N($3), TYPE_N($5), PARAMETER_LIST_N($1));
		set_identifier_list_type(IDENTIFIER_LIST_N($3), TYPE_N($5));
		scope_add_parameter_list(PARAMETER_LIST_N($$));
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
	| if
	{
		$$ = $1;
	}
	| WHILE expression DO statement
	{
		$$ = make_statement(make_while(EXPRESSION_N($2), STATEMENT_N($4)));
	}
	;
if:
	IF expression THEN statement else
	{
		$$ = make_statement(make_if(EXPRESSION_N($2), STATEMENT_N($4), ELSE_N($5)));
	}
	;
else:
	/*empty*/ 
	{
		$$ = make_else(NULL);
	}
	| ELSE statement 
	{
		$$ = make_else($2);
	}
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
	IDENTIFIER RPAREN expression_list LPAREN 
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
	procedure_statement
	{
		$$ = make_factor($1);
	}
	| IDENTIFIER
	{
		$$ = make_factor($1);
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

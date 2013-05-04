#ifndef TREE_H
#define TREE_H

#define SP_INDENT 4

#include <stdio.h>
#include <stdbool.h>

typedef struct tree_s tree_t;

typedef enum {
	PROGRAM_T,					//0
	IDENTIFIER_T,
	IDENTIFIER_LIST_T,
	TYPE_T,
	DECLARATIONS_T,
	FACTOR_T,					//5
	EXPRESSION_T,
	EXPRESSION_LIST_T,
	SIMPLE_EXPRESSION_T,
	TERM_T,
	RELOP_T,					//10
	ADDOP_T,
	MULOP_T,
	PROCEDURE_STATEMENT_T,
	SUBPROGRAM_HEAD_T,
	SUBPROGRAM_DECLARATION_T,	//15
	SUBPROGRAM_DECLARATIONS_T,
	PARAMETER_LIST_T,
	STATEMENT_LIST_T,
	STATEMENT_T,
	VARIABLE_T,					//20
	ASSIGNMENT_T,
	IF_T,
	ELSE_T,
	WHILE_T,
	INTEGER_T,					//25
	
} tree_types;

#include "integer.h"
#include "relop.h"
#include "addop.h"
#include "mulop.h"
#include "types.h"
#include "identifier.h"
#include "identifier_list.h"
#include "declarations.h"
#include "factor.h"
#include "term.h"
#include "simple_expression.h"
#include "expression.h"
#include "expression_list.h"
#include "procedure_statement.h"
#include "statement.h"
#include "statement_list.h"
#include "parameter_list.h"
#include "variable.h"
#include "assignment.h"
#include "if.h"
#include "else.h"
#include "while.h"
#include "subprogram_head.h"
#include "subprogram_declaration.h"
#include "subprogram_declarations.h"
#include "program.h"

#define CAST_TREE(x, x_type, I_T) ((x_type*) (x->type == I_T ? x->node : (tree_error(x, I_T), NULL)))

#define PROGRAM_N(x)				CAST_TREE(x, program_t, PROGRAM_T)
#define INTEGER_N(x)				CAST_TREE(x, integer_t, INTEGER_T)
#define IDENTIFIER_N(x)				CAST_TREE(x, identifier_t, IDENTIFIER_T)
#define IDENTIFIER_LIST_N(x)		CAST_TREE(x, identifier_list_t, IDENTIFIER_LIST_T)
#define TYPE_N(x)					CAST_TREE(x, type_t, TYPE_T)
#define DECLARATIONS_N(x)			CAST_TREE(x, declarations_t, DECLARATIONS_T)
#define FACTOR_N(x)					CAST_TREE(x, factor_t, FACTOR_T)
#define EXPRESSION_N(x)				CAST_TREE(x, expression_t, EXPRESSION_T)
#define EXPRESSION_LIST_N(x)		CAST_TREE(x, expression_list_t, EXPRESSION_LIST_T)
#define RELOP_N(x)					CAST_TREE(x, relop_t, RELOP_T)
#define ADDOP_N(x)					CAST_TREE(x, addop_t, ADDOP_T)
#define MULOP_N(x)					CAST_TREE(x, mulop_t, MULOP_T)
#define SIMPLE_EXPRESSION_N(x)		CAST_TREE(x, simple_expression_t, SIMPLE_EXPRESSION_T)
#define TERM_N(x)					CAST_TREE(x, term_t, TERM_T)
#define VARIABLE_N(x)				CAST_TREE(x, variable_t, VARIABLE_T)
#define ASSIGNMENT_N(x)				CAST_TREE(x, assignment_t, ASSIGNMENT_T)
#define IF_N(x)						CAST_TREE(x, if_t, IF_T)
#define ELSE_N(x)					CAST_TREE(x, else_t, ELSE_T)
#define WHILE_N(x)					CAST_TREE(x, while_t, WHILE_T)
#define PARAMETER_LIST_N(x)			CAST_TREE(x, parameter_list_t, PARAMETER_LIST_T)
#define STATEMENT_LIST_N(x)			CAST_TREE(x, statement_list_t, STATEMENT_LIST_T)
#define STATEMENT_N(x)				CAST_TREE(x, statement_t, STATEMENT_T)
#define PROCEDURE_STATEMENT_N(x)	CAST_TREE(x, procedure_statement_t, PROCEDURE_STATEMENT_T)
#define SUBPROGRAM_HEAD_N(x)		CAST_TREE(x, subprogram_head_t, SUBPROGRAM_HEAD_T)
#define SUBPROGRAM_DECLARATION_N(x)	CAST_TREE(x, subprogram_declaration_t, SUBPROGRAM_DECLARATION_T)
#define SUBPROGRAM_DECLARATIONS_N(x)CAST_TREE(x, subprogram_declarations_t, SUBPROGRAM_DECLARATIONS_T)

typedef struct tree_s {
	int type;
	void * node;
} tree_t;

tree_t * make_tree(void * node, tree_types type);
void tree_error(tree_t * given, tree_types expected);
void print_spaces(int spaces);

#endif

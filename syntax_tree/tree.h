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

#define PROGRAM_N(x)				x->type == PROGRAM_T				? ((program_t*)x->node)				: (tree_error(x, PROGRAM_T   ),			NULL)
#define INTEGER_N(x)				x->type == INTEGER_T				? ((integer_t*)x->node)				: (tree_error(x, INTEGER_T   ),			NULL)
#define IDENTIFIER_N(x)				x->type == IDENTIFIER_T				? ((identifier_t*)x->node)			: (tree_error(x, IDENTIFIER_T),			NULL)
#define IDENTIFIER_LIST_N(x)		x->type == IDENTIFIER_LIST_T		? ((identifier_list_t*)x->node)		: (tree_error(x, IDENTIFIER_LIST_T),	NULL)
#define TYPE_N(x)					x->type == TYPE_T					? ((type_t*)x->node)				: (tree_error(x, TYPE_T),				NULL)
#define DECLARATIONS_N(x)			x->type == DECLARATIONS_T			? ((declarations_t*)x->node)		: (tree_error(x, DECLARATIONS_T),		NULL)
#define FACTOR_N(x)					x->type == FACTOR_T					? ((factor_t*)x->node)				: (tree_error(x, FACTOR_T),				NULL)
#define EXPRESSION_N(x)				x->type == EXPRESSION_T				? ((expression_t*)x->node)			: (tree_error(x, EXPRESSION_T),			NULL)
#define EXPRESSION_LIST_N(x)		x->type == EXPRESSION_LIST_T		? ((expression_list_t*)x->node)		: (tree_error(x, EXPRESSION_LIST_T),	NULL)
#define RELOP_N(x)					x->type == RELOP_T					? ((relop_t*)x->node)				: (tree_error(x, RELOP_T),				NULL)
#define ADDOP_N(x)					x->type == ADDOP_T					? ((addop_t*)x->node)				: (tree_error(x, ADDOP_T),				NULL)
#define MULOP_N(x)					x->type == MULOP_T					? ((mulop_t*)x->node)				: (tree_error(x, MULOP_T),				NULL)
#define FACTOR_N(x)					x->type == FACTOR_T					? ((factor_t*)x->node)				: (tree_error(x, FACTOR_T),				NULL)
#define SIMPLE_EXPRESSION_N(x)		x->type == SIMPLE_EXPRESSION_T		? ((simple_expression_t*)x->node)	: (tree_error(x, SIMPLE_EXPRESSION_T),	NULL)
#define TERM_N(x)					x->type == TERM_T					? ((term_t*)x->node)				: (tree_error(x, TERM_T),				NULL)
#define VARIABLE_N(x)				x->type == VARIABLE_T				? ((variable_t*)x->node)			: (tree_error(x, VARIABLE_T),			NULL)
#define ASSIGNMENT_N(x)				x->type == ASSIGNMENT_T				? ((assignment_t*)x->node)			: (tree_error(x, ASSIGNMENT_T),			NULL)
#define IF_N(x)						x->type == IF_T						? ((if_t*)x->node)					: (tree_error(x, IF_T),					NULL)
#define ELSE_N(x)					x->type == ELSE_T					? ((else_t*)x->node)				: (tree_error(x, ELSE_T),				NULL)
#define WHILE_N(x)					x->type == WHILE_T					? ((while_t*)x->node)				: (tree_error(x, WHILE_T),				NULL)
#define PARAMETER_LIST_N(x)			x->type == PARAMETER_LIST_T			? ((parameter_list_t*)x->node)		: (tree_error(x, PARAMETER_LIST_T),		NULL)
#define STATEMENT_LIST_N(x)			x->type == STATEMENT_LIST_T			? ((statement_list_t*)x->node)		: (tree_error(x, STATEMENT_LIST_T),		NULL)
#define STATEMENT_N(x)				x->type == STATEMENT_T				? ((statement_t*)x->node)			: (tree_error(x, STATEMENT_T),			NULL)
#define PROCEDURE_STATEMENT_N(x)	((procedure_statement_t*) (x->type == PROCEDURE_STATEMENT_T	? x->node	: (tree_error(x, PROCEDURE_STATEMENT_T),NULL)))
#define SUBPROGRAM_HEAD_N(x)		x->type == SUBPROGRAM_HEAD_T		? ((subprogram_head_t*)x->node)		: (tree_error(x, SUBPROGRAM_HEAD_T),	NULL)
#define SUBPROGRAM_DECLARATION_N(x)	x->type == SUBPROGRAM_DECLARATION_T	? ((procedure_statement_t*)x->node)	: (tree_error(x, SUBPROGRAM_DECLARATION_T),NULL)
#define SUBPROGRAM_DECLARATIONS_N(x)x->type == SUBPROGRAM_DECLARATIONS_T? ((procedure_statement_t*)x->node)	: (tree_error(x, SUBPROGRAM_DECLARATIONS_T),NULL)

typedef struct tree_s {
	int type;
	void * node;
} tree_t;

tree_t * make_tree(void * node, tree_types type);
void tree_error(tree_t * given, tree_types expected);
void print_spaces(int spaces);

#endif

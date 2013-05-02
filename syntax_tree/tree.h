#ifndef TREE_H
#define TREE_H

#define SP_INDENT 4

#include <stdio.h>
#include <stdbool.h>

typedef struct tree_s tree_t;

typedef enum {
	PROGRAM_T,			//0
	IDENTIFIER_T,
	IDENTIFIER_LIST_T,
	TYPE_T,
	DECLARATIONS_T,
	FACTOR_T,			//5
	EXPRESSION_T,
	EXPRESSION_LIST_T,
	SIMPLE_EXPRESSION_T,
	TERM_T,
	RELOP_T,			//10
	ADDOP_T,
	MULOP_T,
	PROCEDURE_STATEMENT_T,
} tree_types;

#include "relop.h"
#include "addop.h"
#include "mulop.h"
#include "identifier.h"
#include "identifier_list.h"
#include "types.h"
#include "declarations.h"
#include "factor.h"
#include "term.h"
#include "simple_expression.h"
#include "expression.h"
#include "expression_list.h"
#include "procedure_statement.h"
#include "program.h"

#define PROGRAM_N(x)				x->type == PROGRAM_T				? ((program_t*)x->node)				: (tree_error(x, PROGRAM_T   ),			NULL)
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
#define PROCEDURE_STATEMENT_N(x)	x->type == PROCEDURE_STATEMENT_T	? ((procedure_statement_t*)x->node)	: (tree_error(x, PROCEDURE_STATEMENT_T),NULL)

typedef struct tree_s {
	int type;
	void * node;
} tree_t;

tree_t * make_tree(void * node, tree_types type);
void tree_error(tree_t * given, tree_types expected);
void print_spaces(int spaces);

#endif

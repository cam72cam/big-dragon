#ifndef TREE_H
#define TREE_H

#define SP_INDENT 4

#include <stdio.h>

typedef struct tree_s tree_t;

typedef enum {
	PROGRAM_T,
	IDENTIFIER_T,
	IDENTIFIER_LIST_T,
	TYPE_T,
	DECLARATIONS_T,
} tree_types;

#include "identifier.h"
#include "identifier_list.h"
#include "types.h"
#include "declarations.h"
#include "program.h"

#define PROGRAM_N(x)			x->type == PROGRAM_T			? ((program_t*)x->node)			: (tree_error(x, PROGRAM_T   ),			NULL)
#define IDENTIFIER_N(x)			x->type == IDENTIFIER_T			? ((identifier_t*)x->node)		: (tree_error(x, IDENTIFIER_T),			NULL)
#define IDENTIFIER_LIST_N(x)	x->type == IDENTIFIER_LIST_T	? ((identifier_list_t*)x->node)	: (tree_error(x, IDENTIFIER_LIST_T),	NULL)
#define TYPE_N(x)				x->type == TYPE_T				? ((type_t*)x->node)			: (tree_error(x, TYPE_T),				NULL)
#define DECLARATIONS_N(x)		x->type == DECLARATIONS_T		? ((declarations_t*)x->node)	: (tree_error(x, DECLARATIONS_T),		NULL)

typedef struct tree_s {
	int type;
	void * node;
} tree_t;

tree_t * make_tree(void * node, tree_types type);
void tree_error(tree_t * given, tree_types expected);
void print_spaces(int spaces);

#endif

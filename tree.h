#ifndef TREE_H
#define TREE_H

typedef struct tree_s tree_t;

typedef enum {
	PROGRAM_T,
	IDENTIFIER_T,
} tree_types;

#include "identifier.h"
#include "program.h"

#define PROGRAM_N(x)	x->type == PROGRAM_T	? ((program_t*)x->node)    : (tree_error(x, PROGRAM_T   ), NULL)
#define IDENTIFIER_N(x)	x->type == IDENTIFIER_T ? ((identifier_t*)x->node) : (tree_error(x, IDENTIFIER_T), NULL)
typedef struct tree_s {
	int type;
	void * node;
} tree_t;

tree_t * make_tree(void * node, tree_types type);
void tree_error(tree_t * given, tree_types expected);

#endif

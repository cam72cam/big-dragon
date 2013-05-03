#ifndef FACTOR_H
#define FACTOR_H

typedef struct factor_s factor_t;

#include "tree.h"
#include "../scope.h"

typedef struct factor_s {
	tree_t * node;
	scope_ident_t * scoped_ident;
	bool not;
} factor_t;

tree_t* make_factor(tree_t * node);
void	print_factor(factor_t * node, int spaces);

#endif

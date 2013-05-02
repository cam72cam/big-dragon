#ifndef FACTOR_H
#define FACTOR_H

typedef struct factor_s factor_t;

#include "tree.h"

typedef struct factor_s {
	tree_t * node;
	bool not;
} factor_t;

tree_t* make_factor(tree_t * node);
void	print_factor(factor_t * node, int spaces);

#endif

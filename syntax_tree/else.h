#ifndef ELSE_H
#define ELSE_H

typedef struct else_s else_t;

#include "tree.h"

typedef struct else_s {
	tree_t * node;
} else_t;

tree_t * make_else(tree_t * node);
void	 print_else(else_t * node, int spaces);
void	  gencode_else(else_t * node);
#endif

#ifndef STATEMENT_H
#define STATEMENT_H

typedef struct statement_s statement_t;

#include "tree.h"

typedef struct statement_s {
	tree_t * node;
} statement_t;

tree_t* make_statement(tree_t * node);
void	print_statement(statement_t * node, int spaces);
void	gencode_statement(statement_t * statement);
#endif

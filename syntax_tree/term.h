#ifndef TERM_H
#define TERM_H

typedef struct term_s term_t;

#include "tree.h"

typedef struct term_s {
	term_t * left;
	mulop_t	* op;
	factor_t * right;
} term_t;

tree_t	* make_term(term_t * left, mulop_t * op, factor_t * right);
void	  print_term(term_t * node, int spaces);
int 	  typeof_term(term_t * node);
char * gencode_term(term_t * node);
#endif

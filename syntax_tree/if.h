#ifndef IF_H
#define IF_H

typedef struct if_s if_t;

#include "tree.h"

typedef struct if_s {
	expression_t	* expression;
	statement_t		* statement;
} if_t;

tree_t	* make_if(expression_t * expression, statement_t * statement);
void	* print_if(if_t * node, int spaces);
#endif

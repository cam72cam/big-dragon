#ifndef WHILE_H
#define WHILE_H

typedef struct while_s while_t;

#include "tree.h"

typedef struct while_s {
	expression_t	* expression;
	statement_t		* statement;
} while_t;

tree_t	* make_while(expression_t * expression, statement_t * statement);
void	* print_while(while_t * node, int spaces);
#endif

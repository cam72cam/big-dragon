#ifndef STATEMENT_LIST_H
#define STATEMENT_LIST_H

typedef struct statement_list_s statement_list_t;

#include "tree.h"

typedef struct statement_list_s {
	statement_t			* statement;
	statement_list_t	* next;
} statement_list_t;

tree_t	* make_statement_list(statement_t * statement, statement_list_t * next);
void	  print_statement_list(statement_list_t * node, int spaces);
#endif

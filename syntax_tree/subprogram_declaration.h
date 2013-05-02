#ifndef SUBPROGRAM_DECLARATION_H
#define SUBPROGRAM_DECLARATION_H

typedef struct subprogram_declaration_s subprogram_declaration_t;

#include "tree.h"

typedef struct subprogram_declaration_s {
	subprogram_head_t		* head;
	declarations_t			* declarations;
	statement_list_t 		* statements;
} subprogram_declaration_t;

tree_t	* make_subprogram_declaration(subprogram_head_t	* head,	declarations_t * declarations, statement_list_t	* statements);
void	  print_subprogram_declaration(subprogram_declaration_t * node, int spaces);
#endif

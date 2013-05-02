#ifndef PROCEDURE_STATEMENT_H
#define PROCEDURE_STATEMENT_H

typedef struct procedure_statement_s procedure_statement_t;

#include "tree.h"

typedef struct procedure_statement_s {
	identifier_t		* identifier;
	expression_list_t	* params;
} procedure_statement_t;

tree_t	* make_procedure_statement(identifier_t * ident, expression_list_t * params);
void	* print_procedure_statement(procedure_statement_t * node, int spaces);
#endif

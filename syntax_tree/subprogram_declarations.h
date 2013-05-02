#ifndef SUBPROGRAM_DECLARATIONS_H
#define SUBPROGRAM_DECLARATIONS_H

typedef struct subprogram_declarations_s subprogram_declarations_t;

#include "tree.h"

typedef struct subprogram_declarations_s {
	subprogram_declarations_t	* next;
	subprogram_declaration_t	* declaration;
} subprogram_declarations_t;

tree_t	* make_subprogram_declarations(subprogram_declaration_t * declaration, subprogram_declarations_t * next);
void	  print_subprogram_declarations(subprogram_declarations_t * node, int spaces);
#endif

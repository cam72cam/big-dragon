#ifndef DECLARATIONS_H
#define DECLARATIONS_H

typedef struct declarations_s declarations_t;

#include "tree.h"

typedef struct declarations_s {
	identifier_list_t * vars;
	type_t * type;
	declarations_t * next;
} declarations_t;

tree_t	* make_declarations(identifier_list_t * vars, type_t * type, declarations_t * next);
void	* print_declarations(declarations_t * node, int spaces);
#endif

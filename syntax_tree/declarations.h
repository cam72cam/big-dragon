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
void	  scope_add_declarations(declarations_t * list);
void	  print_declarations(declarations_t * node, int spaces);
void	  gencode_declarations(declarations_t * node);
#endif

#ifndef PARAMETER_LIST_H
#define PARAMETER_LIST_H

typedef struct parameter_list_s parameter_list_t;

#include "tree.h"

typedef struct parameter_list_s {
	identifier_list_t	* idents;
	type_t				* type;
	parameter_list_t	* next;
} parameter_list_t;

tree_t	* make_parameter_list(identifier_list_t * idents, type_t * type, parameter_list_t * next);
void	  scope_add_parameter_list(parameter_list_t * list);
void	  print_parameter_list(parameter_list_t * node, int spaces);
#endif

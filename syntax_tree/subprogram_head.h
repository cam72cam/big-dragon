#ifndef SUBPROGRAM_HEAD_H
#define SUBPROGRAM_HEAD_H

typedef struct subprogram_head_s subprogram_head_t;

#include "tree.h"

typedef struct subprogram_head_s {
	identifier_t		* ident;
	parameter_list_t	* params;
	type_t			 	* type;
} subprogram_head_t;

tree_t	* make_subprogram_head(identifier_t * ident, parameter_list_t * params, type_t * type);
void	  print_subprogram_head(subprogram_head_t * node, int spaces);
#endif

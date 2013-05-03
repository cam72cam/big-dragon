#ifndef SCOPE_H
#define SCOPE_H

typedef struct scope_s scope_t;

#include "syntax_tree/tree.h"

typedef struct scope_ident_s {
//	char * address;
	tree_t * node;
} scope_ident_t;


typedef struct scope_s {
	scope_t 			* up;
	scope_ident_t		* list;
	int					length;
	int					size;
	char 				* name;
	scope_t 			* down;
} scope_t;

scope_t * top_scope;
scope_t * current_scope;

void 			add_scope(char * name);
void			register_identifier(tree_t * node);
scope_ident_t 	* find_identifier(char * ident);
void			print_scope();
#endif

#ifndef SCOPE_H
#define SCOPE_H

typedef struct scope_s scope_t;
typedef struct scope_ident_s scope_ident_t;

#include "syntax_tree/tree.h"

typedef struct scope_ident_s {
//	char * address;
	bool param;
	identifier_t * node;
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
void			register_identifier(identifier_t * node, bool param);
scope_ident_t 	* find_identifier(char * ident);
scope_ident_t 	* find_identifier_with_type(char * ident, int type);
void			print_scope();
#endif

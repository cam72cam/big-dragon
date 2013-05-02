#ifndef INDENTIFIER_LIST_H
#define INDENTIFIER_LIST_H

typedef struct identifier_list_s identifier_list_t;

#include "tree.h"
#include "identifier.h"

typedef struct identifier_list_s {
	identifier_list_t	* next;
	identifier_t		* identifier;
} identifier_list_t;

tree_t * make_identifier_list(identifier_t * ident, identifier_list_t * next);
#endif

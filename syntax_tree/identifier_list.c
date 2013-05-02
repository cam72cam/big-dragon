#include "identifier_list.h"
#include <stdlib.h>

tree_t * make_identifier_list(identifier_t * ident, identifier_list_t * next) {
	identifier_list_t	* node	= malloc(sizeof(identifier_list_t));
	node->identifier			= ident;
	return make_tree(node, IDENTIFIER_LIST_T);
}

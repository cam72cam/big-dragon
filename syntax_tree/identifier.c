#include "identifier.h"
#include <stdlib.h>
#include <string.h>

tree_t *make_identifier(char * ident) {
	identifier_t	* node	= malloc(sizeof(identifier_t));
	node->ident		= malloc(sizeof(char) * (strnlen(ident, MAX_IDENT) + 1));
	strncpy(node->ident, ident, strnlen(ident, MAX_IDENT));
	return make_tree(node, IDENTIFIER_T);
}

void   print_identifier(identifier_t * node, int spaces) {
	if(node != NULL) {
		print_spaces(spaces);
		fprintf(stderr, "IDENT: %s\n", node->ident);
	} else {
		print_spaces(spaces);
		fprintf(stderr, "IDENT NOT FOUND!!!!");
	}
}

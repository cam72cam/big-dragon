#ifndef INDENTIFIER_H
#define INDENTIFIER_H

typedef struct identifier_s identifier_t;

#define MAX_IDENT 40
#include "tree.h"

typedef struct identifier_s {
	char * ident;
} identifier_t;

tree_t	* make_identifier(char * ident);
void	* print_identifier(identifier_t * node, int spaces);
#endif

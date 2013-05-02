#ifndef _RELOP_H_
#define _RELOP_H_

typedef enum {
	EQ,
	NE,
	LT,
	GT,
	LT_EQ,
	GT_EQ,
} relop_types;

typedef struct relop_s relop_t;

#include "tree.h"

typedef struct relop_s {
	relop_types type;
} relop_t;

tree_t	* make_relop(char * op);
void	* print_relop(relop_t * node, int spaces);

#endif

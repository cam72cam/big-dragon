#ifndef _TYPES_H_
#define _TYPES_H_

typedef struct type_s type_t;

#include "tree.h"
#include "../y.tab.h"

typedef struct type_s {
	int type;
} type_t;

tree_t	* make_type(int type);
void	  print_type(type_t * node, int spaces);
char 	* type_to_string(int type);
#endif

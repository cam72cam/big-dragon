#ifndef INTEGER_H
#define INTEGER_H

typedef struct integer_s integer_t;

#include "tree.h"

typedef struct integer_s {
	int	value;
} integer_t;

tree_t	* make_integer(int value);
void	  print_integer(integer_t * node, int spaces);
#endif

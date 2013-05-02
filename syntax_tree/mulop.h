#ifndef _MULOP_H_
#define _MULOP_H_

typedef enum {
	MULT,
	DIV,
	MOD, 
	AND,
} mulop_types;

typedef struct mulop_s mulop_t;

#include "tree.h"

typedef struct mulop_s {
	mulop_types type;
} mulop_t;

tree_t	* make_mulop(char * op);
void	  print_mulop(mulop_t * node, int spaces);

#endif

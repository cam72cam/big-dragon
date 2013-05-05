#ifndef _ADDOP_H_
#define _ADDOP_H_

typedef enum {
	PLUS,
	MINUS,
	OR,
} addop_types;

typedef struct addop_s addop_t;

#include "tree.h"

typedef struct addop_s {
	addop_types type;
} addop_t;

tree_t	* make_addop(char * op);
void	  print_addop(addop_t * node, int spaces);
char * gencode_addop(addop_t * node, char * left, char * right);

#endif

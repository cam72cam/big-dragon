#ifndef TREE_H
#define TREE_H

typedef union tree_s tree_t;

#include "identifier.h"
#include "program.h"

#define PROGRAM_N(x) x->program
#define IDENTIFIER_N(x) x->identifier
typedef union tree_s{
	program_t		* program;
	identifier_t	* identifier;
} tree_t;

tree_t * make_tree();



/*
YYSTYPE = 
union {
	program * prog;
	sub_prgm * sub_program;
	vars * variables;
}*/



/*typedef struct tree_s {
	int type;
	union {
		int ival;
		char* sval;
	} attribute;
	struct tree_s *left, *right;
}
tree_t;


tree_t *make_tree( int type, tree_t *left, tree_t *right );
void	print_tree( tree_t *t, int spaces );*/

#endif


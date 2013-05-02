#ifndef PROGRAM_H
#define PROGRAM_H

typedef struct program_s program_t;

#include "tree.h"

typedef struct program_s
{
	identifier_t * name;
	identifier_list_t * args;
	declarations_t * declarations;
} program_t;

tree_t	* make_program (identifier_t * name, identifier_list_t * args, declarations_t * declarations);
void 	* print_program(program_t * node, int spaces);
#endif

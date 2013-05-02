#ifndef PROGRAM_H
#define PROGRAM_H

typedef struct program_s program_t;

#include "identifier.h"

typedef struct program_s
{
	identifier_t * name;
	identifier_list_t * args;
} program_t;

tree_t	* make_program (identifier_t * name, identifier_list_t * args);
void 	* print_program(program_t * node, int spaces);
#endif

#ifndef PROGRAM_H
#define PROGRAM_H

typedef struct program_s program_t;

#include "identifier.h"

typedef struct program_s
{
	identifier_t * name;
} program_t;

tree_t * make_program(identifier_t * name);

#endif

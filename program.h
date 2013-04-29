#ifndef PROGRAM_H
#define PROGRAM_H

#include "identifier.h"

typedef struct program_s
{
	identifier_t * name;
} program_t;

program_t * make_program(identifier_t * name);

#endif

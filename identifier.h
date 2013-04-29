#ifndef INDENTIFIER_H
#define INDENTIFIER_H

#define MAX_IDENT 40
typedef struct identifier_s {
	char * ident;
} identifier_t;

identifier_t *make_identifier(char * ident);
#endif

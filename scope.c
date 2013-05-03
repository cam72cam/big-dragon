#include "scope.h"
#include <stdlib.h>
#include <string.h>

void add_scope(char * name) {
	if(top_scope == NULL) {
		top_scope = malloc(sizeof(scope_t));
		top_scope->up = NULL;
		top_scope->down = NULL;
		current_scope = top_scope;
	} else {
		current_scope->up = malloc(sizeof(scope_t));
		current_scope->up->down = current_scope;
		current_scope = current_scope->up;
		current_scope->up = NULL;
	}
	current_scope->size = 200;
	current_scope->length = 0;
	current_scope->name = malloc(sizeof(char) * (strlen(name)  +1));
	strcpy(current_scope->name, name);
	current_scope->list = malloc(sizeof(scope_ident_t)*(current_scope->size +1));
}
void register_identifier(identifier_t * node, bool param) {
	current_scope->list[current_scope->length].node = node;
	current_scope->list[current_scope->length].param = param;
	current_scope->length++;
	//TODO DYNAMICALLY EXTEND
}
scope_ident_t * find_identifier_with_type(char * ident, int type) {
	int i;
	int tmp_type;
	scope_t * curr;
	char * str;
	for(curr = current_scope; curr != NULL; curr = curr->down) {
		for(i = 0; i < curr->length; i++) {
			str = curr->list[i].node->ident;
			if(curr->list[i].node->type == NULL) {
				tmp_type = 0;
			} else {
				tmp_type = curr->list[i].node->type->type;
			}
			fprintf(stderr, "CURR IDENT %s %s:%d\n", curr->name, str, tmp_type);
			if(0 == strcmp(ident, str) && (type == tmp_type || type == -2)) {
				//TODO MEMCPY
				fprintf(stderr, "SCOPE: %s | %s = %s\n", curr->name, str, ident);
				return &curr->list[i];
			}
		}
	}
	fprintf(stderr, "COULD NOT FIND IDENTIFIER %s OF TYPE %d\n", ident, type);
	exit(-1);
	return NULL;
}

scope_ident_t * find_identifier(char * ident) {
	return find_identifier_with_type(ident, -2);
}

void print_scope() {
	
}

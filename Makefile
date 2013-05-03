SHELL   = /bin/bash

SYN_TREE_SRC	= tree.c identifier.c identifier_list.c program.c types.c declarations.c factor.c expression.c expression_list.c simple_expression.c term.c relop.c addop.c mulop.c procedure_statement.c subprogram_declaration.c subprogram_declarations.c subprogram_head.c parameter_list.c statement.c variable.c statement_list.c assignment.c if.c else.c while.c integer.c
SYN_TREE_OBJ	= $(SYN_TREE_SRC:%.c=syntax_tree/%.o)
SYNTAX_TREE		= $(SYN_TREE_SRC:%.c=syntax_tree/%)

CFLAGS 	= -rdynamic -g -Wall

main: lex yacc syn_tree scope
	cc $(CFLAGS) $(SYN_TREE_OBJ) scope.o lex.yy.c y.tab.c -o bigd -DYYSTYPE=tree_t*

syn_tree:
	cd syntax_tree && cc -c $(CFLAGS) $(SYN_TREE_SRC)

lex: bigd.l
	lex -d bigd.l
yacc: bigd.y
	yacc -d -y bigd.y
scope: scope.c scope.h
	cc -c $(CFLAGS) scope.c
clean:
	rm $(SYN_TREE_OBJ)
	rm lex.yy.c y.tab.c y.tab.h scope.o bigd 


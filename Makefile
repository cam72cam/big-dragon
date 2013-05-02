SHELL   = /bin/bash

SYN_TREE_SRC	= tree.c identifier.c identifier_list.c program.c types.c declarations.c factor.c expression.c expression_list.c simple_expression.c term.c relop.c addop.c mulop.c
SYN_TREE_OBJ	= $(SYN_TREE_SRC:%.c=syntax_tree/%.o)
SYNTAX_TREE		= $(SYN_TREE_SRC:%.c=syntax_tree/%)

CFLAGS 	= -rdynamic -g

main: lex yacc syn_tree
	cc $(CFLAGS) $(SYN_TREE_OBJ) lex.yy.c y.tab.c -o bigd -DYYSTYPE=tree_t*

syn_tree:
	cd syntax_tree && cc -c $(CFLAGS) $(SYN_TREE_SRC)

lex: bigd.l
	lex -d bigd.l
yacc: bigd.y
	yacc -d -y bigd.y
clean:
	rm $(SYN_TREE_OBJ)
	rm lex.yy.c y.tab.c y.tab.h bigd  


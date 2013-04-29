main: lex yacc tree identifier program
	cc identifier.o tree.o program.o lex.yy.c y.tab.c -o bigd -DYYSTYPE=tree_t*
tree: 
	cc -c tree.c
identifier:
	cc -c identifier.c
program:
	cc -c program.c
lex: bigd.l
	lex -d bigd.l
yacc: bigd.y
	yacc -d -y bigd.y
clean:
	rm lex.yy.c bigd  y.tab.c  y.tab.h program.o identifier.o tree.o

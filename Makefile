all: entrada_saida.o fila.o logica.o sim_senhas.o
	gcc -g -ggdb3 entrada_saida.o fila.o logica.o sim_senhas.o -o sim_senhas
entrada_saida.o: entrada_saida.c
	gcc -g -c entrada_saida.c
fila.o: fila.c
	gcc -g -c fila.c
logica.o: logica.c
	gcc -g -c logica.c
sim_senhas.o: sim_senhas.c
	gcc -g -c sim_senhas.c
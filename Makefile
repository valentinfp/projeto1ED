all: entrada_saida.o fila.o sim_senhas.o
	gcc -g entrada_saida.o fila.o sim_senhas.o -o entrada_saida
entrada_saida.o: entrada_saida.c
	gcc -g -c entrada_saida.c
fila.o: fila.c
	gcc -g -c fila.c
sim_senhas.o: sim_senhas.c
	gcc -g -c sim_senhas.c
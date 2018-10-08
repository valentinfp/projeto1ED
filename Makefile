all: entrada_saida.o fila.o logica.o
	gcc -g entrada_saida.o fila.o logica.o sim_senhas.c -o sim_senha
entrada_saida.o: entrada_saida.c
	gcc -g -c entrada_saida.c
fila.o: fila.c
	gcc -g -c fila.c
logica.o: logica.c
	gcc -g -c logica.c

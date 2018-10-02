#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int chegada;
	int idade;
	int servico;
	int condicao;
	int guiche;
	int espera;
	int prioridade;
	int chave;
}TipoCliente;

typedef struct Celula* Apontador;

typedef struct Celula{
	TipoCliente cliente;
	Apontador proximo;
}TipoCelula;

typedef struct{
	Apontador inicio, fim;
}TipoFila;



#endif
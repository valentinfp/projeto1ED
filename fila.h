#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

/*Tipos de variável*/
typedef struct Celula* Apontador;

/*Define os atributos de cada cliente*/
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

/*Celulas da fila de clientes*/
typedef struct Celula{
	TipoCliente cliente;
	Apontador proximo;
}TipoCelula;

/*Fila de clientes*/
typedef struct{
	Apontador inicio, fim;
}TipoFila;

/*Protótipo das funções*/

void alocaCelula(Apontador celula); /*Aloca uma célula dinamicamente*/
void criaFilaVazia(TipoFila* fila); /*Cria uma fila vazia*/
int Vazia(TipoFila* fila); /*Verifica se a fila está vazia*/
void adicionaCelula(TipoCliente* c, TipoFila* fila); /*Adiciona uma célula ao final da fila*/
void removeCelula(TipoCliente* c, TipoFila* fila); /*Remove uma célula no início da fila*/
void imprimeFila(Apontador celula); /*imprime todo o conteúdo da fila*/



#endif
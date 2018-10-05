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
	int indice;
}TipoCliente;

typedef struct {
	int numero;
	int servico;
	int cronometro;
}TipoGuiche;

/*Celulas da fila*/
typedef struct Celula{
	void* item;
	Apontador proximo;
}TipoCelula;

/*Fila*/
typedef struct{
	Apontador inicio, fim;
}TipoFila;

/*Protótipo das funções*/

void alocaCelula(Apontador celula); /*Aloca uma célula dinamicamente*/
void alocaFila(TipoFila* fila); // Aloca uma fila dinamicamente
void criaFilaVazia(TipoFila* fila); /*Cria uma fila vazia*/
void criaVetorFila(TipoFila** vetorFila, int tamanho); /*Cria um vetor de filas vazias*/
int vazia(TipoFila* fila); /*Verifica se a fila está vazia*/
void adicionaCelula(void* item, TipoFila* fila); /*Adiciona uma célula ao final da fila*/
void removeCelula(void* item, TipoFila* fila); /*Remove uma célula no início da fila*/
void freeFila(TipoFila* fila); // Libera o espaço de memória de toda a fila
void freeVetorFila(TipoFila** vetorFila, int tamanho); // Libera o espaço de memória de um vetor de filas
void imprimeFila(Apontador celula); /*imprime todo o conteúdo da fila*/



#endif
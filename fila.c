#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*Aloca uma célula dinamicamente*/
void alocaCelula(Apontador celula){
	celula = (Apontador)malloc(sizeof(Celula));
}

/*Cria uma fila vazia*/
void criaFilaVazia(TipoFila* fila){
	alocaCelula(fila->inicio);
	fila->fim = fila->inicio;
	fila->inicio->proximo = NULL;
}

/*Verifica se a fila está vazia*/
int vazia(TipoFila* fila){
	return(fila->inicio == fila->fim);
}

/*Adiciona um elemento ao final da fila*/
void adicionaCelula(TipoCliente* c, TipoFila* fila){
	Apontador novaCelula;
	alocaCelula(novaCelula);
	fila->fim = novaCelula;
	fila->fim->cliente = c;
	fila->fim->proximo = NULL;	
}

/*Remove o primeiro elemento na fila e atribui um novo primeiro elemento*/
void removeCelula(TipoCliente* c, TipoFila* fila){
	Apontador cel;
	if(vazia(fila)){
		printf("ERRO - Na função \"removeCelula\": A fila já está vazia.\n");
		return;
	}
	cel = fila->inicio;
	fila->inicio = fila->inicio->proximo;
	*c = fila->inicio->cliente;
	free(cel);
}

/*Imprime todo o conteúdo da fila*/
void imprimeFila(Apontador celula){
	Apontador c;
	for(c = celula; c != NULL; c = celula->proximo){
		printf("***************************************************************************\n");
		printf("Cliente %d\n\n", celula->cliente->chave);
		printf("Horario de chegada: %d\nIdade: %d\nServiço: %d\nCondicao: %d\nGuiche: %d\nTempo de espera: %d\nPrioridade: %d\n",
				celula->cliente->chegada, celula->cliente->idade, celula->cliente->servico, celula->cliente->condicao, celula->cliente->guiche,
				celula->cliente->espera, celula->cliente->prioridade);
	}
}
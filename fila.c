#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Aloca uma célula dinamicamente*/
Apontador alocaCelula(){
	return(TipoCelula*)malloc(sizeof(TipoCelula));
}

/*Aloca uma fila dinamicamente*/
TipoFila* alocaFila(){
	return (TipoFila*)malloc(sizeof(TipoFila));
}

/*Cria uma fila vazia*/
TipoFila* criaFilaVazia(){
	TipoFila* fila;
	fila = alocaFila();
	fila->inicio = alocaCelula();
	fila->fim = fila->inicio;
	fila->inicio->proximo = NULL;
	return fila;
}

/*Cria um vetor de filas vazias*/
TipoFila** criaVetorFila(){
	TipoFila** vetorFila;
	int i;
	vetorFila = (TipoFila**) malloc(sizeof(TipoFila*) * 5);
	for(i = 0; i < 5; i++){
		vetorFila[i] = criaFilaVazia();
	}
	return vetorFila;
}

/*Verifica se a fila está vazia*/
int vazia(TipoFila* fila){
	return (fila->inicio == fila->fim);
}

/*Adiciona um elemento ao final da fila*/
void adicionaCelula(void* item, TipoFila* fila){
	Apontador novaCelula;
	novaCelula = alocaCelula();
	fila->fim->proximo = novaCelula;
	fila->fim = novaCelula;
	fila->fim->item = item;
	fila->fim->proximo = NULL;	
}

/*Remove o primeiro elemento na fila e atribui um novo primeiro elemento*/
void removeCelula(void* item, TipoFila* fila){
	Apontador cel;
	if(vazia(fila)){
		return;
	}
	cel = fila->inicio;
	fila->inicio = fila->inicio->proximo;
	item = fila->inicio->item;
	free(cel);
}

// Libera o espaço de memória de toda a fila
void freeFila(TipoFila* fila){
	void* lixo;
	while(!vazia(fila)){
		removeCelula(lixo, fila);
		free(lixo);
	}
	free(fila->inicio);
	free(fila);
}

// Libera o espaço de memória de um vetor de filas
void freeVetorFila(TipoFila** vetorFila, int tamanho){
	int i;
	for(i = tamanho - 1; i >= 0; i--){
		freeFila(vetorFila[i]);
	}
	free(vetorFila);
}

/*Imprime todo o conteúdo da fila*/
void imprimeFila(Apontador celula){
/*	Apontador c;
	for(c = celula; c != NULL; c = celula->proximo){
		printf("***************************************************************************\n");
		printf("Cliente %d\n\n", celula->item->chave);
		printf("Horario de chegada: %d\nIdade: %d\nServiço: %d\nCondicao: %d\nGuiche: %d\nTempo de espera: %d\nPrioridade: %d\n",
				celula->item->chegada, celula->item->idade, celula->item->servico, celula->item->condicao, celula->item->guiche,
				celula->item->espera, celula->item->prioridade);
	}*/
}
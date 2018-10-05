#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Aloca uma célula dinamicamente*/
void alocaCelula(Apontador celula){
	celula = (Apontador)malloc(sizeof(celula));
}

/*Aloca uma fila dinamicamente*/
void alocaFila(TipoFila* fila){
	fila = (TipoFila*)malloc(sizeof(TipoFila));
}

/*Cria uma fila vazia*/
void criaFilaVazia(TipoFila* fila){
	alocaFila(fila);
	alocaCelula(fila->inicio);
	fila->fim = fila->inicio;
	fila->inicio->proximo = NULL;
}

/*Cria um vetor de filas vazias*/
void criaVetorFila(TipoFila** vetorFila, int tamanho){
	int i;
	vetorFila = (TipoFila**) malloc(sizeof(TipoFila*) * tamanho);
	for(i = 0; i < tamanho; i++){
		criaFilaVazia(vetorFila[i]);
	}
}

/*Verifica se a fila está vazia*/
int vazia(TipoFila* fila){
	return(fila->inicio == fila->fim);
}

/*Adiciona um elemento ao final da fila*/
void adicionaCelula(void* item, TipoFila* fila){
	Apontador novaCelula;
	alocaCelula(novaCelula);
	fila->fim = novaCelula;
	fila->fim->item = item;
	fila->fim->proximo = NULL;	
}

/*Remove o primeiro elemento na fila e atribui um novo primeiro elemento*/
void removeCelula(void* item, TipoFila* fila){
	Apontador cel;
	if(vazia(fila)){
		printf("ERRO - Na função \"removeCelula\": A fila já está vazia.\n");
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
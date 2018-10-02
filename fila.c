#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void alocaCelula(Apontador celula){
	celula = (Apontador)malloc(sizeof(Celula));
}

void criaFilaVazia(TipoFila* fila){
	alocaCelula(fila->inicio);
	fila->fim = fila->inicio;
	fila->inicio->proximo = NULL;
}

int Vazia(TipoFila* fila){
	return(fila->inicio == fila->fim);
}


void adicionaCliente(TipoCliente* cliente, TipoFila* fila){
	Apontador novo;
	alocaCelula(novo);
	novo->prox = NULL;
	if(Vazia(fila)){
		fila->inicio->proximo = novo;
		fila->fim = novo;
		return;
	}
	fila->fim->proximo = novo;
	
	novaCelula->cliente = cliente;
	novaCelula->prox = NULL;
	fila->fim->cliente = cliente;
	fila->fim->proximo = NULL;
	
}

void removeCliente(TipoCliente* cliente, TipoFila* fila){
	Apontador auxiliar;
	if(Vazia(fila)){
		printf("ERRO - Na função \"removeCliente\": A fila já está vazia.\n");
		return;
	}
	auxiliar = fila->inicio;
	fila->inicio = fila->inicio->proximo;
	*cliente = fila->inicio->cliente;
	free(auxiliar);
}

void removeFila(TipoFila* fila){
	while(!(Vazia(fila))){

	}
}

void imprimeLista(Apontador celula){
	Apontador c;
	for(c = celula; c != NULL; c = celula->proximo){
		printf("***************************************************************************\n");
		printf("Cliente %d\n\n", celula->cliente->chave);
		printf("Horario de chegada: %d\nIdade: %d\nServiço: %d\nCondicao: %d\nGuiche: %d\nTempo de espera: %d\nPrioridade: %d\n",
				celula->cliente->chegada, celula->cliente->idade, celula->cliente->servico, celula->cliente->condicao, celula->cliente->guiche,
				celula->cliente->espera, celula->cliente->prioridade);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "entrada_saida.h"
#include "logica.h"

/*Retorna a prioridade dos clientes*/
int prioridade(int idade, int condicao){
	int p = 0;

	if(idade < 65)
		p = 1;
	else 	
		if(idade < 80)
			p = 2;
		else
			p = 3;

	if(condicao == 0)
		p += 2;
	else 
		if(condicao == 1)
			p += 2;
		else
			p += 1;

	return p;
}

/*Lê a fila de carga (clientes)*/
int leCarga(char* nomeArquivo, TipoFila* fila){
	int i=0;
	FILE* arquivo;
	TipoCliente* cliente;

	arquivo = fopen(nomeArquivo, "r");
	
	cliente = (TipoCliente*)malloc(1*sizeof(TipoCliente));

	while(fscanf(arquivo,"%d ", &cliente->chegada) != EOF){
		i++;
		fscanf(arquivo,"%d %d %d",&cliente->idade, &cliente->servico, &cliente->condicao);

		cliente->prioridade = prioridade(cliente->idade, cliente->condicao);
		cliente->indice = i;	

		cliente = (TipoCliente*)malloc(1*sizeof(TipoCliente));
		adicionaCelula(cliente, fila);
	}
	fclose(arquivo);

	return i;
}

/*Lê as filas de configuração (guichês)*/
void leConfiguracao(char * nomeArquivo, TipoFila** vetorFila, TipoFila** vetorAberto){
	FILE* arquivo;
	TipoGuiche* guiche;
	int i, n;

	arquivo = fopen(nomeArquivo, "r");

	fscanf(arquivo, "%d", &n);

	for(i = 1; i < n + 1; i++){
		guiche = (TipoGuiche*)malloc(1*sizeof(TipoGuiche));
		fscanf(arquivo, "%d", &guiche->servico);
		guiche->numero = i;
	
		adicionaCelula(guiche, vetorFila[guiche->servico]);
		adicionaCelula(guiche,vetorAberto[guiche->servico]);	
	}
	fclose(arquivo);
}

/*Funcao que gera o arquivo de saida*/
void imprimeSaida(char* nomeArquivo, TipoFila* fila, int qtClientes, int relogio){
	float somaEspera=0;
	FILE* arquivo;
    Apontador p;
    TipoCliente* Auxp;

	arquivo = fopen(nomeArquivo,"w");
	fprintf(arquivo,"\n");

    p = fila->inicio->proximo;
    Auxp = p->item;

    while(p!=NULL){
		Auxp = p->item;
		fprintf(arquivo, "%d %d %d %d", Auxp->guiche, Auxp->prioridade, Auxp->espera, Auxp->servico);
        somaEspera += Auxp->espera;
        p = p->proximo;
    }

	rewind(arquivo);
	fprintf(arquivo, "%.2f %.2f", (somaEspera/qtClientes), (qtClientes/relogio));

	fclose(arquivo);
}
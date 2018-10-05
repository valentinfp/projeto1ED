#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "entrada_saida.h"


/*Lê a fila de carga (clientes)*/
void leCarga(char* nomeArquivo, TipoFila* fila){
	FILE* arquivo;
	TipoCliente* cliente;

	arquivo = fopen(nomeArquivo, "r");
	
	cliente = (TipoCliente*)malloc(1*sizeof(TipoCliente));

	while(fscanf(arquivo,"%d ", &cliente->chegada) != EOF){

		fscanf(arquivo,"%d %d %d",&cliente->idade, &cliente->servico, &cliente->condicao);

		cliente->prioridade = prioridade(cliente->idade, cliente->condicao);

		adicionaCelula(cliente, fila);	

		cliente = (TipoCliente*)malloc(1*sizeof(TipoCliente));
	}

	fclose(arquivo);
}

/*Lê as filas de configuração (guichês)*/
void leConfiguracao(char * nomeArquivo, TipoFila** vetorFila){
	FILE* arquivo;
	TipoGuiche* guiche;
	int i, n;

	arquivo = fopen(nomeArquivo, "r");

	fscanf(arquivo, "%d", &n);

	for(i = 1; i < n + 1; i++){
		guiche = (TipoGuiche*)malloc(1*sizeof(TipoGuiche));
		fscanf(arquivo, "%d", &guiche->servico);
		guiche->numero = i;
		switch(guiche->servico){
			case 0:
				adicionaCelula(guiche, vetorFila[0]);
				break;
			case 1:
				adicionaCelula(guiche, vetorFila[1]);
				break;
			case 2:
				adicionaCelula(guiche, vetorFila[2]);
				break;
			case 3:
				adicionaCelula(guiche, vetorFila[3]);
				break;
			case 4:
				adicionaCelula(guiche, vetorFila[4]);
				break;
		}
	}
	fclose(arquivo);
}

/*Retorna a prioridade dos clientes*/
int prioridade(int idade, int condicao){
	int p = 0;

	if(idade < 65)
		p = 1;
	else if(idade < 80)
		p = 2;
	else
		p = 3;

	if(condicao == 0)
		p += 2;
	else if(condicao == 1)
		p += 2;
	else
		p += 1;

	return p;
}
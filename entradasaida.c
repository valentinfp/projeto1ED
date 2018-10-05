#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "entradasaida.h"


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

/*Lê a fila de carga (clientes)*/
void leCarga(char* nomeArquivo, TipoFila* fila){
	FILE* arquivo;
	TipoCliente cliente;

	arquivo = fopen(nomeArquivo, "rb");
	
	while(1){

		fread(&cliente.chegada , 1, sizeof(int), arquivo);
		fread(&cliente.idade   , 1, sizeof(int), arquivo);
		fread(&cliente.servico , 1, sizeof(int), arquivo);
		fread(&cliente.condicao, 1, sizeof(int), arquivo);

		cliente.prioridade = prioridade(cliente.idade, cliente->condicao);

		adicionaCelula(&cliente, &fila);	

		if(feof(arquivo))
			break;
	}
	fclose(arquivo);
}

/*Lê as filas de configuração (guichês)*/
void leConfiguracao(char * nomeArquivo, TipoFila** vetorFila){
	FILE* arquivo;
	TipoGuiche guiche;
	int i, n;

	arquivo = fopen(nomeArquivo, "r");

	fscanf(arquivo, "%d", &n);

	for(i = 1, i < n + 1, i++){
		fscanf(arquivo, "%d", &guiche.servico);
		guiche.numero = i;
		switch(guiche.servico){
			case 0:
				adicionaCelula(&guiche, vetorFila[0]);
				break;
			case 1:
				adicionaCelula(&guiche, vetorFila[1]);
				break;
			case 2:
				adicionaCelula(&guiche, vetorFila[2]);
				break;
			case 3:
				adicionaCelula(&guiche, vetorFila[3]);
				break;
			case 4:
				adicionaCelula(&guiche, vetorFila[4]);
				break;
		}
	}
	fclose(arquivo);
}
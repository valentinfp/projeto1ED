#ifndef ENTRADASAIDA_H
#define ENTRADASAIDA_H 

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int prioridade(int idade, int condicao); //Retorna a prioridade dos clientes
int leCarga(char* nomeArquivo, TipoFila* fila); //Lê a fila de carga (clientes)
void leConfiguracao(char * nomeArquivo, TipoFila** vetorAberto); //Lê as filas de configuração (guichês)
void imprimeSaida(char* nomeArquivo, TipoFila* fila, int qtClientes, int relogio);/*Funcao que gera o arquivo de saida*/

#endif
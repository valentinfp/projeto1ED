#ifndef ENTRADASAIDA_H
#define ENTRADASAIDA_H 

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int prioridade(int idade, int condicao); //Retorna a prioridade dos clientes
void leCarga(char* nomeArquivo, TipoFila* fila); //Lê a fila de carga (clientes)
void leConfiguracao(char * nomeArquivo, TipoFila** vetorFila); //Lê as filas de configuração (guichês)

#endif
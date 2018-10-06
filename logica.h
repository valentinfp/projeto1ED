#ifndef LOGICA_H
#define LOGICA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void encaixaPrioridade(TipoCliente* cliente, TipoFila *fila); /*Funçao que coloca o cliente na fila decrescentemente de acordo com a sua prioridade.*/
void chegaCliente(int relogio, TipoFila* fila, TipoFila** vetorFila); /*Caso um cliente chegue, a funcao o aloca na respectiva fila de servico.*/

#endif
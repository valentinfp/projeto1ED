#ifndef LOGICA_H
#define LOGICA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/*Funçao que coloca o cliente na fila de acordo com a sua prioridade. 
  Pessoas com maior prioridade ficam no começo.*/
void encaixaPrioridade(TipoCliente* cliente, TipoFila *fila);

#endif
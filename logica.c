#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Funçao que coloca o cliente na fila de acordo com a sua prioridade. 
  Pessoas com maior prioridade ficam no começo*/
void encaixaPrioridade(TipoCliente* cliente, TipoFila *fila){
    Apontador c;
    alocaCelula(c);
    c->item = cliente;

    Apontador p;
    p = fila->inicio->proximo;
    if(p==NULL){
        adicionaCelula(cliente, fila);
        free(c);
    }
    else{
        while(p!=NULL){
            if((c.item.prioridade) < (p.item.prioridade)){
                c->proximo = p->proximo;
                p->proximo = c;
                return;
            }
            p = p->proximo;
        }
        adicionaCelula(cliente, fila);
        free(c);
    }
}




























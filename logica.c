#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Funçao que coloca o cliente na fila decrescentemente de acordo com a sua prioridade.*/
void encaixaPrioridade(TipoCliente* cliente, TipoFila* fila){
    Apontador c;
    TipoCliente* Auxc;
    Apontador p;
    TipoCliente* Auxp;

    alocaCelula(c);
    c->item = cliente;
    Auxc = c->item;
    p = fila->inicio->proximo;

    if(p==NULL){
        adicionaCelula(cliente, fila);
        free(c);
    }
    else{
        while(p!=NULL){
            Auxp = p->item;
            if((Auxc->prioridade) < (Auxp->prioridade)){
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

/*Caso um cliente chegue, a funcao o aloca na respectiva fila de servico.*/
void chegaCliente(int relogio, TipoFila* fila, TipoFila** vetorFila){
    Apontador p;
    TipoCliente* Auxp;
    p = fila->inicio->proximo;
    Auxp = p->item;

    if(Auxp->chegada != relogio){
        return;
    }
    else{
        while(Auxp->chegada == relogio){
            removeCelula(Auxp, fila);
            encaixaPrioridade(Auxp, vetorFila[Auxp->servico]);
            p = fila->inicio->proximo;
            Auxp = p->item;
        }
    }
}




























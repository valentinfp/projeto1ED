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
            if((Auxc->prioridade) > (Auxp->prioridade)){
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

/*Funçao que coloca o cliente na fila crescentemente de acordo com o seu indice.*/
void encaixaIndice(TipoCliente* cliente, TipoFila* fila){
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
            if((Auxc->indice) < (Auxp->indice)){
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
void chegaCliente(TipoFila* fila, TipoFila** vetorFila, int relogio){
    Apontador p;
    TipoCliente* Auxp;
    p = fila->inicio->proximo;
    Auxp = p->item;

    if(Auxp->chegada!=relogio || vazia(fila)){
        return;
    }
    else{
        while(Auxp->chegada==relogio && !vazia(fila)){
            removeCelula(Auxp, fila);
            encaixaPrioridade(Auxp, vetorFila[Auxp->servico]);
            p = fila->inicio->proximo;
            Auxp = p->item;
        }
    }
}

/*Funcao verifica se eh necessario e abre guiches fechados*/ 
void verificaAbertura(TipoFila* aberto, TipoFila* fechado){
    Apontador p;
    TipoGuiche* Auxp;
    p = fechado->inicio->proximo;
    Auxp = p->item;

    while(Auxp->cronometro==0 && !vazia(fechado)){
        abreGuiche(aberto, fechado);
        p = fechado->inicio->proximo;
        Auxp = p->item;
    }
}

/*Verifica a abertura de todos os guiches*/
void verificaAberturaTodos(TipoFila** vetorAberto, TipoFila** vetorFechado){
    int i;

    for(i=0; i<5; i++){
        verificaAbertura(vetorAberto[i], vetorFechado[i]);
    }
}

/*Atende, se possivel, clientes na fila de espera do respectivo servico*/
void atendeCliente(TipoFila* aberto, TipoFila* fechado, TipoFila* filaServico, TipoFila* filaUnica, int relogio, int tempoServico){
    TipoCliente* cliente;

    while(!vazia(aberto) && !vazia(filaServico)){
        removeCelula(cliente, filaServico);
        cliente->guiche = fechaGuiche(aberto, fechado, tempoServico);
        cliente->espera = (relogio - cliente->chegada);
        encaixaIndice(cliente, filaUnica);
    }
}

/*Atende clientes de todas as filas de servico*/
void atendeClienteTodos(TipoFila** vetorAberto, TipoFila** vetorFechado, TipoFila** vetorServico, TipoFila* filaUnica, int relogio){

    atendeCliente(vetorAberto[0], vetorFechado[0], vetorServico[0], filaUnica, relogio, 5);
    atendeCliente(vetorAberto[1], vetorFechado[1], vetorServico[1], filaUnica, relogio, 10);
    atendeCliente(vetorAberto[2], vetorFechado[2], vetorServico[2], filaUnica, relogio, 8);
    atendeCliente(vetorAberto[3], vetorFechado[3], vetorServico[3], filaUnica, relogio, 7);
    atendeCliente(vetorAberto[4], vetorFechado[4], vetorServico[0], filaUnica, relogio, 2);

}

/*Verifica se a simulacao chegou ao fim*/
int verificaFim(TipoFila** vetorServico, TipoFila** vetorFechado, TipoFila* filaUnica){
    int i, fim=1;
    
    for(i=0; i<5; i++){
        if(!vazia(vetorServico[i])) fim=0;
    }
    for(i=0; i<5; i++){
        if(!vazia(vetorFechado[i])) fim=0;
    }
    if(!vazia(filaUnica)) fim=0;

    return fim;
}
























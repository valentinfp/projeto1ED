#ifndef LOGICA_H
#define LOGICA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void encaixaPrioridade(TipoCliente* cliente, TipoFila *fila); /*Funçao que coloca o cliente na fila decrescentemente de acordo com a sua prioridade.*/
void encaixaIndice(TipoCliente* cliente, TipoFila* fila);/*Funçao que coloca o cliente na fila crescentemente de acordo com o seu indice.*/
void chegaCliente(TipoFila* fila, TipoFila** vetorFila, int relogio); /*Caso um cliente chegue, a funcao o aloca na respectiva fila de servico.*/ 
int fechaGuiche(TipoFila* aberto, TipoFila* fechado, int tempoServico);/*Transfere um guiche da fila de abertos para a de fechados e atualiza seu cronometro*/
void abreGuiche(TipoFila* aberto, TipoFila* fechado);/*Transfere um guiche da fila de fechados para a de abertos*/
void diminuiCronometro(TipoFila* fechado);/*Diminui o cronometro dos guiches fechado de um servico especifico*/
void diminuiCronometroTodos(TipoFila** vetorFechado);/*Diminui o cronometro de todos os guiches*/
void verificaAbertura(TipoFila* aberto, TipoFila* fechado);/*Funcao verifica se eh necessario e abre guiches fechados*/
void verificaAberturaTodos(TipoFila** vetorAberto, TipoFila** vetorFechado);/*Verifica a abertura de todos os guiches*/
void atendeCliente(TipoFila* aberto, TipoFila* fechado, TipoFila* filaServico, TipoFila* filaUnica, int relogio, int tempoServico);/*Atende, se possivel, clientes na fila de espera do respectivo servico*/
void atendeClienteTodos(TipoFila** vetorAberto, TipoFila** vetorFechado, TipoFila** vetorServico, TipoFila* filaUnica, int relogio);/*Atende clientes de todas as filas de servico*/
int verificaFim(TipoFila** vetorServico, TipoFila** vetorFechado, TipoFila* filaUnica);/*Verifica se a simulacao chegou ao fim*/
float calculaSomaEspera(TipoFila* fila);/*Funcao retorna a soma das esperas dos clientes*/

#endif
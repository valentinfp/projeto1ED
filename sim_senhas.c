#include <stdio.h>
#include <stdlib.h>
#include "entrada_saida.h"
#include "fila.h"
#include "logica.h"

int main(int argc, char** argv){
	int relogio=0, qtCliente;
	TipoFila *Entrada, *Saida;
	TipoFila **Atendimento,**guicheAberto, **guicheFechado;

	Entrada = criaFilaVazia();
	Saida = criaFilaVazia();
	Atendimento = criaVetorFila();
	guicheAberto = criaVetorFila();
	guicheFechado = criaVetorFila();

	qtCliente = leCarga(argv[2], Entrada);
	leConfiguracao(argv[1], guicheAberto);

	while(!verificaFim(Atendimento, guicheFechado, Entrada)){
		relogio++;
		chegaCliente(Entrada, Atendimento, relogio);
		diminuiCronometroTodos(guicheFechado);
		verificaAberturaTodos(guicheAberto, guicheFechado);
		atendeClienteTodos(guicheAberto, guicheFechado, Atendimento, Saida, relogio);
	}

	imprimeSaida(argv[3], Saida, qtCliente, relogio);

	freeFila(Entrada);
	freeFila(Saida);
	freeVetorFila(Atendimento, 5);
	freeVetorFila(guicheAberto, 5);
	freeVetorFila(guicheFechado, 5);

	return 0;
}

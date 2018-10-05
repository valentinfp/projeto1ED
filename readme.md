# Projeto 1 de Estrutura de Dados 2018/02 - Universidade de Brasília
Autores: Valentin e Larissa

	v0.1
	
	* Arquivos criados:
		> projeto1.c;
		> fila.h;
		> fila.c.
	
	v0.2
	
	fila.h:
        	* Atualizado com protótipos das funções de fila.c;
		* Adicionados comentários explicando as estruturas e as funções.

	fila.c:
		* Funções básicas de manipulação da lista foram finalizadas. Entre elas:
			> alocaCelula;
			> criaFilaVazia;
			> vazia;
			> adicionaCelula;
			> removeCelula;
			> imprimeFila.
		* Adicionados comentários explicando as funções.

	v0.3

	* Arquivos criados:
		> entradasaida.h;
		> entradasaida.c.

	fila.h:
		* Os tipos TipoCelula e TipoFila tiveram nomes de suas variáveis internas atualizados para serem utilizados com qualquer tipo de fila (não só de clientes);
		* Foi adicionado um TipoGuiche para armazenar as informações do arquivo de configuração de guichês;
		* Os protótipos das funções foram atualizados conforme alterações feitas no fila.c.

	fila.c:
		* Todas as funções foram atualizadas para funcionar para diferentes tipos de item (void*);
		* Novas funções foram criadas:
			> alocaFila;
			> criaVetorFila;
			> freeFila;
			> freeVetorFila.

	entradasaida.h:
		* Adicionado com o protótipo das funções de entradasaida.c.

	entradasaida.c
		* Novas funções foram criadas:
			> prioridade;
			> leCarga;
			> leConfiguracao;
		
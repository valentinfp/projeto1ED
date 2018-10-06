# Projeto 1 de Estrutura de Dados 2018/02 - Universidade de Bras�lia
Autores: Valentin e Larissa

	v0.1
	
	* Arquivos criados:
		> projeto1.c;
		> fila.h;
		> fila.c.
	
	v0.2
	
	fila.h:
        	* Atualizado com prot�tipos das fun��es de fila.c;
		* Adicionados coment�rios explicando as estruturas e as fun��es.

	fila.c:
		* Fun��es b�sicas de manipula��o da lista foram finalizadas. Entre elas:
			> alocaCelula;
			> criaFilaVazia;
			> vazia;
			> adicionaCelula;
			> removeCelula;
			> imprimeFila.
		* Adicionados coment�rios explicando as fun��es.

	v0.3

	* Arquivos criados:
		> entradasaida.h;
		> entradasaida.c.

	fila.h:
		* Os tipos TipoCelula e TipoFila tiveram nomes de suas vari�veis internas atualizados para serem 
		  utilizados com qualquer tipo de fila (n�o s� de clientes);
		* Foi adicionado um TipoGuiche para armazenar as informa��es do arquivo de configura��o de guich�s;
		* Os prot�tipos das fun��es foram atualizados conforme altera��es feitas no fila.c.

	fila.c:
		* Todas as fun��es foram atualizadas para funcionar para diferentes tipos de item (void*);
		* Novas fun��es foram criadas:
			> alocaFila;
			> criaVetorFila;
			> freeFila;
			> freeVetorFila.

	entradasaida.h:
		* Adicionado com o prot�tipo das fun��es de entradasaida.c.

	entradasaida.c
		* Novas fun��es foram criadas:
			> prioridade;
			> leCarga;
			> leConfiguracao.

	v0.3.2:

	entrada_saida.c:
		* Renomeado de "entradasaida.c";
		* Foram feitas algumas pequenas corre��es nas fun��es.

	sim_senhas.c:
		* Renomeado de "projeto1.c";
		* Atualizado para contar uma fun��o main vazia que importa todas os arquivos at� agora.

	Mafile:
		* Arquivo criado;
		* Atualizado com as instru��es atuais de compila��o.			

	v0.4

	* Arquivos criados:
		> logica.h;
		> logica.c.

	entradasaida.h:
		* Adicionado com o prot�tipo das fun��es de logica.c.

	entradasaida.c
		* Nova fun��es foi criadas:
			> encaixaPrioridade;
	
	v0.4.1

	fila.c:
		*printf removido da funcao removeCelula.

	entrada_saida.c:
		*funcao de leitura modificada para informar o indice do cliente.

	logica.h:
		* Adicionado com o prot�tipo das fun��es de logica.c.

	logica.c:
		*Nova funcao foi criada:
		 >chegaCliente;

	sim_senhas.c:
		*incluida a biblioteca da logica.h na main;



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 2000

int main(void)
{
    double start, stop; // variaveis para medir tempo
    int index;          // para escolha de elementos aleatorios
    int qIn, qOut;      // Variáveis para testar se a busca funcionou
    int n;              //índice retornado pela busca
    unsigned int seed = time(NULL); //gerando uma semente para os testes
	/*
        Criamos uma lista Linear de Alocação sequencial para
        utilizar como referência e fonte de dados para testar
        as outras listas. Como esta lista vai ser utilizada 
        apenas como fonte de dados, os alunos vão ser 
        acessados diretamente no array pelo seu índice. 
        Podemos utilizar uma lista não ordenada
    */
    TListAlunos lista;                   // declarando a variável
	iniListAlunos(&lista, LSIZE, FALSE); // inicializando a lista não ordenada
	geraAlunos(&lista);                  // Prenhe a lista não ordenada
    
    /*
        Testando o desempenho de uma lista linear de alocação
        sequencial não ordenada
        1. Se cria uma lista de  tamanho LSIZE/2
    */
	TListAlunos listaNaoOrd;
	iniListAlunos(&listaNaoOrd, LSIZE/2, FALSE);
	printf(" Testando uma Lista Linear de Alocação\n");
    printf("Sequencial Não Ordenada.\n");
    printf("CAP = %d\n", LSIZE/2);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de forma
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta incluir um elemento que já existe na lista. 
        Para comparar esta estrutura, definir uma semente que 
        garanta a mesma sequencia de números aleatórios em 
        todos os testes
    */
    
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    // enquanto a lista não estiver cheia  
	while(listaNaoOrd.tam < listaNaoOrd.cap){ 
		// gera um índice aleatório nos limites da lista de referencia
        index = random()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido 
		incAluno(lista.lista[index], &listaNaoOrd);
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (listaNaoOrd.cap <= 10)
        printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam); 

    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */

	
	start = omp_get_wtime(); // Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos estão ou não na lista
    // percorrer todos os indices da lista de referencia
	for(index = 0; index < lista.tam; index++){
        // Procurar o elemento index
		n = buscaAluno(&listaNaoOrd, lista.lista[index].numMatricula);
		if(n < listaNaoOrd.tam){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remoção de elementos\n");
    /*
        4. Esvaziar a lista pegando elementos da lista de
        referência. Desta forma é possível avaliar o 
        desempenho considerando os casos em que se excluem 
        elementos que não existem na lista. 
    */
    qIn = qOut = 0; // quantos elementos estão ou não na lista
	start = omp_get_wtime();// Iniciando o cronometro
    // enquanto a lista não estiver vazia 
    for(index = 0; index < lista.tam; index++){
        // Remove o elemento index
		if(remAluno(lista.lista[index], &listaNaoOrd)){ // se foi removido 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_rem = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);
	if (listaNaoOrd.cap <= 10)
        printLisAluno(listaNaoOrd.lista, listaNaoOrd.tam);

    /*
        Testando o desempenhyo de uma lista linear de alocação
        sequencial ordenada
        1. Se cria uma lista de  tamanho LSIZE/2
    */

	printf(" Testando uma Lista Linear de Alocação\n");
    printf("Sequencial Ordenada.\n");
    printf("CAP = %d\n", LSIZE/2);

	TListAlunos listaOrd;
	iniListAlunos(&listaOrd, LSIZE/2, TRUE);

    printf("Testando inclusão de elementos\n");
    /*
        2. Preencher a lista pegando elementos, de forma
        aleatória da lista de referência. Desta forma é possível 
        avaliar o desempenho considerando os casos em que se 
        tenta incluir um elemento que já existe na lista. 
        Para comparar com a estrutura anterior redefinir a 
        semente
    */
    srand(seed); // definindo a semente do sequencia rand
	start = omp_get_wtime(); // Iniciando o cronometro
    // enquanto a lista não estiver cheia  
	while(listaOrd.tam < listaOrd.cap){
        // gera um índice aleatório nos limites da lista de referencia
		index = random()%LSIZE;
        // incluindo o elemento index, pode já ter sido incluido 
		incAluno(lista.lista[index], &listaOrd);
	} 
	stop = omp_get_wtime();// Para o cronometro
	printf("t_inc = %f\n", stop - start);
    if (listaOrd.cap <= 10)
        printLisAluno(listaOrd.lista, listaOrd.tam);

    printf("Testando busca de elementos\n");
    /*
        3. Procurar pelos elementos da lista de referencia na nova
        lista. Metade dos elementos estão e a outra metade não. Trata-se 
        de teste de busca considerando elementos que estão e que não
        estão na lista. 
    */
	
	start = omp_get_wtime(); // Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos estão ou não na lista
    // percorrer todos os indices da lista de referencia
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
		n = buscaAluno(&listaOrd, lista.lista[index].numMatricula);
		if(listaOrd.lista[n].numMatricula == lista.lista[index].numMatricula){ // se esta na lista 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime();// Para o cronometro
	printf("t_bus = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remoção de elementos\n");
    /*
        4. Esvaziar a lista pegando elementos da lista de
        referência. Desta forma é possível avaliar o 
        desempenho considerando os casos em que se excluem 
        elementos que não existem na lista.
    */
	
	start = omp_get_wtime();// Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos estão ou não na lista
    // enquanto a lista não estiver vazia 
    for(index = 0; index < lista.tam; index++){
        // Remove o elemento index
		if(remAluno(lista.lista[index], &listaOrd)){ // se foi removido 
			qIn++; // conta que achou
		}else{ // caso contrario 
			qOut++; // conta que não achou 
		}
	}
	stop = omp_get_wtime(); // Para o cronometro
	printf("t_rem = %f\n", stop - start);
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);
	if (listaOrd.cap <= 10)
        printLisAluno(listaOrd.lista, listaNaoOrd.tam); 

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "ferramentas.h"

#define LSIZE 3000

int main(void)
{
    int index;          // para escolha de elementos aleatorios
    int qIn, qOut;      // Vari�veis para testar se a busca funcionou
    int n;              //�ndice retornado pela busca
    unsigned int seed = time(NULL); //gerando uma semente para os testes

    setlocale(LC_ALL, "Portuguese"); //utilizar acentua��o

    /*
        Criamos uma lista Linear de Aloca��o sequencial para
        utilizar como refer�ncia e fonte de dados para testar
        as outras listas. Como esta lista vai ser utilizada
        apenas como fonte de dados, os alunos v�o ser
        acessados diretamente no array pelo seu �ndice.
        Podemos utilizar uma lista n�o ordenada
    */

    TListAlunos lista;                   // declarando a vari�vel
	iniListAlunos(&lista, LSIZE, FALSE); // inicializando a lista n�o ordenada
	geraAlunos(&lista);                  // preenche a lista n�o ordenada

	printf(" Testando uma Lista Linear de Aloca��o\n");
    printf("Sequencial Ordenada.\n");
    printf("CAP = %d\n", LSIZE/2);

	TListAlunos listaOrd;
	iniListAlunos(&listaOrd, LSIZE/2, TRUE);
    //printLisAluno(lista.lista,LSIZE/2); //imprimindo a lista original

    /*
        Testando o desempenho de uma �rvore bin�ria de busca
        1. Se cria uma �rvore
    */

	printf(" Testando uma �rvore Bin�ria de Busca\n");
    printf("equivalente � lista ordenada anterior.\n");


	PNoArvAluno minhaArv = NULL;

    printf("Testando inclus�o de elementos\n");

    /*
        2. Preencher a �rvore pegando elementos, de forma
        aleat�ria da lista de refer�ncia. Desta forma � poss�vel
        avaliar o desempenho considerando os casos em que se
        tenta incluir um elemento que j� existe na lista.
        Para comparar com a estrutura anterior redefinir a
        semente
    */

    srand(seed); // definindo a semente do sequencia rand
    clock_t tempoinc; // variaveis para medir tempo
	tempoinc = clock(); // Iniciando o cronometro
    // enquanto a lista n�o estiver cheia
    int cont = 0;
    int ok;
	while(cont < listaOrd.cap){
        // gera um �ndice aleat�rio nos limites da lista de referencia
		index = rand()%LSIZE;
        // incluindo o elemento index, pode j� ter sido incluido
		ok = incArvAluno(lista.lista[index], &minhaArv);
        if(ok == TRUE)
            cont++;
	}
	tempoinc = clock() - tempoinc;// Para o cronometro
	printf("t_inc = %0.50lf\n", ((double)tempoinc)/((CLOCKS_PER_SEC/1000)));

    if (listaOrd.cap <= LSIZE){
        printf("Arvore Bin�ria de Busca em Pre-ordem\n");
        //printArvAluno(minhaArv, PRE_ORDEM);
        printf("Arvore Bin�ria de Busca em Ordem\n");
        //printArvAluno(minhaArv, ORDEM);
    }

    printf("Testando busca de elementos\n");

     /*
        3. Procurar pelos elementos da lista de referencia na �rvore
        Metade dos elementos est�o e a outra metade n�o. Trata-se
        de teste de busca considerando elementos que est�o e que n�o
        est�o na lista.
    */
    clock_t tempobusc; // variaveis para medir tempo
	tempobusc = clock(); // Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos est�o ou n�o na lista
    // percorrer todos os indices da lista de referencia
    PNoArvAluno no;
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        no = buscaArvAluno(minhaArv, lista.lista[index].numMatricula);
		if(no != NULL){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que n�o achou
		}
	}
	tempobusc = clock() - tempobusc;// Para o cronometro
	printf("t_bus = %lf\n", ((double)tempobusc)/((CLOCKS_PER_SEC/1000)));
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remo��o de elementos\n");
    /*
        4. Esvaziar a �rvore pegando elementos da lista de
        refer�ncia. Desta forma � poss�vel avaliar o
        desempenho considerando os casos em que se excluem
        elementos que n�o existem na lista.
    */

    clock_t temporem; // variaveis para medir tempo
	temporem = clock();// Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos est�o ou n�o na lista
    // enquanto a lista n�o estiver vazia
    for(index = 0; index < lista.tam; index++){
        // Remove o elemento index
		if(remArvAluno(lista.lista[index], &minhaArv)){ // se foi removido
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que n�o achou
		}
	}
	temporem = clock() -  temporem; // Para o cronometro

	printf("t_rem = %lf\n", ((double)temporem)/((CLOCKS_PER_SEC/1000)));
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);
	if (listaOrd.cap <= 10){
        printf("Arvore Bin�ria de Busca em Pre-ordem\n");
        printArvAluno(minhaArv, PRE_ORDEM);
        printf("Arvore Bin�ria de Busca em Ordem\n");
        printArvAluno(minhaArv, ORDEM);
    }


    printf(" Testando uma �rvore AVL\n");
    printf("equivalente � lista ordenada anterior.\n");

	PNoArvAluno minhaArvAvl = NULL;
	clock_t t_inc; // variaveis para medir tempo
    printf("Testando inclus�o de elementos\n");
    srand(seed); // definindo a semente do sequencia rand
	t_inc = clock(); // Iniciando o cronometro
    // enquanto a lista n�o estiver cheia
    int cont1 = 0;
    int ok1;
	while(cont1 < listaOrd.cap){
        // gera um �ndice aleat�rio nos limites da lista de referencia
		index = rand()%LSIZE;
        // incluindo o elemento index, pode j� ter sido incluido
		ok1 = incArvAVLAlunoRec(lista.lista[index], &minhaArvAvl);
        if(ok1 == TRUE)
            cont1++;
	}
	t_inc = clock() - t_inc;// Para o cronometro
	printf("t_inc = %0.50lf\n", ((double)t_inc)/((CLOCKS_PER_SEC/1000)));
    if (listaOrd.cap <= LSIZE){
        printf("Arvore AVL em Pre-ordem\n");
        printArvAluno(minhaArvAvl, PRE_ORDEM);
        printf("Arvore AVL em Ordem\n");
        printArvAluno(minhaArvAvl, ORDEM);
    }

    printf("Testando busca de elementos\n");


    clock_t t_busc; // variaveis para medir tempo
	t_busc = clock(); // Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos est�o ou n�o na lista
    // percorrer todos os indices da lista de referencia
    PNoArvAluno no1;
	for(index = 0; index<LSIZE; index++){
        // Procurar o elemento index
        no1 = buscaArvAluno(minhaArvAvl, lista.lista[index].numMatricula);
		if(no1 != NULL){ // se esta na lista
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que n�o achou
		}
	}
	t_busc = clock() - t_busc;// Para o cronometro
	printf("t_bus = %lf\n", ((double)t_busc)/((CLOCKS_PER_SEC/1000)));
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);

    printf("Testando remo��o de elementos\n");
    /*
        4. Esvaziar a �rvore pegando elementos da lista de
        refer�ncia. Desta forma � poss�vel avaliar o
        desempenho considerando os casos em que se excluem
        elementos que n�o existem na lista.
    */

    clock_t t_rem; // variaveis para medir tempo
	t_rem = clock();// Iniciando o cronometro
    qIn = qOut = 0; // quantos elementos est�o ou n�o na lista
    // enquanto a lista n�o estiver vazia
    for(index = 0; index < lista.tam; index++){
        // Remove o elemento index
		if(remArvAVLAluno(lista.lista[index], &minhaArvAvl)){ // se foi removido
			qIn++; // conta que achou
		}else{ // caso contrario
			qOut++; // conta que n�o achou
		}
	}
	t_rem = clock() -  t_rem; // Para o cronometro

	printf("t_rem = %lf\n", ((double)t_rem)/((CLOCKS_PER_SEC/1000)));
    printf("Se funcionou qOut tem que ser igual a qIn.\n");
	printf("qOut = %d. qIn = %d\n", qOut, qIn);
	if (listaOrd.cap <= LSIZE){
        printf("Arvore AVL em Pre-ordem\n");
        printArvAluno(minhaArvAvl, PRE_ORDEM);
        printf("Arvore AVL em ordem\n");
        printArvAluno(minhaArvAvl, ORDEM);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"
 
#define LSIZE 10

void mostraArvore(PNoArvAluno arvore);
int estaVazia(PNoArvAluno arvore);

int main(void)
{

    TListAlunos lista, listaOrd, listaTeste;    // declarando a variável
	iniListAlunos(&lista, LSIZE, FALSE);        // inicializando a lista não ordenada
    iniListAlunos(&listaOrd, LSIZE, TRUE);      // inicializando a lista ordenada
    iniListAlunos(&listaTeste, LSIZE, FALSE);   // inicializando a lista ordenada
	geraAlunos(&lista);                         // Prenhe a lista não ordenada
    geraAlunos(&listaTeste);                    // Prenhe a lista não ordenada

    //Colocando os elementos de lista em listaOrd
    for(int i = 0; i < lista.tam; i++)
        incAluno(lista.lista[i], &listaOrd);

    PNoArvAluno minhaArv = NULL;

    // Colocando o elemento do meio de listaOrd (ordenada) como raiz da árvore
    int meio = LSIZE/2;
    int ok = incArvAluno(listaOrd.lista[meio], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Erro de inclusão !!\n");
    // Colocando os elementos de lista na árvore
    printf("Testando a Inclusão\n");
    for(int i = 0; i < lista.tam; i++){
        int ok = incArvAluno(lista.lista[i], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Elemento repetido!!\n");
    }
    printf("A lista original\n");
    printLisAluno(listaOrd.lista, lista.tam);
    printf("A lista ordenada\n");
    printLisAluno(listaOrd.lista, listaOrd.tam);
    printf("Arvore Binária de Busca em Pre-ordem\n");
    printArvAluno(minhaArv, PRE_ORDEM);
    printf("Arvore Binária de Busca em Ordem\n");
    printArvAluno(minhaArv, ORDEM);
    printf("Arvore Binária de Busca em Pos-ordem\n");
    printArvAluno(minhaArv, POS_ORDEM);

    PNoArvAluno no;

    printf("Testando a Busca\n");
    for(int i = 0; i < lista.tam; i++){
        printf("Procurando o nó %d - ", lista.lista[i].numMatricula);
        //no = buscaArvAlunoRec(minhaArv, lista.lista[i].numMatricula);
        no = buscaArvAluno(minhaArv, lista.lista[i].numMatricula);
        if(no != NULL)
            printf("achei o no %d!!! \n", no->numMatricula);
        else
            printf("não achei!!! \n");
        printf("Procurando o nó %d - ", listaTeste.lista[i].numMatricula);
        no = buscaArvAluno(minhaArv, listaTeste.lista[i].numMatricula);
        if(no != NULL)
            printf("achei o no %d!!! \n", no->numMatricula);
        else
            printf("não achei!!! \n");
    }

    printf("Testando a Remoção\n");
    for(int i = 0; i < lista.tam; i++){
    //for(int i = 0; i < 6; i++){
        printf("Removendo o nó %d - ", lista.lista[i].numMatricula);
        ok = remArvAluno(lista.lista[i], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Não achei!!\n");
        printf("Removendo o nó %d - ", listaTeste.lista[i].numMatricula);
        ok = remArvAluno(listaTeste.lista[i], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Não achei!!\n");
    }

    printf("Arvore Binária de Busca em Pre-ordem\n");    
    printArvAluno(minhaArv, PRE_ORDEM);
    printf("\n");

    return 0;
}


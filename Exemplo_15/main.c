#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"
 
#define LSIZE 10

int main(void)
{

    TListAlunos lista;                   // declarando a variável
	iniListAlunos(&lista, LSIZE, FALSE); // inicializando a lista não ordenada
    TListAlunos lista2;                  
	iniListAlunos(&lista2, LSIZE, FALSE); // inicializando a lista não ordenada
	geraAlunos(&lista);                  // Prenhe a lista não ordenada
    geraAlunos(&lista2);                  // Prenhe a lista não ordenada
    TListAlunos listaOrd;                   
	iniListAlunos(&listaOrd, LSIZE, TRUE); // inicializando a lista ordenada

    PNoArvAluno minhaArv = NULL;

    for(int i = 0; i < lista.tam; i++)
        incAluno(lista.lista[i], &listaOrd);

    int meio = LSIZE/2;
    int ok = incArvAluno(lista.lista[meio], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Error!!\n");
    
    printf("------------------------------\n");
    
    for(int i = 0; i < lista.tam; i++){
        //incAluno(lista.lista[i], &listaOrd);
        //int ok = incArvAlunoRec(lista.lista[i], &minhaArv);
        int ok = incArvAluno(lista.lista[i], &minhaArv);
        if(ok == TRUE) 
            printf("Ok\n");
        else
            printf("Error!!\n");
    }
    
    printLisAluno(lista.lista, lista.tam);
    printLisAluno(listaOrd.lista, listaOrd.tam);
    printArvAluno_1(minhaArv);
    printf("\n");
    printArvAluno_2(minhaArv);
    printf("\n");
    printArvAluno_3(minhaArv);
    printf("\n");
    
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
    }

    for(int i = 0; i < lista.tam; i++){
        printf("Procurando o nó %d - ", lista2.lista[i].numMatricula);
        //no = buscaArvAlunoRec(minhaArv, lista.lista[i].numMatricula);
        no = buscaArvAluno(minhaArv, lista2.lista[i].numMatricula);
        if(no != NULL)
            printf("achei o no %d!!! \n", no->numMatricula);
        else
            printf("não achei!!! \n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    TPilhaAlunos minhaPilha;
    TListAlunos lista;

    iniPilhaAlunos(&minhaPilha, LSIZE);
    iniListAlunos(&lista, 2*LSIZE, FALSE);

    geraAlunos(&lista);

    printLisAluno(lista.lista, lista.tam);

    for(int i = 0; i < 2*LSIZE; i++){
        if(incAlunoNaPilha(lista.lista[i], &minhaPilha))
            remAluno(lista.lista[i], &lista);
        else{
            printf("A pilha está cheia\n");
            break;
        }
    }

    printLisAluno(lista.lista, lista.tam);

    int i = 0;
    TAluno aluno;
    while(remAlunoDaPilha(&aluno, &minhaPilha)){
        incAluno(aluno, &lista);
    }

    printf("A pilha esta vazia\n");

    printLisAluno(lista.lista, lista.tam);

    TFilaAlunos minhaFila;
    iniFilaAlunos(&minhaFila, LSIZE);

    for(int i = 0; i < 2*LSIZE; i++){
        if(incAlunoNaFila(lista.lista[i], &minhaFila))
            remAluno(lista.lista[i], &lista);
        else{
            printf("A fila está cheia\n");
            break;
        }
    }

    printf("%d, %d, %d\n", minhaFila.cap, minhaFila.fim, minhaFila.ini);

    for(int i = 0; i < 5; i++){
        remAlunoDaFila(&aluno, &minhaFila);
        incAluno(aluno, &lista);
    }

    printf("%d, %d, %d\n", minhaFila.cap, minhaFila.fim, minhaFila.ini);

    for(int i = 0; i < 2*LSIZE; i++){
        if(incAlunoNaFila(lista.lista[i], &minhaFila))
            remAluno(lista.lista[i], &lista);
        else{
            printf("A fila está cheia\n");
            break;
        }
    }

    printf("%d, %d, %d\n", minhaFila.cap, minhaFila.fim, minhaFila.ini);

    printLisAluno(lista.lista, lista.tam);

    while(remAlunoDaFila(&aluno, &minhaFila)){
        incAluno(aluno, &lista);
    }

    printf("A fila esta vazia\n");
    printf("%d, %d, %d\n", minhaFila.cap, minhaFila.fim, minhaFila.ini);

    printLisAluno(lista.lista, lista.tam);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{

    PNoAluno aluno1;
    TNoAluno aluno2;

    TListAlunos lista;                   // declarando a variável
	iniListAlunos(&lista, LSIZE, FALSE); // inicializando a lista não ordenada
	geraAlunos(&lista);                  // Prenhe a lista não ordenada

    TAluno aluno; 
    
    aluno2.numMatricula = lista.lista[0].numMatricula;
    strcpy(aluno2.nome, lista.lista[0].nome);
	strcpy(aluno2.email, lista.lista[0].email);
    aluno2.prox = NULL;

    PNoAluno listaEnc;
    listaEnc = &aluno2;

    aluno1 = (PNoAluno) malloc(sizeof(TNoAluno));
    aluno1->numMatricula = lista.lista[1].numMatricula;
    strcpy(aluno1->nome, lista.lista[1].nome);
	strcpy(aluno1->email, lista.lista[1].email);
    aluno1->prox = NULL;

    listaEnc->prox = aluno1;

    aluno1 = (PNoAluno) malloc(sizeof(TNoAluno));
    aluno1->numMatricula = lista.lista[2].numMatricula;
    strcpy(aluno1->nome, lista.lista[2].nome);
	strcpy(aluno1->email, lista.lista[2].email);
    aluno1->prox = NULL;

    PNoAluno noALuno;
    noALuno = listaEnc->prox;
    noALuno->prox = aluno1;

    aluno1 = (PNoAluno) malloc(sizeof(TNoAluno));
    aluno1->numMatricula = lista.lista[3].numMatricula;
    strcpy(aluno1->nome, lista.lista[3].nome);
	strcpy(aluno1->email, lista.lista[3].email);
    aluno1->prox = NULL;

    noALuno = noALuno->prox;
    noALuno->prox = aluno1;

    noALuno = listaEnc;
    do{
        printf("%d, ", noALuno->numMatricula);
		printf("%s, ", noALuno->nome);
		printf("%s;\n ", noALuno->email);
        noALuno = noALuno->prox;
    }while(noALuno != NULL);

    printLisAluno(lista.lista, lista.tam);

    return 0;
}


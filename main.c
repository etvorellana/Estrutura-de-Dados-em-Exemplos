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
	geraAlunos(&lista);                  // Prenhe a lista não ordenada

    PNoArvAluno minhaArv;
    minhaArv = iniNoArvAluno();

    minhaArv->numMatricula = lista.lista[0].numMatricula; 
	strcpy(minhaArv->nome, lista.lista[0].nome); 	//copia aluno para novo
	strcpy(minhaArv->email, lista.lista[0].email);

    PNoArvAluno folha;
    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[1].numMatricula; 
	strcpy(folha->nome, lista.lista[1].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[1].email);

    minhaArv->esq = folha;

    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[2].numMatricula; 
	strcpy(folha->nome, lista.lista[2].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[2].email);

    minhaArv->dir = folha;

    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[3].numMatricula; 
	strcpy(folha->nome, lista.lista[3].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[3].email);

    minhaArv->dir->esq = folha;

    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[4].numMatricula; 
	strcpy(folha->nome, lista.lista[4].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[4].email);

    minhaArv->dir->dir = folha;

    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[5].numMatricula; 
	strcpy(folha->nome, lista.lista[5].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[5].email);

    minhaArv->esq->dir = folha;

    folha = iniNoArvAluno();
    
    folha->numMatricula = lista.lista[6].numMatricula; 
	strcpy(folha->nome, lista.lista[6].nome); 	//copia aluno para novo
	strcpy(folha->email, lista.lista[6].email);

    minhaArv->esq->esq = folha;

    

    return 0;
}


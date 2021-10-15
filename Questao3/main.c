#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    TAluno aluno;
    TListAlunos lista;
    TPilhaAlunos minhaPilha;
    TFilaAlunos minhaFila;
   
    iniListAlunos(&lista,LSIZE,FALSE);
    iniFilaAlunos(&minhaFila,LSIZE);
    geraAlunos(&lista);
    printf("Lista inicial: \n");
    printLisAluno(lista.lista,lista.tam);

    for(int i = 0; i < lista.tam; i++){
        incAlunoNaFila(lista.lista[i],&minhaFila);
        remAluno(lista.lista[i],&lista);
    }

    printf("Lista apos remover elementos: \n");
    printLisAluno(lista.lista,lista.tam);

    printf("Fila: \n");
    printLisAluno(minhaFila.fila,minhaFila.fim);
    

    iniPilhaAlunos(&minhaPilha,LSIZE/2);
    unsigned int matricula;
	while(minhaPilha.topo < (minhaPilha.cap)/2){
		//                  ano                       semestre               sequencial
		matricula = (2021)*100000 + 2*10000 + rand()%10000; 
		aluno.numMatricula = matricula;
  		geraNomes(&aluno);
		incAlunoNaPilha(aluno, &minhaPilha);
	}
    
    //if()
    
    return 0;
}


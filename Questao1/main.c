#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    TPilhaAlunos minhaPilha,pilhaAux;
    iniPilhaAlunos(&minhaPilha,LSIZE);
    iniPilhaAlunos(&pilhaAux,LSIZE);

    TAluno aluno;

	while(minhaPilha.topo < minhaPilha.cap){
		//                  ano                       semestre               sequencial
		int matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000; 
		aluno.numMatricula = matricula;
  		geraNomes(&aluno);
		incAlunoNaPilha(aluno, &minhaPilha);
	}
    printf("Pilha de alunos: \n");
    printLisAluno(minhaPilha.pilha,minhaPilha.topo);
    printf("Aluno para remover: 201314771\n");
    int busca = 201314771;
    
    for(int i = minhaPilha.topo - 1; 0 <= i; i--){
        if(minhaPilha.pilha[i].numMatricula == busca){
            remAlunoDaPilha(&minhaPilha.pilha[i],&minhaPilha);
            break;
        }
        else{
            remAlunoDaPilha(&minhaPilha.pilha[i],&minhaPilha);
            incAlunoNaPilha(minhaPilha.pilha[i],&pilhaAux);
        }
        if(minhaPilha.topo == 0)
            printf("Aluno não pertence a pilha\n"); 
    }

    printf("Pilha principal depois de remover: \n");
    printLisAluno(minhaPilha.pilha,minhaPilha.topo);
    printf("Pilha auxiliar: \n");
    printLisAluno(pilhaAux.pilha,pilhaAux.topo);

    for(int i = pilhaAux.topo - 1; 0 <= i; i--){
        incAlunoNaPilha(pilhaAux.pilha[i],&minhaPilha);
        remAlunoDaPilha(&aluno,&pilhaAux);
    }
    printf("Pilha final depois de remover: \n");
    printLisAluno(minhaPilha.pilha,minhaPilha.topo);
    printf("Pilha auxiliar esvaziada: \n");
    printLisAluno(pilhaAux.pilha,pilhaAux.topo);

    return 0;
}


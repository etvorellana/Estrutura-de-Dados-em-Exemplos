#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <locale.h>

#include "ferramentas.h"

#define LSIZE 3

int main(void)
{

 TPilhaAlunos minhaPilha;
    TPilhaAlunos aux;
    TAluno aluno;

    iniPilhaAlunos(&minhaPilha, LSIZE);
    iniPilhaAlunos(&aux, LSIZE);

    for (int i = 0; i<LSIZE; i++){
        printf("Digite o número de matrícula: ");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Digite o nome: ");
        gets(aluno.nome);
        printf("Digite o e-mail: ");
        gets(aluno.email);
        incAlunoNaPilha(aluno, &minhaPilha);
    }
    
    system("cls");
    printf("Pilha inicial:\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);

    int num;
    printf("Qual o aluno que você deseja remover? (Digite o número de matrícula dele): \n");
    scanf("%d", &num);

   
    int pos = minhaPilha.topo-1;
  
    for(int i = minhaPilha.topo-1; i>0;i--){

      if(minhaPilha.pilha[pos].numMatricula == num){
       remAlunoDaPilha(&aluno, &minhaPilha);
       break;
     }else{
       incAlunoNaPilha(minhaPilha.pilha[pos],&aux);
       remAlunoDaPilha(&aluno, &minhaPilha);
     }
     pos--;
    }

  
    for (int i = aux.topo-1;i>=0; i--){
        incAlunoNaPilha(aux.pilha[i], &minhaPilha);
        remAlunoDaPilha(&aux.pilha[i], &aux);
    }

    printf("Pilha final:\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);

    return 0;
}
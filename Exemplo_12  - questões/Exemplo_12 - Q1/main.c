#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>
//BIBLIOTECAS

#include "ferramentas.h"
//FERRAMENTAS 

#define LSIZE 10
//TAMANHO MAX DA PILHA

int main(void)
{
int matRem; //NUMERO DE MATRICULA DE QUEM VAI REMOVER DA PILHA.  

TPilhaAlunos pilhaP; //PILHA PRINCIPAL
TPilhaAlunos PilhaAux; //PILHA AUXILIAR
TAluno aluno; 

//Inicializndo pilhas
  iniPilhaAlunos(&pilhaP, LSIZE);
  iniPilhaAlunos(&PilhaAux, LSIZE);

printf("\n Trabalho sobre pilhas");
printf("\n");

aluno.numMatricula = 2016;
strcpy(aluno.nome,"Luciano Fernandes");
strcpy(aluno.email,"lfernandes.cic@uesc.br");
incAlunoNaPilha(aluno, &pilhaP);

aluno.numMatricula = 2017;
strcpy(aluno.nome,"Mariana Peres");
strcpy(aluno.email,"mperes.cic@uesc.br");
incAlunoNaPilha(aluno, &pilhaP);

aluno.numMatricula = 2018;
strcpy(aluno.nome,"Julia Moura");
strcpy(aluno.email,"jmoura.cic@uesc.br");
incAlunoNaPilha(aluno, &pilhaP);

aluno.numMatricula = 2019;
strcpy(aluno.nome,"Bento Fontes");
strcpy(aluno.email,"bfontes.cic@uesc.br");
incAlunoNaPilha(aluno, &pilhaP);

aluno.numMatricula = 2020;
strcpy(aluno.nome,"Mila Gutierrez");
strcpy(aluno.email,"mgutierrez.cic@uesc.br");
incAlunoNaPilha(aluno, &pilhaP);

printf("\n Alunos empilhados: ");
printLisAluno(pilhaP.pilha, pilhaP.topo);

printf("\nNum de matricula do aluno que deseja remover:");
scanf("\t %d", &matRem);
int posicao = pilhaP.topo;

while(pilhaP.topo > 0){
 posicao--;

 if(pilhaP.pilha[posicao].numMatricula == matRem){
  remAlunoDaPilha(&aluno, &pilhaP);
  break;
 }
 else{
  incAlunoNaPilha(pilhaP.pilha[posicao], &PilhaAux);
  remAlunoDaPilha(&aluno, &pilhaP);
 }
}

//DEVOLVE ALUNOS GUARDADOS EM PILHA AUXILIAR PRA PILHA PRINCIPAL
for (int i = PilhaAux.topo-1; i >= 0; i--){

  incAlunoNaPilha(PilhaAux.pilha[i], &pilhaP);

  remAlunoDaPilha(&PilhaAux.pilha[i], &PilhaAux);
}

printf("Pilha após remocao: \n");
printLisAluno(pilhaP.pilha, pilhaP.topo);

return 0;
}
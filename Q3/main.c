#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 3

int main(void)
{
  //Declaração das variáveis
   TAluno aluno;
   TListAlunos lista;
   TPilhaAlunos cal;
   TFilaAlunos vet;

   //Inicializando lista não ordenada, pilha e fila.
   iniListAlunos(&lista, LSIZE, FALSE);
   iniPilhaAlunos(&cal, LSIZE);
   iniFilaAlunos(&vet, LSIZE);

   //Inserindo alunos na lista, pelo user
   for (int i = 0; i<LSIZE; i++){
        printf("Digite o número de matrícula: ");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Digite o nome: ");
        gets(aluno.nome);
        printf("Digite o e-mail: ");
        gets(aluno.email);
        incLisAluno(aluno, lista.lista, &lista.tam);
    }

  printf("Lista original\n");
  printLisAluno(lista.lista, lista.tam);

  /*
  num matricula menor do q 202120000, é veterano
  */

  for(int i = 0; i<lista.tam; i++ ){
    if(lista.lista[i].numMatricula >= 202120000){
      incAlunoNaPilha(lista.lista[i], &cal);
    }else{
      incAlunoNaFila(lista.lista[i], &vet);
    }
  }

  printf("Lista dos calouros:\n");
  printLisAluno(cal.pilha, cal.topo);
  printf("Lista dos veteranos\n");
  printLisAluno(vet.fila, vet.fim);

/*
 pos - tamanho da lista
 pos2 - pilha de calouro
 percorre o for
 primeiro o vet
 depois que essa condição for satisfeita
 add cal
 */
 int pos = lista.tam;
 int pos2 = cal.topo;
  lista.tam = 0;
  for(int i = 0; i<pos;i++){
    if(vet.ini != vet.fim){
   incLisAluno(vet.fila[i],lista.lista, &lista.tam);
   remAlunoDaFila(&vet.fila[i], &vet);
    }else{
      pos2--;
  incLisAluno(cal.pilha[pos2],lista.lista, &lista.tam);
  remAlunoDaPilha(&cal.pilha[pos2],&cal);
    }
  }
  printf("Tamanho da lista = %d\n", lista.tam);
  printLisAluno(lista.lista, lista.tam);
    return 0;
}

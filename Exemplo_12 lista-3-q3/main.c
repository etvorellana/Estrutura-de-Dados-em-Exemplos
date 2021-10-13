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

TAluno aluno;
   TListAlunos lista;
   TPilhaAlunos calouros;
   TFilaAlunos veteranos;

   iniListAlunos(&lista, LSIZE, FALSE);
   iniPilhaAlunos(&calouros, LSIZE);
   iniFilaAlunos(&veteranos, LSIZE);

   aluno.numMatricula = 20192034;
   strcpy(aluno.nome, "Larissa Mendes");
   strcpy(aluno.email, "lcmdendes.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  aluno.numMatricula = 202145324;
   strcpy(aluno.nome, "Ana");
   strcpy(aluno.email, "Ana.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 201745314;
   strcpy(aluno.nome, "Luan santana");
   strcpy(aluno.email, "luanzito.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 202178547;
   strcpy(aluno.nome, "cascão");
   strcpy(aluno.email, "cascão.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  aluno.numMatricula = 201720720;
   strcpy(aluno.nome, "Castiel");
   strcpy(aluno.email, "Castiel.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 202124510;
   strcpy(aluno.nome, "Jensen ackles");
   strcpy(aluno.email, "Dean.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  printf("Exibindo lista\n");
  printLisAluno(lista.lista, lista.tam);
  
  for(int i = 0; i<lista.tam; i++ ){
    if(lista.lista[i].numMatricula >= 202120000){
      incAlunoNaPilha(lista.lista[i], &calouros);
    }else{
      incAlunoNaFila(lista.lista[i], &veteranos);
    }
  }

  printf("Pilha dos calouros\n");
  printLisAluno(calouros.pilha, calouros.topo);
  printf("Fila dos veterano\n");
  printLisAluno(veteranos.fila, veteranos.fim);

 int pos = lista.tam;
 int pos2 = calouros.topo;
  lista.tam = 0;
  for(int i = 0; i<pos;i++){
    
    if(veteranos.ini != veteranos.fim){
   incLisAluno(veteranos.fila[i],lista.lista, &lista.tam);
   remAlunoDaFila(&veteranos.fila[i], &veteranos);
    }else{
      pos2--;
  incLisAluno(calouros.pilha[pos2],lista.lista, &lista.tam);
  remAlunoDaPilha(&calouros.pilha[pos2],&calouros);
    }
  }
  printf("Tamanho da lista = %d\n", lista.tam);
  printLisAluno(lista.lista, lista.tam);
    return 0;
    }
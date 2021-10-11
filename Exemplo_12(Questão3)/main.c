#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
  //Declaração das variaveis que serao utilizadas
   TAluno aluno;
   TListAlunos lista;
   TPilhaAlunos calouros;
   TFilaAlunos veteranos;

   //Inicia: lista not Ord, pilha e fila.
   iniListAlunos(&lista, LSIZE, FALSE);
   iniPilhaAlunos(&calouros, LSIZE);
   iniFilaAlunos(&veteranos, LSIZE);

   //Inserindo alguns alunos na lista
   aluno.numMatricula = 201920227;
   strcpy(aluno.nome, "Alessandro");
   strcpy(aluno.email, "acsantos.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  aluno.numMatricula = 202120227;
   strcpy(aluno.nome, "Fulano");
   strcpy(aluno.email, "Fulano.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 201820227;
   strcpy(aluno.nome, "Jair");
   strcpy(aluno.email, "Jair.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 201920727;
   strcpy(aluno.nome, "Vava");
   strcpy(aluno.email, "Vvar.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  aluno.numMatricula = 202120010;
   strcpy(aluno.nome, "Cicrano");
   strcpy(aluno.email, "Cicrano.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

   aluno.numMatricula = 202120090;
   strcpy(aluno.nome, "Otavio");
   strcpy(aluno.email, "Otavio.cic@uesc.br");
   incLisAluno(aluno, lista.lista, &lista.tam);

  printf(">>>EXIBINDO LISTA ORIGINAL<<<\n");
  printLisAluno(lista.lista, lista.tam);

  /*
   -> Se o numero de matrcula for maior ou igual a duzentos e dois milhões cento e vinte mil é considerado calouro. Caso contrario é veterano.
  */
  
  for(int i = 0; i<lista.tam; i++ ){
    if(lista.lista[i].numMatricula >= 202120000){
      incAlunoNaPilha(lista.lista[i], &calouros);
    }else{
      incAlunoNaFila(lista.lista[i], &veteranos);
    }
  }

  printf(">>>EXIBINDO PILHA DOS CALOUROS <<<<\n");
  printLisAluno(calouros.pilha, calouros.topo);
  printf(">>>EXIBINDO FILA DOS VETERANOS <<<<\n");
  printLisAluno(veteranos.fila, veteranos.fim);

/*
 -> Inclusão na lista ORIGINAL
 -> pos: variavel que recebe o tamanho da lista.
 -> pos2: reponsavel por acessar os indices da pilha, recebe o valor do topo da pilha;
 -> Começo da logica: Ao chega nesse ponto temos a lista já preenchida com alguns alunos, por isso é necessario fazer com que a lista fique vazia para conseguirmos preenche-la com os alunos. De forma prática faço lista.tam=0 para conseguir inserir os alunos novamente na lista.

  ->if() Os veteranos são os primeiros a serem incluidos na lista. Temos que se inicio = fim de uma fila ela está vazia, entao incluimos os alunos da fila na lista até que essa condição seja satisfeita. Apos incluir acontece a remoção.
  -> else() Apos a condiçao da lista ter sido satisfeita entao podemos incluir os alunos contidos na pilha.
*/
 int pos = lista.tam;
 int pos2 = calouros.topo;
  lista.tam = 0;
  for(int i = 0; i<pos;i++){
    //Primeiro os veteranos
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


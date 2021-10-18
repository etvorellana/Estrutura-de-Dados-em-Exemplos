#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>
//BIBLIOTECAS

#include "ferramentas.h"
//FERRAMENTAS

#define LSIZE 5
//DEFININDO CAPACIDADE MAX

int main(void){

int opcao; //OPCIONAL DO MENU

TAluno aluno;
TListAlunos lisAlunos;
TFilaAlunos f;
// DECLARANDO VARIAVEIS DO TIPO ESTRUTURA

iniListAlunos(&lisAlunos, LSIZE, FALSE);
iniFilaAlunos(&f, LSIZE);
// INICIALIZANDO A FILA E A LISTA

do{

 printf("\nSeja bem vindx ao Laboratorio!");
 printf("\nO que deseja fazer?");

 printf("\n1 - Fazer registro.");
 printf("\n2 - Checar alunos no laboratorio.");
 printf("\n3 - Checar alunos na fila.");
 printf("\n4 - Remover aluno do laboratorio.");
 printf("\n5 - Sair.");
 scanf("%i", &opcao);

switch(opcao){

  case 1:
  system("clear");

  printf("Numero de matricula no aluno: \t");
  scanf("%d", &aluno.numMatricula);
  printf("\nNome do aluno:");
  scanf("%c", aluno.nome);
  fflush(stdin);
  printf("\nInfrome o email:");
  scanf("%c", aluno.email);
  fflush(stdin);

 if (incAluno(aluno,&lisAlunos) == FALSE) {
   printf("\nNao foi possivel adicionar aluno \nPortanto, elx vai aguardar na fila");
  if(incAlunoNaFila(aluno, &f) == FALSE){
  printf("Fila de espera cheia\n");
   }
 }
break;

case 2:
  system("clear");

  printf("\nAlunos que estao no laboratorio");
  printLisAluno(lisAlunos.lista, lisAlunos.tam);
  break;

case 3:
 system("clear");
 printf("Alunos na Fila de Espera: ");
 printFila(f);
 break;
//PEGUEI DE UM COLEGA ESSA FUNÇÃO PRINTAR FILA

case 4:
 system("clear");
 printf("\n Registro de saida.");
 printf("Numero de matricula de quem esta saindo:\n");
 scanf("%d", &aluno.numMatricula);

if(remAluno(aluno, &lisAlunos) == FALSE){
  printf("O aluno %d nao esta no laboratorio\n", aluno.numMatricula);
}

else {
  if(f.fim == f.ini){
  f.fim = 0;
  f.ini = 0;
  printf("A fila está vazia\n");
}

else{
if(incAluno(f.fila[f.ini], &lisAlunos) == TRUE){
  printf("\nO aluno %d pode acessar o laboratorio.",f.fila[f.ini].numMatricula);

if(remAlunoDaFila(f.fila, &f) == TRUE){
  f.fila[f.ini-1] = f.fila[f.ini];
  f.ini --;
  f.fim--;
    }  
   } 
 }
}
break;

case 5:
system("clear");
printf("\nObrigado pela preferencia!!");
break;

default:
system("clear");
printf("\nOpcao inexistente, selecione uma do menu.");

   }
}
 while(opcao != 5);

return 0;
}
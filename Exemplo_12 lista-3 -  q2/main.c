#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10
#define size 2


int main(void)
{

  TAluno alunos;
  TListAlunos lista;
  TFilaAlunos fila;

  iniListAlunos(&lista, LSIZE, FALSE);
  iniFilaAlunos(&fila, LSIZE);

   int opcao; 

  while('true') {
   printf("Laboratorio alguma coisa\n");
   printf("1 - Registrar aluno no laboratorio\n");
   printf("2 - Listar alunos\n");
   printf("3 - Lista de alunos na fila\n");
   printf("4 - Remover um aluno do laboratorio\n");
   printf("5 - Sair\n");

   scanf("%d", &opcao);

    if (opcao == 5) {
      printf("\nAté logo!");
        return 0;
    }

     switch(opcao){

        case 1:
        printf("Cadastro\n");
        printf("Infrome o numero de matricula: \n");
        scanf("%d", &alunos.numMatricula);
        printf("Nome do aluno: \n");
        fgets(alunos.nome, 50, stdin);
        printf("Email do aluno: \n");
        fgets(alunos.email, 50, stdin);

        if(incAluno(alunos,&lista) == FALSE){
           printf("A lista está cheia, movido para espera\n");
        }

        system("clear");
        break;

        case 2:
        printf("Alunos no laboratorio\n");
        printLisAluno(lista.lista, lista.tam);
        system("clear");
        break;

        case 3:
        system("cls");
        printf(" Alunos na fila de espera\n");
        printFilaAlunos(fila);
        break;

        case 4:
        system("cls");
        printf("Saída do aluno\n");
        printf("Informe número de matricula:\n");
        scanf("%d", &alunos.numMatricula);

         if(remAluno(alunos, &lista) == FALSE){
          printf("Aluno %d nao encontrado!\n", alunos.numMatricula);
        }else{
          if(fila.fim == fila.ini){
            fila.fim = 0;
            fila.ini = 0;
            printf("A fila está vazia\n");
          }else{
            if(incAluno(fila.fila[fila.ini], &lista) == TRUE){
         printf("Aluno %d pode acessar o laboratorio!\n",fila.fila[fila.ini].numMatricula);
  
          if(remAlunoDaFila(fila.fila, &fila) == TRUE){
            fila.fila[fila.ini-1] =fila.fila[fila.ini];
            fila.ini --;
            fila.fim--;

             system("cls");
          }
        }
      }
    }
        break;

        case 5:
       // system("clear");
        printf("Até a próxima!\n");
        break;

        default:
        printf("opção invalida");

  }
    return 0;
}
}

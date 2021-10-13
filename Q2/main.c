#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <locale.h>

#include "ferramentas.h"

#define LSIZE 2

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    //Criação das variaveis
    TAluno aluno;
    TListAlunos lista;
    TFilaAlunos fila;

    //Inicialização da lista e fila
    iniListAlunos(&lista, LSIZE, FALSE);
    iniFilaAlunos(&fila, LSIZE);


    int op;

    do{
      //opções do user
      printf("Laboratório dos jogadores de LoL\n");
      printf("1- Registrar alunos no laboratório\n");
      printf("2- Listar alunos no laboratório\n");
      printf("3- Listar alunos na fila de espera\n");
      printf("4- Remover aluno do laboratório\n");
      printf("5- Sair do programa \n");
      scanf("%d", &op);
//cada caso
      switch(op){
        case 1:
       system("cls");
        printf("Registro do aluno \n");
        printf("Informe o número de matrícula: \n");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Informe o nome: \n");
        gets(aluno.nome);
        printf("Informe o email: \n");
        gets(aluno.email);
   /*if(incAluno(aluno,&lista)==FALSE &&incAluno(aluno,&lista) == aluno.numMatricula){
        printf("Aluno já está na lista.");
        return 0;
        */
        if(incAluno(aluno,&lista)==FALSE){
        printf("A lista está cheia.\n");
        printf("Aluno movido para a fila de espera\n");

        if(incAlunoNaFila(aluno, &fila) == FALSE){
          printf("A Fila de espera está cheia\n");
        }
        }

        break;

        case 2:
        system("cls");
      printf("Alunos no laboratório\n");
        printLisAluno(lista.lista, lista.tam);
        break;

        case 3:
        system("cls");
    printf(" Alunos na fila de espera\n");
        printFila(fila);
        break;

        case 4:
        system("cls");
        printf("Saída do aluno\n");
        printf("Informe número de matricula:\n");
        scanf("%d", &aluno.numMatricula);
      /*
      se der false, o aluno não ta na lista
      se fim == ini, não tem elementos pra incluir
      se fim != ini tem elementos
      se a inclusão for bem-sucedida aparece a msg de acesso ao aluno
     */
        if(remAluno(aluno, &lista) == FALSE){
          printf("Aluno %d nao encontrado!\n", aluno.numMatricula);
        }else{
          if(fila.fim == fila.ini){
            fila.fim = 0;
            fila.ini = 0;
            printf("A fila está vazia\n");
          }else{
            if(incAluno(fila.fila[fila.ini], &lista) == TRUE){
         printf("Aluno %d tem acesso ao laboratorio!\n",fila.fila[fila.ini].numMatricula);
         /*
         se a remoção for bem-sucedida
         utilizo dos decrementos para mover a fila
         */
          if(remAlunoDaFila(fila.fila, &fila) == TRUE){
            fila.fila[fila.ini-1] =fila.fila[fila.ini];
            fila.ini--;
            fila.fim--;
          }
            }
          }

        }
        break;

        case 5:
        system("cls");
        printf("Beijos de luz\n");
        break;

        default:
        system("cls");
        printf("Opção inválida, tente novamente\n");


      }
    }while(op != 5);
    //término do programa
    return 0;
}

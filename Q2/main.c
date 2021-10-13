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
    //Cria��o das variaveis
    TAluno aluno;
    TListAlunos lista;
    TFilaAlunos fila;

    //Inicializa��o da lista e fila
    iniListAlunos(&lista, LSIZE, FALSE);
    iniFilaAlunos(&fila, LSIZE);


    int op;

    do{
      //op��es do user
      printf("Laborat�rio dos jogadores de LoL\n");
      printf("1- Registrar alunos no laborat�rio\n");
      printf("2- Listar alunos no laborat�rio\n");
      printf("3- Listar alunos na fila de espera\n");
      printf("4- Remover aluno do laborat�rio\n");
      printf("5- Sair do programa \n");
      scanf("%d", &op);
//cada caso
      switch(op){
        case 1:
       system("cls");
        printf("Registro do aluno \n");
        printf("Informe o n�mero de matr�cula: \n");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Informe o nome: \n");
        gets(aluno.nome);
        printf("Informe o email: \n");
        gets(aluno.email);
   /*if(incAluno(aluno,&lista)==FALSE &&incAluno(aluno,&lista) == aluno.numMatricula){
        printf("Aluno j� est� na lista.");
        return 0;
        */
        if(incAluno(aluno,&lista)==FALSE){
        printf("A lista est� cheia.\n");
        printf("Aluno movido para a fila de espera\n");

        if(incAlunoNaFila(aluno, &fila) == FALSE){
          printf("A Fila de espera est� cheia\n");
        }
        }

        break;

        case 2:
        system("cls");
      printf("Alunos no laborat�rio\n");
        printLisAluno(lista.lista, lista.tam);
        break;

        case 3:
        system("cls");
    printf(" Alunos na fila de espera\n");
        printFila(fila);
        break;

        case 4:
        system("cls");
        printf("Sa�da do aluno\n");
        printf("Informe n�mero de matricula:\n");
        scanf("%d", &aluno.numMatricula);
      /*
      se der false, o aluno n�o ta na lista
      se fim == ini, n�o tem elementos pra incluir
      se fim != ini tem elementos
      se a inclus�o for bem-sucedida aparece a msg de acesso ao aluno
     */
        if(remAluno(aluno, &lista) == FALSE){
          printf("Aluno %d nao encontrado!\n", aluno.numMatricula);
        }else{
          if(fila.fim == fila.ini){
            fila.fim = 0;
            fila.ini = 0;
            printf("A fila est� vazia\n");
          }else{
            if(incAluno(fila.fila[fila.ini], &lista) == TRUE){
         printf("Aluno %d tem acesso ao laboratorio!\n",fila.fila[fila.ini].numMatricula);
         /*
         se a remo��o for bem-sucedida
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
        printf("Op��o inv�lida, tente novamente\n");


      }
    }while(op != 5);
    //t�rmino do programa
    return 0;
}

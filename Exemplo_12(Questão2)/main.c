#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 2

int main(void)
{
    //Criação das variaveis
    TAluno aluno;
    TListAlunos lista;
    TFilaAlunos fila;

    //Inicialização da lista e da fila
    iniListAlunos(&lista, LSIZE, FALSE);
    iniFilaAlunos(&fila, LSIZE);
    
    
    int op;

    do{
      printf("========================\n");
      printf("Laboratorio Filho Chora\n");
      printf("      Mãe Não Vê     \n");
      printf("========================\n");

      printf("[1] Registrar no laboratorio\n");
      printf("[2] Listar alunos no laboratorio\n");
      printf("[3] Listar alunos na fila\n");
      printf("[4] Remover um aluno do laboratorio\n");
      printf("[5] Sair do programa \n");
      scanf("%d", &op);

      switch(op){
        case 1:
        system("clear");
        printf(">>> Tela de registro <<<\n");
        printf("Infrome o numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        printf("Infrome o nome: \n");
        scanf("%s", aluno.nome);
        printf("Infrome o email: \n");
        scanf("%s", aluno.email);
 /*Se ele retona FALSE é por 2 motivos
1°Já tem aluno com o mesmo numero de matricula
2° A lista se encontra cheia

Falta melhorar pois se ele encontra um aluno que ja se encotra na lista, ele move esse aluno para a lista de espera.
*/
        if(incAluno(aluno,&lista)== FALSE){
        printf("A lista está cheia...\n");
        printf("Aluno movido para a fila de espera\n");
        if(incAlunoNaFila(aluno, &fila) == FALSE){
          printf("A Fila de espera está cheia\n");
        }
        }
        break;

        case 2:
        system("clear");
      printf(">>> Exibindo alunos no laboratorio <<<\n");
        printLisAluno(lista.lista, lista.tam);
        break;

        case 3:
        system("clear");
    printf(">>> Exibindo alunos na Fila de Espera <<<\n");
        /*
          Criei essa função de printar fila so para testes, devo remove-la depois.
        
        */
        printFila(fila);
        break;

        case 4:
        system("clear");
        printf(">>> Registro de saída <<<\n");
        printf("Informe numero de matricula:\n");
        scanf("%d", &aluno.numMatricula);
      /*
      -> Se remAluno retonar FALSE é pq o aluno nao faz parte da fila de espera
      ->Se retorna TRUE signfica que o aluno faz parte da fila de espera, então é removido e acontece uma verifição: se fim == ini significa que a fila está vazia e nao tem alunos para incluir no laboratorio,os valores de ini e fim são zerados.
      -> Se fim != ini entao existem elementos na fila portanto podemos move-los. Se a inclusao foi bem realizada uma mensagem informando qual aluno tem acesso ao laboratorio é mostrada.
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
         ->Sempre que manipulamos filas, os valores de fim e ini vao aumentando, neste exemplo estava tendo problemas pois para incluir. Tomando como por exemplo:
         capacidade = 2
         ini = 2
         fim = 3
        O modulo de 3 mod 2 = 1, seria impossivel inserir nessa posição. A solução que encontrei foi mover os elemntos da filha um posição para a esqueda toda vez que algum elemento é removido e decrementar fim e ini.
         */
          if(remAlunoDaFila(fila.fila, &fila) == TRUE){
            fila.fila[fila.ini-1] =fila.fila[fila.ini];
            fila.ini --;
            fila.fim--;
          }
            }
          }
          
        }
        break;

        case 5:
        system("clear");
        printf("Até a próxima!\n");
        break;

        default:
        system("clear");
        printf("Opção invalida tente novamente\n");


      }
    }while(op != 5);


    

    return 0;
}


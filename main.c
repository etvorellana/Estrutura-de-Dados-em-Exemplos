#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int main(void)
{
    TListAlunos lista;
    TAluno aluno;
    //Incializa a lista
    iniListAlunos(&lista, LSIZE, FALSE);
    
    printf("============================\n");
    printf("     Listas sequencias\n");
    printf("============================\n");
    int op;

    do{
      printf("[1] Para Inserir Nao Ordenado\n");
      printf("[2] Para Inserir Ordenado\n");
      printf("[3] Para Remover Nao Ordenado\n");
      printf("[4] Para Remover Ordenado\n");
      printf("[5] Para Sair\n");
      scanf("%d", &op);

      switch(op){
        case 1:
        lista.eOrd =FALSE;
        printf("Informe numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        printf("Informe o nome: \n");
        scanf("%s", aluno.nome);
        printf("Informe o email: \n");
        scanf("%s", aluno.email);
        if(incAluno(aluno, &lista) == FALSE){
      printf("Aluno %d ja se econtra na lista\n", aluno.numMatricula);
        }
        printLisAluno(lista.lista, lista.tam);
         mostraTamanhopAndCap(lista);
        break;

         case 2:
         lista.eOrd = TRUE;
        printf("Informe numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        printf("Informe o nome: \n");
        scanf("%s", aluno.nome);
        printf("Informe o email: \n");
        scanf("%s", aluno.email);
        if(incAluno(aluno, &lista) == FALSE){
      printf("Aluno %d ja se econtra na lista\n", aluno.numMatricula);
        }
        printLisAluno(lista.lista, lista.tam);
        mostraTamanhopAndCap(lista);
        break;

        case 3:
        printf("Informe o numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        if(remAluno(aluno,&lista)== FALSE){
      printf("Aluno não encontrado\n");
    }
        printLisAluno(lista.lista, lista.tam);
         mostraTamanhopAndCap(lista);
        break;

        case 4:
        printf("Informe o numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        if(remAluno(aluno,&lista)== FALSE){
      printf("Aluno não encontrado\n");
    }
        printLisAluno(lista.lista, lista.tam);
         mostraTamanhopAndCap(lista);
        break;

         case 5:
        printf("Ate a proxima!\n");
        break;

        default:
        printf("Ops.... Opçao invalida tente outra vez!\n");
        break;

      }//Fim do switch

    }while(op != 5);
    
    
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int main(void)
{
    int tamLista, capLista;
    /* capLista - Capacidade da lista.  Limite máximo de elememtos
        que podem ser aramzenados na lista. Pode ser entendido como
        o tamanho do array
    */
    capLista = LSIZE;
    /* tamLista - Tamanho da lista
        * tamLista == 0: Lista vazia
        * tamLista == capLista: Lista cheia
    */
    tamLista = 0;
    // Uma lista como uma array alocado estaticamente
    TAluno lista[LSIZE];

    //printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br   
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */

    // Adicionando o primeiro elemento na lista
    TAluno aluno;
  
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
        printf("Informe numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        printf("Informe o nome: \n");
        scanf("%s", aluno.nome);
        printf("Informe o email: \n");
        scanf("%s", aluno.email);
        incLisAluno(aluno,lista, &tamLista);
        printLisAluno(lista,tamLista);
        break;

        case 2:
        printf("Informe numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        printf("Informe o nome: \n");
        scanf("%s", aluno.nome);
        printf("Informe o email: \n");
        scanf("%s", aluno.email);
        if(incLisAlunoOrd(aluno, lista, &tamLista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
        printLisAluno(lista,tamLista);
        break;

        case 3:
        printf("Informe o numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        if(remAlunoOrd(aluno,lista, &tamLista)== FALSE){
      printf("Aluno não encontrado\n");
    }
        printLisAluno(lista,tamLista);
        break;
        
        case 4:
        printf("Informe o numero de matricula: \n");
        scanf("%d", &aluno.numMatricula);
        if(remAlunoOrd(aluno,lista, &tamLista)== FALSE){
      printf("Aluno não encontrado\n");
    }
        printLisAluno(lista,tamLista);
        break;

        case 5:
        printf("Ate a proxima!\n");
        break;

        default:
        printf("Ops.... Opçao invalida tente outra vez!\n");
        break;
      }
      
    }while (op != 5);

    return 0;
}


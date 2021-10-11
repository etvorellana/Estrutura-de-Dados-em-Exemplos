#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    //Declaração de algumas variaveis
    TPilhaAlunos minhaPilha;
    TPilhaAlunos aux;
    TAluno aluno;

    //Inicialização das pilhas
    iniPilhaAlunos(&minhaPilha, LSIZE);
    iniPilhaAlunos(&aux, LSIZE);

    printf("===========================\n");
    printf("   Trabalhando com Pilhas \n");
    printf("===========================\n");
    printf(">>> Exibindo lista inicial <<<\n");

    /*
     Inclusão de alguns alunos para comprovar
     o funcionamento do código.
    */
    aluno.numMatricula = 1;
    strcpy(aluno.nome,"Teste");
    strcpy(aluno.email,"Teste@gmail.com");
    incAlunoNaPilha(aluno, &minhaPilha);

     aluno.numMatricula = 2;
    strcpy(aluno.nome,"Oi");
    strcpy(aluno.email,"Oi@gmail.com");
    incAlunoNaPilha(aluno, &minhaPilha);

    aluno.numMatricula = 3;
    strcpy(aluno.nome,"Oliveira");
    strcpy(aluno.email,"Oliveiral@gmail.com");
    incAlunoNaPilha(aluno, &minhaPilha);

    aluno.numMatricula = 4;
    strcpy(aluno.nome,"Alessandro");
    strcpy(aluno.email,"Ale@gmail.com");
    incAlunoNaPilha(aluno, &minhaPilha);

    printLisAluno(minhaPilha.pilha, minhaPilha.topo);
    printf("------------------------------------\n");

    //Utilizada para armazenar a escolha do usuario
    int num;
    printf("Informe o numero de matricula do aluno que deseja remover: \n");
    scanf("%d", &num);
    
    /*
    -> Pos é uma variavel fundamnetal, pois ela é a 
    responsavel por acessar os indices da pilha para que sejam realizadas as comparaçoes e inclusoes em outra pilha.

    ->Pos  recebe o valor do topo da pilha e logo é decrementada pois o topo indica sempre onde dever ser incluido um novo elemento, logo  em pilha[topo] nao "existe nada", logo deve ser decrementada para fazer referencia ao ultimo elemento inserido. Ficando pilha[topo-1].
    */
    int pos = minhaPilha.topo;
   /*
   -> Em cada volta do for existe uma comparação:
  ->If() caso a comparação seja veraddeira, remove o aluno da pilha, pois é o aluno que o usuário deseja remover e não há necessidade de procurar no restante da pilha (levando em consideração que não haverá elemntos repetidos na pilha), logo em seguida acontece um break e o laço for é finalizado.

  ->Else() significa que a comparação do if foi falsa, entao é feita a inclusão desse aluno em um pilha auxiliar que será utilizada para armazenar os alunos que tem o numero de matricula diferente do informado pelo usuario, logo apos ocorre a remoção na pilha original.
   */
    for(int i = minhaPilha.topo; i>0;i--){
      pos--;
      if(minhaPilha.pilha[pos].numMatricula == num){
       remAlunoDaPilha(&aluno, &minhaPilha);
       break;
     }else{
       incAlunoNaPilha(minhaPilha.pilha[pos],&aux);
       remAlunoDaPilha(&aluno, &minhaPilha);
     }
    }

    /*
    -> Ocorre a inclusão dos elemetos da pilha auxiliar na pilha original. Mantendo a pilha na mesma ordem, somente com a ausencia do aluno informado pelo usuario, caso ele exista na pilha.

    -> A pilha auxiliar tbm é esvaziada ao final.
    */
    for (int i = aux.topo-1;i>=0; i--){
        incAlunoNaPilha(aux.pilha[i], &minhaPilha);
        remAlunoDaPilha(&aux.pilha[i], &aux);
    }

    printf(">>>Exibindo Pilha Final<<<<\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);

   /*
   -> SUGESTÃO: Caso o usuario digite um numero de matricula que nao existe, nada é exibido informando que o numero nao foi encotrado. Caso isso aconteça colocar uma mensagem informando que o numero infomando nao existe na pilha.
   
   */

    return 0;
}
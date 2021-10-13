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
    setlocale(LC_ALL, "portuguese");

    TPilhaAlunos minhaPilha;
    TPilhaAlunos aux;
    TAluno aluno;

    //Inicio das pilhas
    iniPilhaAlunos(&minhaPilha, LSIZE);
    iniPilhaAlunos(&aux, LSIZE);


    //Inclui alunos pelo usuário
    for (int i = 0; i<LSIZE; i++){
        printf("Digite o número de matrícula: ");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Digite o nome: ");
        gets(aluno.nome);
        printf("Digite o e-mail: ");
        gets(aluno.email);
        incAlunoNaPilha(aluno, &minhaPilha);
    }
    //limpa a tela
    system("cls");
    printf("Pilha inicial:\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);


    //Recebe numero que o usuario deseja remover
    int num;
    printf("Qual o aluno que você deseja remover? (Digite o número de matrícula dele): \n");
    scanf("%d", &num);

    /*
     Posição: responsável para que tudo aconteça, comparações e modificações
     Posição: recebe o valor do topo da pilha -1, pois pilha[topo] ou possui nada ou possui "lixo"
    */
    int pos = minhaPilha.topo-1;
   /*
    if dentro do for - para a primeira opção, pois não precisaria usar variável auxiliar. para a outra opção, há a inclusão da variável na pilha auxiliar e a remoção dela na minhaPilha
   */
    for(int i = minhaPilha.topo-1; i>0;i--){

      if(minhaPilha.pilha[pos].numMatricula == num){
       remAlunoDaPilha(&aluno, &minhaPilha);
       break;
     }else{
       incAlunoNaPilha(minhaPilha.pilha[pos],&aux);
       remAlunoDaPilha(&aluno, &minhaPilha);
     }
     pos--;
    }

    /*
    Elementos da auxiliar na original
    Auxiliar esvaziada
    */
    for (int i = aux.topo-1;i>=0; i--){
        incAlunoNaPilha(aux.pilha[i], &minhaPilha);
        remAlunoDaPilha(&aux.pilha[i], &aux);
    }

    printf("Pilha final:\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);

    return 0;
}
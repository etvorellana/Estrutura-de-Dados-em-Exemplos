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
    //Declara��o das variaveis
    TPilhaAlunos minhaPilha;
    TPilhaAlunos aux;
    TAluno aluno;

    //Inicializa��o das pilhas
    iniPilhaAlunos(&minhaPilha, LSIZE);
    iniPilhaAlunos(&aux, LSIZE);


    //inclus�o de alunos pelo usu�rio
    for (int i = 0; i<LSIZE; i++){
        printf("Digite o n�mero de matr�cula: ");
        scanf("%d", &aluno.numMatricula);
        fflush(stdin);
        printf("Digite o nome: ");
        gets(aluno.nome);
        printf("Digite o e-mail: ");
        gets(aluno.email);
        incAlunoNaPilha(aluno, &minhaPilha);
    }
    //limpeza da tela
    system("cls");
    printf("Pilha inicial:\n");
    printLisAluno(minhaPilha.pilha, minhaPilha.topo);


    //Numero que o usuario quer remover
    int num;
    printf("Qual o aluno que voc� deseja remover? (Digite o n�mero de matr�cula dele): \n");
    scanf("%d", &num);

    /*
    => Pos - respons�vel para que tudo aconte�a, compara��es e modifica��es
    => Pos recebe o valor do topo da pilha -1, pois pilha[topo] ou possui nada ou possui "lixo"
    */
    int pos = minhaPilha.topo-1;
   /*
    if dentro do for - para a primeira op��o, pois n�o precisaria usar
   vari�vel auxiliar. para a outra op��o, h� a inclus�o da vari�vel na
   pilha auxiliar e a remo��o dela na minhaPilha
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

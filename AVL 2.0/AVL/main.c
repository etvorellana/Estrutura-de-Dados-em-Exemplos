#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ferramentas.h"
#include <locale.h>
#include <time.h>

int main(void) {
    setlocale(LC_ALL, "portuguese");
    clock_t t;
  int op;
  int num;
  TAluno aluno;
  No *arv = NULL;
  No *busca = NULL;

  do{
    printf("=============================\n");
    printf(" Trabalhando com arvores AVL\n");
    printf("=============================\n\n");

    printf("[1] Para inserir\n");
    printf("[2] Para remoção\n");
    printf("[3] Para imprimir\n");
    printf("[4] Para sair\n");
    printf("[5] Inserir aleatorio\n");
    printf("[6] Buscar elemento\n");
    scanf("%d", &op);

    switch(op){
      case 1:
      system("cls");
      printf(">>> Tela de registro <<<\n");
      printf("Informe o numero de matricula: \n");
      scanf("%d", &aluno.numMatricula);
      printf("Informe o nome: \n");
      scanf("%s", aluno.nome);
      printf("Informe o email: \n");
      scanf("%s", aluno.email);

      if ((arv = inserir(arv,aluno ) )== NULL){
        printf("Aluno %d  nao inserido\n", aluno.numMatricula);
      }
      break;

      case 2:
      system("cls");
      printf(">>> Tela de remoção <<<\n");
      printf("Informe o numero de matricula: \n");
      scanf("%d", &num);
      t=clock();
      arv = remover(arv, num);
      t=clock()-t;
      printf("Tempo de execução: %.2lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

      break;


      case  3:
      system("cls");
      printf(">>> Imprimindo a arvore <<<<\n");
      imprimir(arv, 1);
      printf("\n\n");

      break;

      case 4:
      printf("Ate a próxima!!!\n");
      break;

      case 5:
      /*
        2° Parametro quantidade que vai ser addc
      */
      t=clock();
       arv =  geraAlunosNaArv(arv, 10000);
        t=clock()-t;
        printf("Tempo de execução: %.2lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

      break;

      case 6:
      system("cls");
      printf("Qual elemnto deseja buscar??? \n");
      scanf("%d", &num);
      t=clock();
      busca = buscaArvAlunoRec(arv, num);
      if(busca == NULL){
        printf("Aluno não existe na arvore\n");
      }else printf("Elemento %d existe na arvore\n", busca->numMatricula);
      t=clock()-t;
      printf("Tempo de execução: %.2lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
      break;

      default:
        printf("Ops... Opcao inválida\n");

    }
  }while(op != 4);





  return 0;
}

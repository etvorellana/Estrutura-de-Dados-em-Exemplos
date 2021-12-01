#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ferramentas.h"


int main(void) {
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
      system("clear");
      printf(">>> Tela de registro <<<\n");
      printf("Informe o numero de matricula: \n");
      scanf("%d", &aluno.numMatricula);
      printf("Infrome o nome: \n");
      scanf("%s", aluno.nome);
      printf("Infrome o email: \n");
      scanf("%s", aluno.email);

      if ((arv = inserir(arv,aluno ) )== NULL){
        printf("Aluno %d  nao inserido\n", aluno.numMatricula);
      } 
      break;

      case 2:
      system("clear");
      printf(">>> Tela de remocao <<<\n");
      printf("Informe o numero de matricula: \n");
      scanf("%d", &num);
      arv = remover(arv, num);
      break;


      case  3:
      system("clear");
      printf(">>> Imprimindo a arvore <<<<\n");
      imprimir(arv, 1);
      printf("\n\n");
      break;
      
      case 4:
      printf("Ate a proxima!!!\n");
      break;

      case 5: 
      /*
        2° Parametro quantidade que vai ser addc
      */
       arv =  geraAlunosNaArv(arv, 10);
      break;

      case 6:
      system("clear");
      printf("Qual elemnto deseja buscar??? \n");
      scanf("%d", &num);
      busca = buscaArvAlunoRec(arv, num);
      if(busca == NULL){
        printf("Aluno não existe na arvore\n");
      }else printf("Elemento %d existe na arvore\n", busca->numMatricula);
      break;

      default:
        printf("Ops... Opcao invalida\n");

    }
  }while(op != 4);





  return 0;
}
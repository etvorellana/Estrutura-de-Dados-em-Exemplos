#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

No* novoNo(TAluno aluno){
    No *novo = malloc(sizeof(No));

    if(novo){
        cpAlunoNaFolha(aluno, novo);
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar n� em novoNo!\n");
    return novo;
}

int maior(int a, int b){
    return (a > b)? a: b;
}

int alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

int fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}



/*
 Se�ao de Rota��es
*/

No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoEsquerdaDireita(No *r){
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No *r){
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}

No* balancear(No *raiz){
    int fb = fatorDeBalanceamento(raiz);

    // Rota��o � esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rota��o � direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rota��o dupla � esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rota��o dupla � direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

No* inserir(No *raiz, TAluno aluno){
    if(raiz == NULL) // �rvore vazia
        return novoNo(aluno);
    else{ // inser��o ser� � esquerda ou � direita
        if(aluno.numMatricula < raiz->numMatricula)
            raiz->esquerdo = inserir(raiz->esquerdo, aluno);
        else if(aluno.numMatricula > raiz->numMatricula)
            raiz->direito = inserir(raiz->direito, aluno);
        else
            printf("\nInsercao nao realizada!\nO elemento %d ja existe!\n", aluno.numMatricula);
    }

    // Recalcula a altura de todos os n�s entre a raiz e o novo n� inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a �rvore
    raiz = balancear(raiz);

    return raiz;
}


No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o n� a remover
        if(raiz->numMatricula == chave) {
            // remove n�s folhas (n�s sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover n�s que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    No *aux = raiz->esquerdo;
                    while(aux->direito != NULL)
                        aux = aux->direito;
                    raiz->numMatricula = aux->numMatricula;
                    aux->numMatricula = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else{
                    // remover n�s que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->numMatricula)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
        }

        // Recalcula a altura de todos os n�s entre a raiz e o novo n� inserido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a �rvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimir(No *raiz, int nivel){
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(int i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->numMatricula);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

void cpAlunoNaFolha(TAluno aluno, No* folha){
	folha->numMatricula = aluno.numMatricula;
	strcpy(folha->nome, aluno.nome); 	//copia aluno para novo
	strcpy(folha->email, aluno.email);
	return;
}

No* geraAlunosNaArv(No* arvore, int qtd){
  unsigned int matricula;
  TAluno aluno;
  int cont = 0;
srand(time(NULL));
  while(cont < qtd){
    matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000;
    aluno.numMatricula = matricula;
  	strcpy(aluno.nome, "Nome SobrenomeM SobrenomeP");
  	strcpy(aluno.email,"NSmSp@uesc.br");
    arvore = inserir(arvore, aluno);
    cont++;

  }
  return arvore;
}
No* buscaArvAlunoRec(No* raiz, int chave){
  /*
   Caso a arvore esteja vazia ou a chvae que estamos procurando
  */
  if(raiz == NULL || raiz->numMatricula == chave)
		return raiz;

   else if(chave < raiz->numMatricula)
		//procura na sub�rvore da esquerda
		return buscaArvAlunoRec(raiz->esquerdo, chave);

   	else // Se n�o, (ent�o � maior)
	    //procura na sub�rvore da direita
		return buscaArvAlunoRec(raiz->direito, chave);
}

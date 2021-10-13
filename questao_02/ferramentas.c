#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista
definida como um array de forma estática.
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência
	um array de tipo tAluno. Nesta implementação se assume que a chave
    procurada foi copiada no final da lista;
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1. A chave procurada deve ter sido copiada para
    o elemento de índice tam, que não pertence à lista;
- chave: Número de matrícula do aluno que está sendo procurado.
	Para evitar ambiguidades, supõe-se que todas as chaves são
	distintas;
saída:
- A função retorna o índice da lista que possui a chave procurada.
	Caso a chave não pertença a nenhum dos elementos da lista a
	função retorna tam;
*/

int buscaLisAluno(TAluno lista[], int tam, int chave)
{
	int i = 0;
	while (lista[i].numMatricula != chave){
		i++;
	}
	return i;
}

int buscaLisAlunoOrd(TAluno lista[], int tam, int chave)
{
	int min = 0, max = tam, i;
	while (min != max)	{
		i = (max + min) / 2;
		if (lista[i].numMatricula < chave)
			min = ++i;
		else
			if (lista[i].numMatricula > chave)
				max = i;
			else
				return i;
	}
	return i;
}

/*
Implementa a inclusão numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista
definida como um array de forma estática. Os elementos da lista
não podem repetir o mesmo atributi chave.
Entrada:
- aluno: Variável de tipo TAluno com as informações do elemnto
    que se deseja incluir na lista;
- lista: Uma lista sequencial estática na forma de uma referência
	um array de tipo tAluno. O array permite aloca um elementro a
    mais do que a capacidade da lista para permitir um algorítmo de
    busca mais eficiente;
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1;
saída:
- A função retorna o verdadeiro caso o aluno seja incluído na lista
    e falso caso contrário. Nesta implementação o aluno não sera
    incluído na lista se já tiver um elemento na lista com o mesmo
    atributo chave
*/
int incLisAluno(TAluno aluno, TAluno lista[], int *tam)
{
    lista[*tam].numMatricula = aluno.numMatricula;
	if (buscaLisAluno(lista, *tam, aluno.numMatricula) == *tam){
        strcpy(lista[*tam].nome, aluno.nome);
	    strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

void trocaAluno(TAluno *alunoA, TAluno *alunoB){
	TAluno troca;
	troca.numMatricula = alunoA->numMatricula;
	strcpy(troca.nome, alunoA->nome);
	strcpy(troca.email, alunoA->email);

	alunoA->numMatricula = alunoB->numMatricula;
	strcpy(alunoA->nome, alunoB->nome);
	strcpy(alunoA->email, alunoB->email);

	alunoB->numMatricula = troca.numMatricula;
	strcpy(alunoB->nome, troca.nome);
	strcpy(alunoB->email, troca.email);
}

int incLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam)
{
	int pos = buscaLisAlunoOrd(lista, *tam, aluno.numMatricula);
	if(lista[pos].numMatricula != aluno.numMatricula){
		for(int i = *tam; i > pos; i--){
			lista[i].numMatricula = lista[i-1].numMatricula;
			strcpy(lista[i].nome, lista[i-1].nome);
			strcpy(lista[i].email, lista[i-1].email);
		}
		lista[pos].numMatricula = aluno.numMatricula;
		strcpy(lista[pos].nome, aluno.nome);
	    strcpy(lista[pos].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

int remLisAluno(TAluno aluno, TAluno lista[], int *tam){
	lista[*tam].numMatricula = aluno.numMatricula;
	int pos = buscaLisAluno(lista, *tam, aluno.numMatricula);
	if ( pos != *tam)
		if(*tam == 1){
			*tam = 0;
        	return TRUE;
		}else{
			lista[pos].numMatricula = lista[*tam - 1].numMatricula;
        	strcpy(lista[pos].nome, lista[*tam - 1].nome);
	    	strcpy(lista[pos].email, lista[*tam - 1].email);
			*tam -= 1;
        	return TRUE;
		}
    return FALSE;
}

int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam){
	int pos = buscaLisAlunoOrd(lista, *tam, aluno.numMatricula);
	if ( lista[pos].numMatricula == aluno.numMatricula){
		for(int i = pos; i < (*tam - 1); i++){
			lista[i].numMatricula = lista[i+1].numMatricula;
        	strcpy(lista[i].nome, lista[i+1].nome);
	    	strcpy(lista[i].email, lista[i+1].email);
		}
        *tam -= 1;
        return TRUE;
	}
    return FALSE;
}

void printLisAluno(TAluno lista[], int tam)
{

	for (int i = 0; i < tam; i++)
	{
	    printf("[");
		printf("%d, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s", lista[i].email);
		printf("]");
	}

}

void iniListAlunos(TListAlunos *list, int cap, int eOrd)
{
	if (eOrd)
		list->lista = (TAluno *)malloc((cap) * sizeof(TAluno));
	else
		list->lista = (TAluno *)malloc((cap + 1) * sizeof(TAluno));
	list->cap = cap;
	list->tam = 0;
	list->eOrd = eOrd;
}

int buscaAluno(TListAlunos *lista, int chave){
	if (lista->eOrd == TRUE)
		return buscaLisAlunoOrd(lista->lista, lista->tam, chave);
	else{
		lista->lista[lista->tam].numMatricula = chave;
		return buscaLisAluno(lista->lista, lista->tam, chave);
	}
}

int incAluno(TAluno aluno, TListAlunos *lista){
	if (lista->tam == lista->cap)
		return FALSE;
	if (lista->eOrd == TRUE)
		return incLisAlunoOrd(aluno, lista->lista, &lista->tam);
	else
		return incLisAluno(aluno, lista->lista, &lista->tam);
}

int remAluno(TAluno aluno, TListAlunos *lista){
	if (lista->tam == 0)
		return FALSE;
	if (lista->eOrd == TRUE)
		return remLisAlunoOrd(aluno, lista->lista, &lista->tam);
	else
		return remLisAluno(aluno, lista->lista, &lista->tam);
}

void geraAlunos(TListAlunos* lista){
	unsigned int matricula;
	TAluno aluno;
	while(lista->tam < lista->cap){
		//                  ano                       semestre               sequencial
		matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000;
		aluno.numMatricula = matricula;
  		strcpy(aluno.nome, "Nome SobrenomeM SobrenomeP");
  		strcpy(aluno.email,"NSmSp@uesc.br");
		incAluno(aluno, lista);
	}
}

void iniPilhaAlunos(TPilhaAlunos* pilha, int cap){
	pilha->cap = cap;
	pilha->topo = 0;
	pilha->pilha = (TAluno*) malloc(sizeof(TAluno)*cap);
}

int incAlunoNaPilha(TAluno aluno, TPilhaAlunos* pilha){ //push ou empilha
	if(pilha->topo < pilha->cap)
	{
		pilha->pilha[pilha->topo].numMatricula = aluno.numMatricula;
		strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
		strcpy(pilha->pilha[pilha->topo].email, aluno.email);
		pilha->topo++;
		return TRUE;
	}else{
		return FALSE;
	}
}

int remAlunoDaPilha(TAluno* aluno, TPilhaAlunos* pilha){ //pop ou desempilha
	if(pilha->topo > 0)
	{
		pilha->topo--;
		aluno->numMatricula = pilha->pilha[pilha->topo].numMatricula;
		strcpy(aluno->nome, pilha->pilha[pilha->topo].nome);
		strcpy(aluno->email, pilha->pilha[pilha->topo].email);
		return TRUE;
	}else{
		return FALSE;
	}
}

void iniFilaAlunos(TFilaAlunos* fila, int cap){
	fila->cap = cap;
	fila->ini = 0;
	fila->fim = 0;
	fila->fila = (TAluno*) malloc(sizeof(TAluno)*cap);
}

int incAlunoNaFila(TAluno aluno, TFilaAlunos* fila){
	if((fila->fim - fila->ini) < fila->cap){
		int pos = fila->fim % fila->cap;
		fila->fila[pos].numMatricula = aluno.numMatricula;
		strcpy(fila->fila[pos].nome, aluno.nome);
		strcpy(fila->fila[pos].email, aluno.email);
		fila->fim++;
		return TRUE;
	}else{
		return FALSE;
	}
}

int remAlunoDaFila(TAluno* aluno, TFilaAlunos* fila){
	if(fila->ini < fila->fim)
	{
		int pos = fila->ini%fila->cap;
		aluno->numMatricula = fila->fila[pos].numMatricula;
		strcpy(aluno->nome, fila->fila[pos].nome);
		strcpy(aluno->email, fila->fila[pos].email);
		fila->ini++;
		return TRUE;
	}else{
		return FALSE;
	}
}

void printFila(TFilaAlunos fila){

  for(int i = fila.ini; i<fila.fim; i++){
    printf("[");
    printf("%d, ", fila.fila[i].numMatricula);
    printf("%s, ", fila.fila[i].nome);
    printf("%s", fila.fila[i].email);
  printf("]");
  }

}
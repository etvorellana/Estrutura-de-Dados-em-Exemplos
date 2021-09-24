#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"


#define TRUE 1
#define FALSE 0


typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;


typedef struct{
	TAluno* lista;
	int cap;
	int tam;
    int eOrd;
} TListAlunos;


int buscaLisAlunoOrd(TAluno lista[], int chave);
int incListAlunoOrd(TAluno aluno, TAluno lista[], int *tam);
void trocaAluno(TAluno *alunoA, TAluno *alunoB);
void printLisAluno(TAluno lista[], int *tam);
int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);
int remLisAluno(TAluno aluno, TAluno lista[], int *tam);
void iniListAlunos(TListAlunos *list, int cap, int eOrd);


//Funcao de busca para listas não ordenadas de alunos
int buscaLisAluno(TAluno lista[], int chave)
{
	int i = 0;
	while (lista[i].numMatricula != chave){
		i++;
	}
	return i;
}

//Funcao de busca para listas ordenadas de alunos
int buscaLisAlunoOrd(TAluno lista[], int chave)
{
    int i = 0;
    while (lista[i].numMatricula < chave){
        i++;
    }
    return i;
}

//Funcao de busca para listas ordenadas/não ordenadas de alunos
int buscaAluno(TListAlunos *lista, int chave){
	if (lista->eOrd == TRUE)
		return buscaLisAlunoOrd(lista->lista, chave);
	else{
		lista->lista[lista->tam].numMatricula = chave;
		return buscaLisAluno(lista->lista, chave);
	}
}

//Função para trocar alunos
void trocaAluno(TAluno *alunoA, TAluno *alunoB){
	alunoB->numMatricula = alunoA->numMatricula;
	strcpy(alunoB->nome, alunoA->nome);
	strcpy(alunoB->email, alunoA->email);
}

//inclue um aluno em um array de alunos não ordenado
int incListAluno(TAluno aluno, TAluno lista[], int *tam)
{
    lista[*tam].numMatricula = aluno.numMatricula;
	if (buscaLisAluno(lista,aluno.numMatricula) == *tam){
        strcpy(lista[*tam].nome, aluno.nome);
	    strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

//inclue um aluno em um array de alunos ordenado
int incListAlunoOrd(TAluno aluno, TAluno lista[], int *tam)
{
    int pos = buscaLisAlunoOrd(lista, aluno.numMatricula);
    if (pos == *tam){
        trocaAluno(&aluno, &lista[*tam] );
        *tam += 1;
        return TRUE;
    }else if(lista[pos].numMatricula != aluno.numMatricula){
        for(int i = *tam; i > pos; i--){
            trocaAluno(&lista[i-1], &lista[i] );
        }
        trocaAluno(&aluno, &lista[pos] );
        *tam += 1;
        return TRUE;
    }
    return FALSE;
}

//Inclue um aluno em uma lista ordenada/nao ordenada de alunos
int incAluno(TAluno aluno, TListAlunos *lista){
    // return TRUE or FALSE
    if(lista->tam == lista->cap)
        return FALSE;
    if (lista->eOrd == TRUE)
        return incListAlunoOrd(aluno, lista->lista, &lista->tam);
    else
        return incListAluno(aluno, lista->lista, &lista->tam);
}

//Funcao para remocao em listas não ordenadas de alunos
int remLisAluno(TAluno aluno, TAluno lista[], int *tam){
	if(*tam > 0){
		
	lista[*tam].numMatricula = aluno.numMatricula;
    int pos = buscaLisAluno(lista, aluno.numMatricula);
	if (pos != *tam){
        for(int i=pos;i<*tam-1;i++){
            trocaAluno(&lista[i+1], &lista[i]);
        }
        *tam -= 1;
        return TRUE;
	}
    return FALSE;
}	
		
}		
    

//Funcao para remocao em listas ordenadas de alunos
int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam){
    if(*tam > 0){
        int pos = buscaLisAlunoOrd(lista,aluno.numMatricula);
        if(lista[pos].numMatricula == aluno.numMatricula){
            *tam -= 1;
            for(int i =pos; i < *tam; i++)
                trocaAluno(&lista[i+1], &lista[i]);
            return TRUE;
        }
    }
    return FALSE;
}

//Remove um aluno em uma lista ordenada/nao ordenada de alunos
int remAluno(TAluno aluno, TListAlunos *lista){
    // return TRUE or FALSE
    if(lista->tam == 0)
        return FALSE;
    if (lista->eOrd == TRUE)
        return remLisAlunoOrd(aluno, lista->lista, &lista->tam);
    else
        return remLisAluno(aluno, lista->lista, &lista->tam);
}

//Função para imprimir na tela uma lista de alunos
void printLisAluno(TAluno lista[], int *tam)
{
	printf("[ \n ");
	for (int i = 0; i < *tam; i++)
	{
		printf("%d, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}

//Função para instanciar uma lista de alunos
void iniListAlunos(TListAlunos *list, int cap, int eOrd){
	if (eOrd)
		list->lista = (TAluno *)malloc((cap) * sizeof(TAluno));
	else
		list->lista = (TAluno *)malloc((cap + 1) * sizeof(TAluno));
	list->cap = cap;
	list->tam = 0;
	list->eOrd = eOrd;
}

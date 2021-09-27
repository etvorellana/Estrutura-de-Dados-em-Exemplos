#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

int buscaLisAluno(TAluno lista[], int tam, int chave)
{
    int i = 0;
    while (lista[i].numMatricula != chave)
    {
        i++;
    }
    return i;
}

int buscaLisAlunoOrd(TAluno lista[], int tam, int chave)
{
    int min = 0, max = tam, i;
    while (min != max)
    {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i;
        else if (lista[i].numMatricula > chave)
            max = i;
        else
            return i;
    }
    return i;
}

int incLisAluno(TAluno aluno, TListAlunos lista[], int *tam)
{
    lista->lista[lista->tam].numMatricula = aluno.numMatricula;
    if (buscaAluno(lista, aluno.numMatricula) == *tam)
    {
        strcpy(lista->lista[lista->tam].nome, aluno.nome);
        strcpy(lista->lista[lista->tam].email, aluno.email);
        *tam += 1;
        return TRUE;
    }
    return FALSE;
}

void trocaAluno(TAluno *alunoA, TAluno *alunoB)
{
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

int incLisAlunoOrd(TAluno aluno, TListAlunos lista[], int *tam)
{
    int pos = buscaAluno(lista, aluno.numMatricula);
    if (lista->lista[pos].numMatricula != aluno.numMatricula)
    {
        for (int i = *tam; i > pos; i--)
        {
            lista->lista[i].numMatricula = lista->lista[i - 1].numMatricula;
            strcpy(lista->lista[i].nome, lista->lista[i - 1].nome);
            strcpy(lista->lista[i].email, lista->lista[i - 1].email);
        }
        lista->lista[pos].numMatricula = aluno.numMatricula;
        strcpy(lista->lista[pos].nome, aluno.nome);
        strcpy(lista->lista[pos].email, aluno.email);
        *tam += 1;
        return TRUE;
    }
    return FALSE;
}

int remLisAluno(TAluno aluno, TListAlunos lista[], int *tam)
{
    int pos = 0;
    lista->lista[lista->tam].numMatricula = aluno.numMatricula;
    if ((pos = buscaAluno(lista, aluno.numMatricula)) != *tam)
    {
        for (int i = pos - 1; i < *tam - 1; i++)
        {
            lista->lista[i].numMatricula = lista->lista[i + 1].numMatricula;
            strcpy(lista->lista[i].nome, lista->lista[i + 1].nome);
            strcpy(lista->lista[i].email, lista->lista[i + 1].email);
        }
        *tam -= 1;
        return TRUE;
    }
    return FALSE;
}

int remLisAlunoOrd(TAluno aluno, TListAlunos lista[], int *tam)
{
    int pos = buscaAluno(lista, aluno.numMatricula);
    if (lista->lista[pos].numMatricula == aluno.numMatricula)
    {
        *tam -= 1;
        for (int i = pos; i < *tam; i++)
        {
            lista->lista[i].numMatricula = lista->lista[i + 1].numMatricula;
            strcpy(lista->lista[i].nome, lista->lista[i + 1].nome);
            strcpy(lista->lista[i].email, lista->lista[i + 1].email);
        }
        return TRUE;
    }
    return FALSE;
}

void printLisAluno(TAluno lista[], int tam)
{
    printf("[ \n");

    for (int i = 0; i < tam; i++)
    {
        printf("%d %s %s\n", lista[i].numMatricula, lista[i].nome, lista[i].email);
    }

    printf(" ]\n");
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

int buscaAluno(TListAlunos *lista, int chave)
{
    return lista->eOrd
               ? buscaLisAlunoOrd(lista->lista, lista->tam, chave)
               : buscaLisAluno(lista->lista, lista->tam, chave);
}

int incAluno(TAluno aluno, TListAlunos *lista)
{
    return lista->eOrd
               ? incLisAlunoOrd(aluno, lista, &lista->tam)
               : incLisAluno(aluno, lista, &lista->tam);
}

int remAluno(TAluno aluno, TListAlunos *lista)
{
    return lista->eOrd
               ? remLisAlunoOrd(aluno, lista, &lista->tam)
               : remLisAluno(aluno, lista, &lista->tam);
}

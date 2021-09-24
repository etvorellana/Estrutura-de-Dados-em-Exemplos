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

    printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br   
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */
    //LISTA ORDENADA
    printf("\nLISTA ORDENADA\n\n");

    // Adicionando o primeiro elemento na lista
    TAluno aluno;
    TListAlunos lista;

    iniListAlunos(&lista,capLista,TRUE);

    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Regrano Guedes Maia");
    strcpy(aluno.email, "regguemai@uesc.br");
    if(incAluno(aluno, &lista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um elemento na lista com chave repetida
    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Mengano Martins Pereira");
    strcpy(aluno.email, "menmarper@uesc.br");
    if(incAluno(aluno, &lista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um novo elemento na lista
    aluno.numMatricula = 201913245;
    strcpy(aluno.nome, "Mengano Martins Pereira");
    strcpy(aluno.email, "menmarper@uesc.br");
    if(incAluno(aluno, &lista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um novo elemento na lista
    aluno.numMatricula = 201912345;
    strcpy(aluno.nome, "Fulano Silva Oliveira");
    strcpy(aluno.email, "fulsiloli@uesc.br");
    if(incAluno(aluno, &lista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

    // Imprimindo a lista
    printLisAluno(lista.lista, lista.tam);

    // Removendo um elemento na lista ordenada
    aluno.numMatricula = 201912345;
    if(remAluno(aluno, &lista) == FALSE)
        printf("Aluno %d não está na lista\n", aluno.numMatricula);

    // Imprimindo nova lista
    printLisAluno(lista.lista, lista.tam);

    //LISTA NÃO ORDENADA
    printf("\nLISTA NAO ORDENADA\n\n");
    // Adicionando o primeiro elemento na lista
    TAluno aluno1;
    TListAlunos lista1;

    iniListAlunos(&lista1,capLista,FALSE);

    aluno1.numMatricula = 201913425;
    strcpy(aluno1.nome, "Regrano Guedes Maia");
    strcpy(aluno1.email, "regguemai@uesc.br");
    if(incAluno(aluno1, &lista1) == FALSE)
        printf("Aluno %d já está na lista\n", aluno1.numMatricula);

    // Adicionando um elemento na lista com chave repetida
    aluno1.numMatricula = 201913425;
    strcpy(aluno1.nome, "Mengano Martins Pereira");
    strcpy(aluno1.email, "menmarper@uesc.br");
    if(incAluno(aluno1, &lista1) == FALSE)
        printf("Aluno %d já está na lista\n", aluno1.numMatricula);

    // Adicionando um novo elemento na lista
    aluno1.numMatricula = 201913245;
    strcpy(aluno1.nome, "Mengano Martins Pereira");
    strcpy(aluno1.email, "menmarper@uesc.br");
    if(incAluno(aluno1, &lista1) == FALSE)
        printf("Aluno %d já está na lista\n", aluno1.numMatricula);

    // Adicionando um novo elemento na lista
    aluno1.numMatricula = 201912345;
    strcpy(aluno1.nome, "Fulano Silva Oliveira");
    strcpy(aluno1.email, "fulsiloli@uesc.br");
    if(incAluno(aluno1, &lista1) == FALSE)
        printf("Aluno %d já está na lista\n", aluno1.numMatricula);

    // Imprimindo a lista
    printLisAluno(lista1.lista, lista1.tam);

    // Removendo um elemento na lista
    aluno1.numMatricula = 201912345;
    if(remAluno(aluno1, &lista1) == FALSE)
        printf("Aluno %d não está na lista\n", aluno1.numMatricula);

    // Imprimindo nova lista
    printLisAluno(lista1.lista, lista1.tam);
    return 0;
}

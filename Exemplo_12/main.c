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

    printf("Testando Listas Lineares Sequenciais\n");

    TAluno aluno;
    TListAlunos lista;
    iniListAlunos(&lista, capLista, TRUE);

    // Adicionando o aluno Regrano Guedes
    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Regrano Guedes Maia");
    strcpy(aluno.email, "regguemai@uesc.br");
    if (incAluno(aluno, &lista) == TRUE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

    // Adicionando o aluno Mengano Martins
    aluno.numMatricula = 201913426;
    strcpy(aluno.nome, "Mengano Martins");
    strcpy(aluno.email, "menmarper@uesc.br");
    if (incAluno(aluno, &lista) == TRUE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

    // Adicionando o aluno Mengano Martins
    aluno.numMatricula = 201913427;
    strcpy(aluno.nome, "Mengano Martins");
    strcpy(aluno.email, "menmarper@uesc.br");
    if (incAluno(aluno, &lista) == TRUE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

        // Adicionando um novo elemento na lista
    aluno.numMatricula = 201912345;
    strcpy(aluno.nome, "Fulano Silva Oliveira");
    strcpy(aluno.email, "fulsiloli@uesc.br");
    if(incAluno(aluno, &lista) == TRUE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

    // Imprimindo a lista
    printLisAluno(lista.lista, tamLista);

    // Removendo um elemento na lista
    aluno.numMatricula = 201913425;
    if (remAluno(aluno, &lista) == FALSE)
        printf("Aluno %d não está na lista\n", aluno.numMatricula);

    // Imprimindo a lista
    printLisAluno(lista.lista, tamLista);

    // Buscado aluno na lista
    aluno.numMatricula = 201912345;
    int pos = buscaAluno(&lista, aluno.numMatricula);
    TAluno encontrado = lista.lista[pos];


    // Printando o nome do aluno encontrado
    printf("Aluno %s encontrado na posicao %d\n", aluno.nome, pos);

    return 0;
}

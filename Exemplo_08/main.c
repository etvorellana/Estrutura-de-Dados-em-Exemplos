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
    TAluno lista[LSIZE];

    printf("Testando Listas Lineares Sequenciais\n");

    /* Vamos adicionar 3 alunos na lsita
        Nome                    Matrícula   EMail
        Regrano Guedes Maia     201913425   regguemai@uesc.br   
        Mengano Martins Pereira 201913245   menmarper@uesc.br
        Fulano Silva Oliveira   201912345   fulsiloli@uesc.br
    */

    // Adicionando o primeiro elemento na lista
    TAluno aluno;
    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Regrano Guedes Maia");
    strcpy(aluno.email, "regguemai@uesc.br");
    if(incLisAlunoOrd(aluno, lista, &tamLista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um elemento na lista com chave repetida
    aluno.numMatricula = 201913425;
    strcpy(aluno.nome, "Mengano Martins Pereira");
    strcpy(aluno.email, "menmarper@uesc.br");
    if(incLisAlunoOrd(aluno, lista, &tamLista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um novo elemento na lista
    aluno.numMatricula = 201913245;
    strcpy(aluno.nome, "Mengano Martins Pereira");
    strcpy(aluno.email, "menmarper@uesc.br");
    if(incLisAlunoOrd(aluno, lista, &tamLista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);
    // Adicionando um novo elemento na lista
    aluno.numMatricula = 201912345;
    strcpy(aluno.nome, "Fulano Silva Oliveira");
    strcpy(aluno.email, "fulsiloli@uesc.br");
    if(incLisAlunoOrd(aluno, lista, &tamLista) == FALSE)
        printf("Aluno %d já está na lista\n", aluno.numMatricula);

    // Imprimindo a lista
    printLisAluno(lista, tamLista);

    return 0;
}

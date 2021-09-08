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
    tamLista = LSIZE;
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
    //
    lista[0].numMatricula = 201913425; // Posição inicial na posição indexada 0
    // Copiando uma string literal em uma array de char
    strcpy(lista[0].nome, "Regrano Guedes Maia");
    // Pode ser utilizada também como indexador o tamanho da lista
    strcpy(lista[tamLista].email, "regguemai@uesc.br");
    // Antes de incrementar o tamanho
    tamLista++;

    // Adicionando um novo elemento na lista
    //if (lista[0].numMatricula != 201913245)
    if (buscaLisAluno(lista, tamLista, 201913245) == tamLista)
    {
        lista[tamLista].numMatricula = 201913245;
        strcpy(lista[tamLista].nome, "Mengano Martins Pereira");
        strcpy(lista[tamLista].email, "menmarper@uesc.br");
        tamLista++;
    }
    else
    {
        printf("Aluno já está na lista\n");
    }

    // Adicionando um novo elemento na lista
    //if (buscaLisAluno(lista, tamLista, 201912345) == tamLista)
    TAluno aluno;
    aluno.numMatricula = 201912345;
    strcpy(aluno.nome, "Fulano Silva Oliveira");
    strcpy(aluno.email, "fulsiloli@uesc.br");
    if(incLisAluno(aluno, lista, &tamLista) == FALSE)
    {
        printf("Aluno já está na lista\n");
    }

    // Imprimindo a lista
    printLisAluno(lista, tamLista);

    return 0;
}


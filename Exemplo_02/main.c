#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int buscaLisAluno(TAluno lista[], int tam, int chave);

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

    if (buscaLisAluno(lista, tamLista, 201913425) == tamLista)
    {
        lista[tamLista].numMatricula = 201913425;
        strcpy(lista[tamLista].nome, "Mengano Martins Pereira");
        strcpy(lista[tamLista].email, "menmarper@uesc.br");
        tamLista++;
    }
    else
    {
        printf("Já tem Aluno na lista com matrícula 201913425\n");
    }

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
    //if (lista[0].numMatricula != 201912345 && lista[1].numMatricula != 201912345)
    if (buscaLisAluno(lista, tamLista, 201912345) == tamLista)
    {
        lista[tamLista].numMatricula = 201912345;
        strcpy(lista[tamLista].nome, "Fulano Silva Oliveira");
        strcpy(lista[tamLista].email, "fulsiloli@uesc.br");
        tamLista++;
    }
    else
    {
        printf("Aluno já está na lista\n");
    }

    // Imprimindo a lista
    printf("[ \n ");
    for (int i = 0; i < tamLista; i++)
    {
        printf("%d, ", lista[i].numMatricula);
        printf("%s, ", lista[i].nome);
        printf("%s;\n ", lista[i].email);
    }
    printf(" ]\n");

    return 0;
}

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo TAluno.
- tam: Tamanho da lista, ou seja os índices dos elementos da lista
	vão de 0 até tam-1; 
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
	while (i < tam)
	{
		if (lista[i].numMatricula == chave)
			return i;
		i++;
	}
	return tam; //não achou, retorna tam
}

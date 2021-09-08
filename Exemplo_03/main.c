#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LSIZE 100

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int buscaLisAluno(TAluno lista[], int tam, int chave);
int incLisAluno(TAluno aluno, TAluno lista[], int *tam);
void printLisAluno(TAluno lista[], int tam);

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

/*
Implementa a busca numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. 
Entrada:
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno.
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
	return tam; //não achou, retorna n
}

int incLisAluno(TAluno aluno, TAluno lista[], int *tam)
{
	if (buscaLisAluno(lista, *tam, aluno.numMatricula) == *tam)
	{
		lista[*tam].numMatricula = aluno.numMatricula;
		strcpy(lista[*tam].nome, aluno.nome);
		strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

void printLisAluno(TAluno lista[], int tam)
{
	printf("[ \n ");
	for (int i = 0; i < tam; i++)
	{
		printf("%d, ", lista[i].numMatricula);
		printf("%s, ", lista[i].nome);
		printf("%s;\n ", lista[i].email);
	}
	printf(" ]\n");
}

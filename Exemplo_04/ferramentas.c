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

/*
Implementa a inclusão numa lista linear de alocação sequencial
do tipo TAluno. Nesta função se trabalha com uma lista 
definida como um array de forma estática. Os elementos da lista
não podem repetir o mesmo atributi chave. 
Entrada:
- aluno: Variável de tipo TAluno com as informações do elemnto
    que se deseja incluir na lista;
- lista: Uma lista sequencial estática na forma de uma referência 
	um array de tipo tAluno;
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

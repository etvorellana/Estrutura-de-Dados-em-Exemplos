#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


int main()
{
   	TAluno aluno;
	TAluno* lista;
	lista = (TAluno*) malloc(5*sizeof(TAluno));

    int tamLista =  0;
    printf("Testando inclusão em lista ordenada\n");
    aluno.numMatricula = 1;
    strcpy(aluno.nome, "Fulano pereira");
    strcpy(aluno.email,"fulano_pereira@uesc.br");
	if(incListAlunoOrd(aluno, lista, &tamLista))
        printf("incluiu\n");

    aluno.numMatricula = 3;
    strcpy(aluno.nome, "ciclano conceicao");
    strcpy(aluno.email,"fulaninho_conceicao@uesc.br");
	if(incListAlunoOrd(aluno, lista, &tamLista))
        printf("incluiu\n");

	aluno.numMatricula = 2;
    strcpy(aluno.nome, "beltrano martins");
    strcpy(aluno.email,"beltranim_martim@uesc.br");
	if(incListAlunoOrd(aluno, lista, &tamLista))
        printf("incluiu\n");

	aluno.numMatricula = 0;
    strcpy(aluno.nome, "teste martins");
    strcpy(aluno.email,"teste_martim@uesc.br");
	if(incListAlunoOrd(aluno, lista, &tamLista))
        printf("incluiu\n");

    printLisAluno(lista, &tamLista);

    printf("Testando remocao ordenada\n");
    if(remLisAlunoOrd(aluno, lista, &tamLista))
       printf("Remocao funcionou!");
    else
        printf("Remocao n funcionou!");

    printLisAluno(lista, &tamLista);

    return 0;
}


//retorna o indice da posição que encontrou ou do primeiro elemento maior que a chave
int buscaLisAlunoOrd(TAluno lista[], int chave)
{
    int i = 0;
    while (lista[i].numMatricula < chave){
        i++;
    }
    return i;
}

void trocaAluno(TAluno *alunoA, TAluno *alunoB){
	alunoB->numMatricula = alunoA->numMatricula;
	strcpy(alunoB->nome, alunoA->nome);
	strcpy(alunoB->email, alunoA->email);
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

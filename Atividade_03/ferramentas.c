#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ferramentas.h"

int buscaLisAluno(TAluno lista[], int tam, int chave)
{
	int i = 0;
	while (lista[i].numMatricula != chave){
		i++;
	}
	return i;
}

int buscaLisAlunoOrd(TAluno lista[], int tam, int chave)
{	
	int min = 0, max = tam, i = 0;
	while (min != max)	{
		i = (max + min) / 2;
		if (lista[i].numMatricula < chave)
			min = ++i;
		else
			if (lista[i].numMatricula > chave)
				max = i;
			else			
				return i;
	}
	return i;
}

int incLisAluno(TAluno aluno, TAluno lista[], int *tam)
{   
    lista[*tam].numMatricula = aluno.numMatricula;
	if (buscaLisAluno(lista, *tam, aluno.numMatricula) == *tam){
        strcpy(lista[*tam].nome, aluno.nome);
	    strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    else return FALSE;
}

void trocaAluno(TAluno *alunoA, TAluno *alunoB){
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

int incLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam)
{   
	int pos = buscaLisAlunoOrd(lista, *tam, aluno.numMatricula);
	if(lista[pos].numMatricula != aluno.numMatricula){
		for(int i = *tam; i > pos; i--){
			lista[i].numMatricula = lista[i-1].numMatricula;
			strcpy(lista[i].nome,lista[i-1].nome);
			strcpy(lista[i].email,lista[i-1].email);
		}
		lista[pos].numMatricula = aluno.numMatricula;
		strcpy(lista[pos].nome,aluno.nome);
		strcpy(lista[pos].email,aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

int remLisAluno(TAluno aluno, TAluno lista[], int *tam){
    int pos = 0;
    lista[*tam].numMatricula = aluno.numMatricula;
	if ((pos = buscaLisAluno(lista, *tam, aluno.numMatricula)) != *tam){
        for(int i=pos-1;i<*tam-1;i++){
            lista[i].numMatricula = lista[i+1].numMatricula;
            strcpy(lista[i].nome, lista[i+1].nome);
	        strcpy(lista[i].email, lista[i+1].email);
        }
        *tam -= 1;
        return TRUE;
	}
    return FALSE;
}

int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam){
	int pos = buscaLisAlunoOrd(lista, *tam, aluno.numMatricula);
	if(lista[pos].numMatricula == aluno.numMatricula){
	    *tam -= 1;
		for(int i =pos; i < *tam; i++){
			lista[i].numMatricula=lista[i+1].numMatricula;
			strcpy(lista[i].nome,lista[i+1].nome);
			strcpy(lista[i].email,lista[i+1].email);
		}
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

void iniListAlunos(TListAlunos *list, int cap, int eOrd){
	if (eOrd){
		list->lista = (TAluno *)malloc((cap) * sizeof(TAluno ));
		if(list->lista == NULL) printf("Deu erro!");
	}
	else{
		list->lista = (TAluno *)malloc((cap+1) * sizeof(TAluno ));
		if(list->lista == NULL) printf("Deu erro!");
	}
	list->cap = cap;
	list->tam = 0;
	list->eOrd = eOrd;
}

int buscaAluno(TListAlunos *lista, int chave){
	if (lista->eOrd == TRUE)
		return buscaLisAlunoOrd(lista->lista, lista->tam, chave);
	else{
		lista->lista[lista->tam].numMatricula = chave;
		return buscaLisAluno(lista->lista, lista->tam, chave);
	}
}

int incAluno(TAluno aluno, TListAlunos *lista){
	if(lista->eOrd == TRUE){
		if(incLisAlunoOrd(aluno,lista->lista,&lista->tam) == TRUE)
			return TRUE;
		else	
			return FALSE;
	}
	else{	

		lista->lista[lista->tam].numMatricula = aluno.numMatricula;
		if(incLisAluno(aluno,lista->lista,&lista->tam) == TRUE)
			return TRUE;	
		else
			return FALSE;
	}
}

int remAluno(TAluno aluno, TListAlunos *lista){
	if(lista->eOrd == TRUE){
		if(remLisAlunoOrd(aluno,lista->lista,&lista->tam) == TRUE)
			return TRUE;
		else	
			return FALSE;
	}
	else{	
		lista->lista[lista->tam].numMatricula = aluno.numMatricula;
		if(remLisAluno(aluno,lista->lista,&lista->tam) == TRUE)
			return TRUE;	
		else
			return FALSE;
	}
}

void geraAlunos(TListAlunos* lista){
    unsigned int matricula;
    TAluno aluno;
    while(lista->tam < lista->cap){
        //                ano                         semestre           sequencial        
        matricula = (2000  + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000;
        aluno.numMatricula = matricula;
		geraNomes(&aluno);
        incAluno(aluno, lista);
    }
}

void geraNomes(TAluno* aluno){
	unsigned int random; 
	random = 1+(rand() %12);
	switch (random)
	{
	case 1:
		strcpy(aluno->nome,"Maria");
		break;
	case 2:
		strcpy(aluno->nome,"José");
		break;
	case 3:
		strcpy(aluno->nome,"Antônio");
		break;
	case 4:
		strcpy(aluno->nome,"João");
		break;
	case 5:
		strcpy(aluno->nome,"Francisco");
		break;
	case 6:
		strcpy(aluno->nome,"Ana");
		break;
	case 7:
		strcpy(aluno->nome,"Luiz");
		break;
	case 8:
		strcpy(aluno->nome,"Paulo");
		break;
	case 9:
		strcpy(aluno->nome,"Carlos");
		break;
	case 10:
		strcpy(aluno->nome,"Manoel");
		break;
	case 11:
		strcpy(aluno->nome,"Pedro");
		break;
	case 12:
		strcpy(aluno->nome,"Francisca");
		break;
	}

	strcpy(aluno->email,aluno->nome);
	int tam = strlen(aluno->email);
	printf("Tam = %d",tam);

	for(int i = 0; i < 2 ; i++){
		
		random = 1+(rand() %8);
		switch (random)
		{
		case 1:
			strcat(aluno->nome," Silva");
			break;
		case 2:
			strcat(aluno->nome," Santos");
			break;
		case 3:
			strcat(aluno->nome," Souza");
			break;
		case 4:
			strcat(aluno->nome," Oliveira");
			break;
		case 5:
			strcat(aluno->nome," Pereira");
			break;
		case 6:
			strcat(aluno->nome," Rodrigues");
			break;
		case 7:
			strcat(aluno->nome," Alves");
			break;
		case 8:
			strcat(aluno->nome," Costa");
			break;
		}
	}
	for(int i = 0; i < strlen(aluno->nome); i++){
		char ch;
		ch = aluno->nome[i];
		if(isupper(ch)){
			 memset(aluno->email, '\0', sizeof(aluno->email));
			 aluno->email[i] = ch;
		}
	}
}

/*void geraEmail(TAluno* aluno, int *tami, int *tamf1, int *tamf2){
	int i;
	for(i = 0; i < *tami; i++)
		aluno->email[i] = aluno->nome[i];
	aluno->email[i] = aluno->nome[*tamf1];
	aluno->email[i+1] = aluno->nome[*tamf2];
	strcat(aluno->email,"@uesc.br");
}
*/
void iniPilhaAlunos(TPilhaAlunos* pilha, int cap){
    pilha->cap = cap;
    pilha->topo = 0;
    pilha->pilha = (TAluno*) malloc(sizeof(TAluno)*cap);
    if(pilha->pilha == NULL) exit (-1);
}

int incAlunoNaPilha(TAluno aluno, TPilhaAlunos* pilha){
    if(pilha->topo < pilha->cap){
        pilha->pilha[pilha->topo].numMatricula = aluno.numMatricula;
        strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
        strcpy(pilha->pilha[pilha->topo].email, aluno.nome);
        pilha->topo++;
        return TRUE;
    }
    else    
        return FALSE;
}

int remAlunoNaPilha(TAluno* aluno, TPilhaAlunos* pilha){
	
}
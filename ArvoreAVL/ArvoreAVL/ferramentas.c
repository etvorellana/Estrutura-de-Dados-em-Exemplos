#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ferramentas.h"

/*
Implementa a busca numa lista linear de aloca��o sequencial
do tipo TAluno. Nesta fun��o se trabalha com uma lista
definida como um array de forma est�tica.
Entrada:
- lista: Uma lista sequencial est�tica na forma de uma refer�ncia
	um array de tipo tAluno. Nesta implementa��o se assume que a chave
    procurada foi copiada no final da lista;
- tam: Tamanho da lista, ou seja os �ndices dos elementos da lista
	v�o de 0 at� tam-1. A chave procurada deve ter sido copiada para
    o elemento de �ndice tam, que n�o pertence � lista;
- chave: N�mero de matr�cula do aluno que est� sendo procurado.
	Para evitar ambiguidades, sup�e-se que todas as chaves s�o
	distintas;
sa�da:
- A fun��o retorna o �ndice da lista que possui a chave procurada.
	Caso a chave n�o perten�a a nenhum dos elementos da lista a
	fun��o retorna tam;
*/

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
	int min = 0, max = tam, i;
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

/*
Implementa a inclus�o numa lista linear de aloca��o sequencial
do tipo TAluno. Nesta fun��o se trabalha com uma lista
definida como um array de forma est�tica. Os elementos da lista
n�o podem repetir o mesmo atributi chave.
Entrada:
- aluno: Vari�vel de tipo TAluno com as informa��es do elemnto
    que se deseja incluir na lista;
- lista: Uma lista sequencial est�tica na forma de uma refer�ncia
	um array de tipo tAluno. O array permite aloca um elementro a
    mais do que a capacidade da lista para permitir um algor�tmo de
    busca mais eficiente;
- tam: Tamanho da lista, ou seja os �ndices dos elementos da lista
	v�o de 0 at� tam-1;
sa�da:
- A fun��o retorna o verdadeiro caso o aluno seja inclu�do na lista
    e falso caso contr�rio. Nesta implementa��o o aluno n�o sera
    inclu�do na lista se j� tiver um elemento na lista com o mesmo
    atributo chave
*/
int incLisAluno(TAluno aluno, TAluno lista[], int *tam)
{
    lista[*tam].numMatricula = aluno.numMatricula;
	if (buscaLisAluno(lista, *tam, aluno.numMatricula) == *tam){
        strcpy(lista[*tam].nome, aluno.nome);
	    strcpy(lista[*tam].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
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
			strcpy(lista[i].nome, lista[i-1].nome);
			strcpy(lista[i].email, lista[i-1].email);
		}
		lista[pos].numMatricula = aluno.numMatricula;
		strcpy(lista[pos].nome, aluno.nome);
	    strcpy(lista[pos].email, aluno.email);
        *tam += 1;
        return TRUE;
	}
    return FALSE;
}

int remLisAluno(TAluno aluno, TAluno lista[], int *tam){
	lista[*tam].numMatricula = aluno.numMatricula;
	int pos = buscaLisAluno(lista, *tam, aluno.numMatricula);
	if ( pos != *tam)
		if(*tam == 1){
			*tam = 0;
        	return TRUE;
		}else{
			lista[pos].numMatricula = lista[*tam - 1].numMatricula;
        	strcpy(lista[pos].nome, lista[*tam - 1].nome);
	    	strcpy(lista[pos].email, lista[*tam - 1].email);
			*tam -= 1;
        	return TRUE;
		}
    return FALSE;
}

int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam){
	int pos = buscaLisAlunoOrd(lista, *tam, aluno.numMatricula);
	if ( lista[pos].numMatricula == aluno.numMatricula){
		for(int i = pos; i < (*tam - 1); i++){
			lista[i].numMatricula = lista[i+1].numMatricula;
        	strcpy(lista[i].nome, lista[i+1].nome);
	    	strcpy(lista[i].email, lista[i+1].email);
		}
        *tam -= 1;
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

int buscaAluno(TListAlunos *lista, int chave){
	if (lista->eOrd == TRUE)
		return buscaLisAlunoOrd(lista->lista, lista->tam, chave);
	else{
		lista->lista[lista->tam].numMatricula = chave;
		return buscaLisAluno(lista->lista, lista->tam, chave);
	}
}

int incAluno(TAluno aluno, TListAlunos *lista){
	if (lista->tam == lista->cap)
		return FALSE;
	if (lista->eOrd == TRUE)
		return incLisAlunoOrd(aluno, lista->lista, &lista->tam);
	else
		return incLisAluno(aluno, lista->lista, &lista->tam);
}

int remAluno(TAluno aluno, TListAlunos *lista){
	if (lista->tam == 0)
		return FALSE;
	if (lista->eOrd == TRUE)
		return remLisAlunoOrd(aluno, lista->lista, &lista->tam);
	else
		return remLisAluno(aluno, lista->lista, &lista->tam);
}

void geraAlunos(TListAlunos* lista){
	unsigned int matricula;
	TAluno aluno;
	while(lista->tam < lista->cap){
		//                  ano                       semestre               sequencial
		matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000;
		aluno.numMatricula = matricula;
  		strcpy(aluno.nome, "Nome SobrenomeM SobrenomeP");
  		strcpy(aluno.email,"NSmSp@uesc.br");
		incAluno(aluno, lista);
	}
}

/*Pilas*/

void iniPilhaAlunos(TPilhaAlunos* pilha, int cap){
	pilha->cap = cap;
	pilha->topo = 0;
	pilha->pilha = (TAluno*) malloc(sizeof(TAluno)*cap);
}

int incAlunoNaPilha(TAluno aluno, TPilhaAlunos* pilha){ //push ou empilha
	if(pilha->topo < pilha->cap)
	{
		pilha->pilha[pilha->topo].numMatricula = aluno.numMatricula;
		strcpy(pilha->pilha[pilha->topo].nome, aluno.nome);
		strcpy(pilha->pilha[pilha->topo].email, aluno.email);
		pilha->topo++;
		return TRUE;
	}else{
		return FALSE;
	}
}

int remAlunoDaPilha(TAluno* aluno, TPilhaAlunos* pilha){ //pop ou desempilha
	if(pilha->topo > 0)
	{
		pilha->topo--;
		aluno->numMatricula = pilha->pilha[pilha->topo].numMatricula;
		strcpy(aluno->nome, pilha->pilha[pilha->topo].nome);
		strcpy(aluno->email, pilha->pilha[pilha->topo].email);
		return TRUE;
	}else{
		return FALSE;
	}
}

/*Filas*/

void iniFilaAlunos(TFilaAlunos* fila, int cap){
	fila->cap = cap;
	fila->ini = 0;
	fila->fim = 0;
	fila->fila = (TAluno*) malloc(sizeof(TAluno)*cap);
}

int incAlunoNaFila(TAluno aluno, TFilaAlunos* fila){
	if((fila->fim - fila->ini) < fila->cap){
		int pos = fila->fim % fila->cap;
		fila->fila[pos].numMatricula = aluno.numMatricula;
		strcpy(fila->fila[pos].nome, aluno.nome);
		strcpy(fila->fila[pos].email, aluno.email);
		fila->fim++;
		return TRUE;
	}else{
		return FALSE;
	}
}

int remAlunoDaFila(TAluno* aluno, TFilaAlunos* fila){
	if(fila->ini < fila->fim)
	{
		int pos = fila->ini%fila->cap;
		aluno->numMatricula = fila->fila[pos].numMatricula;
		strcpy(aluno->nome, fila->fila[pos].nome);
		strcpy(aluno->email, fila->fila[pos].email);
		fila->ini++;
		return TRUE;
	}else{
		return FALSE;
	}
}

/*Listas Enadeadas*/

// Cria um ponteiro para o TNoAluno
PNoAluno iniNoAluno(void){
	PNoAluno no;
    no = (PNoAluno) malloc(sizeof(TNoAluno));
	//no->prox = NULL;
	no->prox = no;
	return no;
}

PNoAluno buscaLisEncAluno_(PNoAluno lista, int chave){
	PNoAluno atual = lista;
	while(atual->prox != NULL){
		if (atual->prox->numMatricula == chave)
			break;
		atual = atual->prox;
	}
	//return atual->prox;
	return atual;
}

//Vers�o 2 da busca, supondo que a chave faz parte de lista
PNoAluno buscaLisEncAluno(PNoAluno lista, int chave){
	PNoAluno atual = lista;
	atual->numMatricula = chave;
	while(atual->prox->numMatricula != chave){
		atual = atual->prox;
	}
	return atual;
}

int incLisEncAluno(TAluno aluno, PNoAluno lista){
	PNoAluno pos = buscaLisEncAluno(lista, aluno.numMatricula);
	if (pos->prox == lista){ 				//o aluno n�o esta na lista
		PNoAluno novo = iniNoAluno(); //Criando um novo no
		novo->numMatricula = aluno.numMatricula;
		strcpy(novo->nome, aluno.nome); 	//copia aluno para novo
		strcpy(novo->email, aluno.email);
		novo->prox = lista; 				//o novo para lista
		pos->prox = novo; 					//�ltimo aponta para novo
		return TRUE;
	}
	return FALSE; 							//aluno j� esta na lista
}

int remLisEncAluno(TAluno aluno, PNoAluno lista){
	PNoAluno pos = buscaLisEncAluno(lista, aluno.numMatricula);
	if (pos->prox != lista){ 				//o aluno esta na lista
		PNoAluno exc = pos->prox; 			//no a ser excluido
		pos->prox = exc->prox; 				//anterior aponta para proximo
		free(exc); 							//livera mem�ria
		return TRUE;
	}
	return FALSE; // aluno n�o esta na lista
}

PNoAluno buscaLisEncAlunoOrd(PNoAluno lista, int chave){
	PNoAluno atual = lista;
	atual->numMatricula = chave;
	while(atual->prox->numMatricula < chave){
		atual = atual->prox;
	}
	return atual;
}

int incLisEncAlunoOrd(TAluno aluno, PNoAluno lista){
	PNoAluno pos = buscaLisEncAlunoOrd(lista, aluno.numMatricula);
	if (pos->prox == lista){ 				//o aluno n�o esta na lista
		PNoAluno novo = iniNoAluno(); //Criando um novo no
		novo->numMatricula = aluno.numMatricula;
		strcpy(novo->nome, aluno.nome); 	//copia aluno para novo
		strcpy(novo->email, aluno.email);
		novo->prox = lista; 				//o novo para lista
		pos->prox = novo; 					//�ltimo aponta para novo
		return TRUE;
	}else if(pos->prox->numMatricula != aluno.numMatricula){
		PNoAluno novo = iniNoAluno(); //Criando um novo no
		novo->numMatricula = aluno.numMatricula;
		strcpy(novo->nome, aluno.nome); 	//copia aluno para novo
		strcpy(novo->email, aluno.email);
		novo->prox = pos->prox;
		pos->prox = novo; 					//�ltimo aponta para novo
		return TRUE;
	}
	return FALSE; 							//aluno j� esta na lista
}

void printLisEncAluno(PNoAluno lista){
	printf("[ \n ");
	PNoAluno atual = lista;
	while(atual->prox != lista)	{
		atual = atual->prox;
		printf("%d, ", atual->numMatricula);
		printf("%s, ", atual->nome);
		printf("%s;\n ", atual->email);
	}
	printf(" ]\n");
}

/*
// Criando uma lista simplesmente encadeada com base numa lista sequencial
PNoAluno criarListEncDeListSeq(TListAlunos* listaS){
	PNoAluno listaE, atual;
	listaE = iniListaEncAluno(); 	//Criamos uma lista encadeada vazia
	if (listaS->tam > 0){ 			// Se a lista seq n�o estiver vazia
		atual = listaE;
		for(int i = 0; i < listaS->tam; i++){
			atual->prox = (PNoAluno)malloc(sizeof(TNoAluno));
			atual = atual->prox;
			atual->numMatricula = listaS->lista[i].numMatricula;
    		strcpy(atual->nome, listaS->lista[i].nome);
    		strcpy(atual->email,listaS->lista[i].email);
		}
		atual->prox = listaE;
	}
	return listaE;
}


void ini_tListEncAlunos(TListEncAlunos* lista, int eOrd){
	lista->lista = iniListaEncAluno();
	lista->tam = 0;
	lista->eOrd = eOrd;
	lista->lista->numMatricula = 0 ; // Para listas ordenadas
	lista->lista->prox = lista->lista; // Lista vazia lista.prox = lista
}
*/

// Cria um ponteiro para o TNoAluno
PNoArvAluno iniNoArvAluno(void){
	PNoArvAluno no;
    no = (PNoArvAluno) malloc(sizeof(TNoArvAluno));
	no->esq = NULL;
	no->dir = NULL;
	no->altura = 1; //adicionado altura na fun��o de criar novo n�
	return no;
}

void cpAlunoNaFolha(TAluno aluno, PNoArvAluno folha){
	folha->numMatricula = aluno.numMatricula;
	strcpy(folha->nome, aluno.nome); 	//copia aluno para novo
	strcpy(folha->email, aluno.email);
	return;
}


/*
	Incluir um aluno numa �rvore bin�ria de busca
*/
int incArvAlunoRec(TAluno aluno, PNoArvAluno *raiz){
	PNoArvAluno folha;
	if (*raiz == NULL){ // se a �rvore for vazia
		// Cria um n� folha
		folha = iniNoArvAluno();  // verifica��o de aloca��o
		// Copia as informa��es do aluno neste n�
		cpAlunoNaFolha(aluno, folha);
		// Faz a raiz da �rvore ser o novo n�
		*raiz = folha;
		return TRUE; // o aluno foi inclu�do na �rvore
	}else{ // Caso contrario, tem alguma coisa na �rvore
		// para simpleifica a nota��o, copio o endere�o do n� raiz
		PNoArvAluno no = *raiz; // para o ponteiro no
		/* Se a matr�cula do aluno que se quer incluir for maior
		   que a a matr�cula da raiz
		*/
		if(aluno.numMatricula > no->numMatricula)
			// incluir na sub�rvore da direita
			return incArvAlunoRec(aluno, &(no->dir));
		else // se n�o
			/* Se a matr�cula do aluno que se quer incluir for
		       menor que a a matr�cula da raiz
			*/
			if(aluno.numMatricula < no->numMatricula)
				// incluir na sub�rvore da esquerda
				return incArvAlunoRec(aluno, &(no->esq));
			else //Se n�o
				/* Ent�o a matr�cula do n� � igual a dp aluno
				   que se deseja incluir e neste casso retorna
				*/
				return FALSE; //O aluno n�o foi incluido
	}
}

// Vers�o n�o recursiva do inclus�o de um aluno na �rvore
int incArvAluno(TAluno aluno, PNoArvAluno *raiz){
	PNoArvAluno atual, folha;
	if (*raiz == NULL){
		folha = iniNoArvAluno();
		cpAlunoNaFolha(aluno, folha);
		*raiz = folha;
		return TRUE;
	}else{
		atual = *raiz;
		while(TRUE){
			if(aluno.numMatricula > atual->numMatricula){
				if(atual->dir == NULL){
					folha = iniNoArvAluno();
					cpAlunoNaFolha(aluno, folha);
					atual->dir = folha;
					return TRUE;
				}else{
					atual = atual->dir;
					continue;
				}
			}else{
				if(aluno.numMatricula < atual->numMatricula){
					if(atual->esq == NULL){
						folha = iniNoArvAluno();
						cpAlunoNaFolha(aluno, folha);
						atual->esq = folha;
						return TRUE;
					}else{
						atual = atual->esq;
						continue;
					}
				}else{
					return FALSE;
				}
			}
		}
	}
}

PNoArvAluno buscaArvAlunoRec(PNoArvAluno raiz, int chave){
	/* Se for uma �rvores vazia ou se for o n� que estou
	   procurado:
	*/
	if(raiz == NULL || raiz->numMatricula == chave)
		return raiz; // Retorna o n�
	/* se n�o, se a chave que estou procurando for menor
	   que a chave do n�
	*/
	else if(chave < raiz->numMatricula)
		//procura na sub�rvore da esquerda
		return buscaArvAlunoRec(raiz->esq, chave);
	else // Se n�o, (ent�o � maior)
	    //procura na sub�rvore da direita
		return buscaArvAlunoRec(raiz->dir, chave);
}

// Vers�o n�o recursiva de busca de um aluno na �rvore
PNoArvAluno buscaArvAluno(PNoArvAluno raiz, int chave){
	PNoArvAluno atual = raiz;
	while(atual != NULL && atual->numMatricula != chave){
		if(chave < atual->numMatricula)
			atual = atual->esq;
		else
			atual = atual->dir;
	}
	return atual;
}

PNoArvAluno buscaArvAlunoPai(PNoArvAluno raiz, int chave, PNoArvAluno *pai){
	PNoArvAluno atual = raiz;
	*pai = NULL;
	while(atual != NULL && atual->numMatricula != chave){
		*pai = atual;
		if(chave < atual->numMatricula)
			atual = atual->esq;
		else
			atual = atual->dir;
	}
	return atual;
}

int remArvAluno(TAluno aluno, PNoArvAluno *raiz){
	PNoArvAluno pai, no, p, q;
	no = buscaArvAlunoPai(*raiz, aluno.numMatricula, &pai);
	if(no==NULL)
		return FALSE; // n�o tem esse chave na �rvore
	if(no->esq == NULL || no->dir == NULL){ // se for um no de grau 0 ou 1
		if(no->esq == NULL){ //grau 1 com subarvore a direita
			q = no->dir;
		}else{ //grau 0 ou grau 1 com subarvore a esquerda
			q = no->esq;
		}
	}else{  //� um no de grau 2
		// procurando o no mais a direita da sub�rvore da esquerda
		p = no;
		q = no->esq;
		while(q->dir != NULL){
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
	if(pai==NULL){
		free(no);
		*raiz = q;
		return TRUE;
	}
	if(aluno.numMatricula < pai->numMatricula)
		pai->esq = q;
	else
		pai->dir = q;
	free(no);
	return(TRUE);
}

void printArvAluno(PNoArvAluno raiz, int modo){
	switch (modo%10)
	{
		case 0:
			printf("[ ");
			if(raiz != NULL){
				printf("%d ", raiz->numMatricula);
        		printf(" - L: ");
        		printArvAluno(raiz->esq, modo+10);
        		printf(" - R: ");
        		printArvAluno(raiz->dir, modo+10);
			}
			if(modo >= 10)
				printf(" ] ");
			else
				printf(" ]\n");
			break;
		case 1:
			if(modo < 10)
				printf("[ ");
			if(raiz != NULL){
				printArvAluno(raiz->esq, modo+10);
				printf("%d, ", raiz->numMatricula);
        		printArvAluno(raiz->dir, modo+10);
			}
			if(modo < 10)
				printf(" ]\n");
			break;

		default:
			if(modo < 10)
				printf("[ ");
			if(raiz != NULL){
				printArvAluno(raiz->dir, modo+10);
				printf("%d, ", raiz->numMatricula);
        		printArvAluno(raiz->esq, modo+10);
			}
			if(modo < 10)
				printf(" ]\n");
			break;
	}


}


//Fun��o para medir o valor maximo do no
int maxNoArvAluno(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

//Fun��o para medir a altura da �rvore
int alturaArvAluno(TNoArvAluno *no){
	if(no == NULL)
		return 0;
	return no->altura;
}
//Fun��o para medir o balanceamento da �rvore
int balanArvAluno(TNoArvAluno *no){
	if(no == NULL)
		return 0;
	return alturaArvAluno(no->dir) - alturaArvAluno(no->esq);
}

//Fun��o de rota��o para direita
void rotArvDir (TNoArvAluno *no){
	TNoArvAluno * novoNo = no->esq;
	TNoArvAluno * aux = novoNo->dir;

	novoNo->dir = no;
	no->esq = aux;

	novoNo->altura= maxNoArvAluno(alturaArvAluno(novoNo->dir) , alturaArvAluno(novoNo->esq)) + 1;
	no->altura= maxNoArvAluno(alturaArvAluno(no->dir) , alturaArvAluno(no->esq)) + 1;

}

//Fun��o de rota��o para esquerda
void rotArvEsq (TNoArvAluno *no){
	TNoArvAluno * novoNo = no->dir;
	TNoArvAluno * aux = novoNo->esq;

	novoNo->esq = no;
	no->dir = aux;

	novoNo->altura= maxNoArvAluno(alturaArvAluno(novoNo->dir) , alturaArvAluno(novoNo->esq)) + 1;
	no->altura= maxNoArvAluno(alturaArvAluno(no->dir) , alturaArvAluno(no->esq)) + 1;

}

 int incArvAVLAlunoRec(TAluno aluno, PNoArvAluno *raiz){

	PNoArvAluno folha;
	PNoArvAluno no = *raiz;
	if (*raiz == NULL){ // se a �rvore for vazia
		// Cria um n� folha
		folha = iniNoArvAluno();  // verifica��o de aloca��o
		// Copia as informa��es do aluno neste n�
		cpAlunoNaFolha(aluno, folha);
		// Faz a raiz da �rvore ser o novo n�
		*raiz = folha;
		return TRUE; // o aluno foi inclu�do na �rvore

	}else{ // Caso contrario, tem alguma coisa na �rvore
		// para simpleifica a nota��o, copio o endere�o do n� raiz

		if(aluno.numMatricula > no->numMatricula)
			// incluir na sub�rvore da direita
			return incArvAlunoRec(aluno, &(no->dir));
		else // se n�o
			/* Se a matr�cula do aluno que se quer incluir for
		       menor que a a matr�cula da raiz
			*/
			if(aluno.numMatricula < no->numMatricula)
				// incluir na sub�rvore da esquerda
				return incArvAlunoRec(aluno, &(no->esq));
			else //Se n�o
				/* Ent�o a matr�cula do n� � igual a dp aluno
				   que se deseja incluir e neste casso retorna
				*/
				return FALSE; //O aluno n�o foi incluido
	}

	no->altura = maxNoArvAluno(alturaArvAluno(no->dir) , alturaArvAluno(no->esq))+1; //Para atualizar a altura da �rvore

	int fatorB = balanArvAluno(no); // Para medir o fator de balanceamento do novo no

	/*Situa��o Esquerda-Esquerda*/
	if(fatorB < -1 && aluno.numMatricula < no->esq->numMatricula)
		rotArvDir(no);
	/*Situa��o Direita-Direita*/
	if(fatorB > 1 && aluno.numMatricula > no->dir->numMatricula)
		rotArvEsq(no);
	/*Situa��o Esquerda-Direita*/
	if(fatorB < -1 && aluno.numMatricula > no->esq->numMatricula){
		rotArvEsq(no->esq);
		rotArvDir(no);
	}
	/*Situa��o Direita-Esquerda*/
	if(fatorB > 1 && aluno.numMatricula < no->dir->numMatricula){
		rotArvDir(no->dir);
		rotArvEsq(no);
	}
}

int remArvAVLAluno(TAluno aluno, PNoArvAluno *raiz){
	PNoArvAluno pai, no, p, q;
	no = buscaArvAlunoPai(*raiz, aluno.numMatricula, &pai);
	if(no==NULL)
		return FALSE; // n�o tem esse chave na �rvore
	if(no->esq == NULL || no->dir == NULL){ // se for um no de grau 0 ou 1
		if(no->esq == NULL){ //grau 1 com subarvore a direita
			q = no->dir;
		}else{ //grau 0 ou grau 1 com subarvore a esquerda
			q = no->esq;
		}
	}else{  //� um no de grau 2
		// procurando o no mais a direita da sub�rvore da esquerda
		p = no;
		q = no->esq;
		while(q->dir != NULL){
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
	if(pai==NULL){
		free(no);
		*raiz = q;
		return TRUE;
	}
	if(aluno.numMatricula < pai->numMatricula)
		pai->esq = q;
	else
		pai->dir = q;
	free(no);
	return(TRUE);
}


#define TRUE 1
#define FALSE 0

// Armazenando as informações de um aluno
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

typedef struct{
	TAluno* pilha;
	int cap;  //pilha vazia quando topo = 0
	int topo; //pilha cheia quando topo = cap
}TPilhaAlunos; //last in first out - lifo

typedef struct{
	TAluno* fila;
	int cap;
	int ini; 	//fila vazia quando ini = fim
	int fim;  //fila cheia quando fim - ini = cap
}TFilaAlunos; //first in first out - fifo



// Lista não ordenada
int buscaLisAluno(TAluno lista[], int tam, int chave);
int incLisAluno(TAluno aluno, TAluno lista[], int *tam);
int remLisAluno(TAluno aluno, TAluno lista[], int *tam);

// Lista ordenada
int buscaLisAlunoOrd(TAluno lista[], int tam, int chave);
int incLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);
int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);

void printLisAluno(TAluno lista[], int tam);
void geraAlunos(TListAlunos* lista);

// Para trabalhar com Lista Sequenciais de Alocação Sequencial
void iniListAlunos(TListAlunos* lista, int cap, int eOrd);
int buscaAluno(TListAlunos *lista, int chave);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(TAluno aluno, TListAlunos *lista);

// Pilhas
void iniPilhaAlunos(TPilhaAlunos* pilha, int cap);
int incAlunoNaPilha(TAluno aluno, TPilhaAlunos* pilha);
int remAlunoDaPilha(TAluno* aluno, TPilhaAlunos* pilha);

// Filas
void iniFilaAlunos(TFilaAlunos* fila, int cap);
int incAlunoNaFila(TAluno aluno, TFilaAlunos* fila);
int remAlunoDaFila(TAluno* aluno, TFilaAlunos* fila);
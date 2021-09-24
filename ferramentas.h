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

typedef struct{
	TAluno* lista;
	int cap;
	int tam;
    int eOrd;
} TListAlunos;

// Lista não ordenada
int buscaLisAluno(TAluno lista[], int tam, int chave);
int incLisAluno(TAluno aluno, TAluno lista[], int *tam);
int remLisAluno(TAluno aluno, TAluno lista[], int *tam);
// Lista ordenada

// ATividade 1. Modificar o algoritmo de inc para melhorar o processo
// seguindo recomendação que está no comentario 
int buscaLisAlunoOrd(TAluno lista[], int tam, int chave);
int incLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);
int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);

void printLisAluno(TAluno lista[], int tam);


// Utilizar isto aqui no projeto 
void iniListAlunos(TListAlunos* list, int cap, int eOrd);
int buscaAluno(TListAlunos *lista, int chave);
int incAluno(TAluno aluno, TListAlunos *lista);
int remAluno(TAluno aluno, TListAlunos *lista);
void freeListAlunos(TListAlunos* lista);
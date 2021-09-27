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

int buscaLisAluno(TAluno lista[], int tam, int chave);

int incLisAluno(TAluno aluno, TAluno lista[], int *tam);

void printLisAluno(TAluno lista[], int tam);

int incLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);

int remLisAluno(TAluno aluno, TAluno lista[], int *tam);

int remLisAlunoOrd(TAluno aluno, TAluno lista[], int *tam);

void iniListAlunos(TListAlunos* list, int cap, int eOrd);

int buscaAluno(TListAlunos *lista, int chave);

int buscaLisAlunoOrd(TAluno lista[], int tam, int chave);

int incAluno(TAluno aluno, TListAlunos *lista);

int remAluno(TAluno aluno, TListAlunos *lista);
#define TRUE 1
#define FALSE 0

// Armazenando as informações de um aluno
typedef struct{
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
	int cap;  		//pilha vazia quando topo = 0
	int topo; 		//pilha cheia quando topo = cap
}TPilhaAlunos; 		//last in first out - lifo

typedef struct{
	TAluno* fila;
	int cap;
	int ini; 		//fila vazia quando ini = fim
	int fim;  		//fila cheia quando fim - ini = cap
}TFilaAlunos; 		//first in first out - fifo

struct SNoALuno{
	int numMatricula; 		//chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   		// nome com até 99 caracteres
    char email[100];  		// eMail com até 99 caracteres
	struct SNoALuno *prox; 	// Endereço do próximo elemento
};

typedef struct SNoALuno TNoAluno;
typedef TNoAluno *PNoAluno;

typedef struct{
	PNoAluno lista; //ini
	int tam;
	int eOrd;
}TListEncAlunos;

struct DNoALuno{
	int numMatricula; 		//chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   		// nome com até 99 caracteres
    char email[100];  		// eMail com até 99 caracteres
	struct DNoALuno *prox; 	// Endereço do próximo elemento
	struct DNoALuno *ant; 	// Endereço do elemento anterior
};

typedef struct DNoALuno TDNoAluno;
typedef TDNoAluno *PDNoAluno;

typedef struct{
	PDNoAluno lista; //ini
	int tam;
	int eOrd;
}TListDEncAlunos;

struct SNoArvAluno{
	int numMatricula; 		//chave com 9 dígitos (INT_MAX	+2147483647
    char nome[100];         // nome com até 99 caracteres
    char email[100];        // eMail com até 99 caracteres
	struct SNoArvAluno *dir;
	struct SNoArvAluno *esq;
};

typedef struct SNoArvAluno TNoArvAluno;
typedef TNoArvAluno *PNoArvAluno;




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
void iniListAlunos(TListAlunos* list, int cap, int eOrd);
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

//Listas simplesmente encadeadas

// Lista não ordenada
PNoAluno buscaLisEncAluno(PNoAluno lista, int chave);
int incLisEncAluno(TAluno aluno, PNoAluno lista);
int remLisEncAluno(TAluno aluno, PNoAluno lista);

PNoAluno iniNoAluno(void);
void printLisEncAluno(PNoAluno lista);
PNoAluno criarListEncDeListSeq(TListAlunos* listaS);

//Listas duplamente encadeadas

// Lista não ordenada
PDNoAluno buscaLisDEncAluno(PDNoAluno lista, int chave);
int incLisDEncAluno(TAluno aluno, PDNoAluno lista);
int remLisDEncAluno(TAluno aluno, PDNoAluno lista);

PDNoAluno iniNoDAluno(void);
void printLisDEncAluno(PDNoAluno lista);
PDNoAluno criarListDEncDeListSeq(TListAlunos* listaS);


PNoArvAluno iniNoArvAluno(void);
PNoArvAluno buscaArvAlunoRec(PNoArvAluno raiz, int chave);
PNoArvAluno buscaArvAluno(PNoArvAluno raiz, int chave);
int incArvAlunoRec(TAluno aluno, PNoArvAluno *raiz);
int incArvAluno(TAluno aluno, PNoArvAluno *raiz);
int remArvAluno(TAluno aluno, PNoArvAluno *raiz); 
void printArvAluno_1(PNoArvAluno raiz); 
void printArvAluno_2(PNoArvAluno raiz); 
void printArvAluno_3(PNoArvAluno raiz); 
typedef struct no{
    int numMatricula;
    char nome[100];   // nome com até 99 caracteres
    char email[100];
    struct no *esquerdo, *direito;
    int altura;
}No;


typedef struct{
    int numMatricula; //chave com 9 dígitos (INT_MAX	+2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;


No* novoNo(TAluno aluno);
int maior(int a, int b);
int alturaDoNo(No *no);
int fatorDeBalanceamento(No *no);


/*
 Seçao de Rotações
*/

No* rotacaoEsquerda(No *r);
No* rotacaoDireita(No *r);
No* rotacaoEsquerdaDireita(No *r);
No* rotacaoDireitaEsquerda(No *r);


No* balancear(No *raiz);
No* inserir(No *raiz, TAluno aluno);
No* remover(No *raiz, int chave);
void imprimir(No *raiz, int nivel);

void cpAlunoNaFolha(TAluno aluno, No *folha);
No* geraAlunosNaArv(No* arvore, int qtd);
No* buscaArvAlunoRec(No* raiz, int chave);

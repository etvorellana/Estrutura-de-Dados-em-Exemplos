#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    int resp = -1;
    TListAlunos lista;
    TAluno aluno; 
    TFilaAlunos minhaFila;
    int qnt;

    do{
        printMenu();
        scanf("%d",&resp);
        
        switch (resp){
        
        case 1:
            printf("Digite a quantidade de alunos: ");
            scanf("%d",&qnt);
            while(qnt > LSIZE){
                printf("Quantidade ultrapassa a capacidade maxima!Tente novamente: ");
                scanf("%d",&qnt);
            }
            iniListAlunos(&lista,qnt,FALSE);
            iniFilaAlunos(&minhaFila,LSIZE);
            int op = 1;
            do{
                int matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000; 
		        aluno.numMatricula = matricula;
  		        geraNomes(&aluno);
		        if(!incAluno(aluno, &lista)){
                    if(lista.lista->numMatricula == aluno.numMatricula)
                        printf("Aluno ja esta na lista");
                    else{
                        printf("Lista cheia\n");
                        incAlunoNaFila(aluno,&minhaFila);
                    }
                }
                else
                    incAluno(aluno, &lista);
                printf("Deseja adicionar aluno? <1> sim <0> nao\n");
                scanf("%d",&op);
                
            }while(op != 0 && (minhaFila.fim - minhaFila.ini) != minhaFila.cap);
            
            break;
        
        case 2:
            printf("<1> Alunos utilizando o laboratorio\n<2> Alunos na fila de espera \n");
            int opc;
            scanf("%d",&opc);
            if(opc == 1){
                printf("Lista de Alunos utilizando o laboratorio: \n");
                printLisAluno(lista.lista,qnt);
            }
            if(opc == 2){
                printf("Lista de Alunos esperando na fila: \n");
                printLisAluno(minhaFila.fila,minhaFila.fim);
            }
            break;
        case 3:
            printf("Aluno para remover: ");
            int rem;
            scanf("%d",&rem);
            aluno.numMatricula = rem;
            remAluno(aluno,&lista);
            incAluno(minhaFila.fila[0],&lista);
            remAlunoDaFila(minhaFila.fila,&minhaFila);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!Tente novamente!\n");
            break;
        }
    }while(resp != 0);
    
    return 0;
}


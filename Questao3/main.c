#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "ferramentas.h"

#define LSIZE 10

int main(void)
{
    TAluno aluno;
    TListAlunos lista;
    TPilhaAlunos minhaPilha;
    TFilaAlunos minhaFila;
   
    iniListAlunos(&lista,LSIZE,FALSE);
    iniFilaAlunos(&minhaFila,LSIZE);
    iniPilhaAlunos(&minhaPilha,LSIZE);
    srand(time(NULL));
    int aleat = rand()%1;
    unsigned int matricula;
    
    while (lista.tam < lista.cap) {
        if(aleat == 0){
            matricula = (2000 + rand()%22)*100000 + (1 + rand()%2)*10000 + rand()%10000; 
            if(matricula >= 202120000)
                matricula-=10000;
		    aluno.numMatricula = matricula;
  		    geraNomes(&aluno);
	    	incAluno(aluno,&lista);
            incAlunoNaFila(aluno,&minhaFila);
        }
            
        if(aleat == 1){
            matricula = (2021)*100000 + 2*10000 + rand()%10000; 
		    aluno.numMatricula = matricula;
  		    geraNomes(&aluno);
            incAluno(aluno,&lista);
            incAlunoNaPilha(aluno,&minhaPilha);
        }
        aleat = rand()%2;
    }
    
    printf("Lista inicial: \n");
    printLisAluno(lista.lista,lista.tam);

    for(int i = lista.tam; 0 <= i ; i--)
        remAluno(lista.lista[i],&lista);
    printf("Lista vazia. \n");
    
    
    printf("Fila: \n");
    printLisAluno(minhaFila.fila,minhaFila.fim);
    printf("Fila ini: %d\n",minhaFila.ini);
    printf("Fila fim: %d\n",minhaFila.fim);
    
    printf("Pilha: \n");
    printLisAluno(minhaPilha.pilha,minhaPilha.topo);

    int inicio = minhaFila.ini;
    
    while(inicio != minhaFila.fim){
        incAluno(minhaFila.fila[inicio],&lista);
        inicio++;
        
    }
    for(int i = lista.tam;i < lista.cap;i++){
        incAluno(minhaPilha.pilha[minhaPilha.topo -1],&lista);
        minhaPilha.topo--;
    }
    while(minhaFila.ini < minhaFila.fim){
        if(remAlunoDaFila(minhaFila.fila,&minhaFila)){
            minhaFila.ini--;minhaFila.fim--;
        } 
    }  
        

    
    for(int i = minhaPilha.topo; 0 <= i ; i--)
        remAlunoDaPilha(&minhaPilha.pilha[i],&minhaPilha);
    
    printf("Lista com os calouros no final da fila: \n");
    printLisAluno(lista.lista,lista.tam);

    printf("Fila vazia: \n");
    printLisAluno(minhaFila.fila,minhaFila.fim);
    
    printf("Pilha vazia: \n");
    printLisAluno(minhaPilha.pilha,minhaPilha.topo);
    
    return 0;
}


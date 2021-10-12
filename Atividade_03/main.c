#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ferramentas.h"

int main (void){
    TPilhaAlunos mPilha;
    TListAlunos lista;

    iniPilhaAlunos(&mPilha, LSIZE);
    iniListAlunos(&lista, 2*LSIZE, FALSE);

    geraAlunos(&lista);

    printLisAluno(lista.lista, lista.tam);

    for(int i = 0; i < 2*LSIZE; i++){
        if(incAlunoNaPilha(lista.lista[i], &mPilha))
            remAluno(lista.lista[i] ,&lista);
        else{
            printf("Pilha cheia\n");
            break;
        }
    }

    //printLisAluno(lista.lista, lista.tam);


    return 0;
}

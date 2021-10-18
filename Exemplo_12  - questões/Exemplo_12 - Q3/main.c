#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <time.h>
//BIBLIOTECAS

#include "ferramentas.h"
//FERRAMENTAS

#define LSIZE 10
//TAMANHO MAX

int main(void){

TAluno aluno;
TListAlunos l;
TPilhaAlunos cal;
TFilaAlunos vets;
//VARIAVEIS DO TIPO ESTRUTURA

iniListAlunos(&l, LSIZE, FALSE);
iniPilhaAlunos(&cal, LSIZE);
iniFilaAlunos(&vets, LSIZE);
//INICIALIZANDO VARIAVEIS DO TIPO STRUCT

aluno.numMatricula = 2019240425;
strcpy(aluno.nome,"Luciano Fernandes");
strcpy(aluno.email,"lfernandes.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

aluno.numMatricula = 2020160316;
strcpy(aluno.nome,"Mariana Peres");
strcpy(aluno.email,"mperes.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

aluno.numMatricula = 2017187321;
strcpy(aluno.nome,"Julia Moura");
strcpy(aluno.email,"jmoura.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

aluno.numMatricula = 2018110445;
strcpy(aluno.nome,"Bento Fontes");
strcpy(aluno.email,"bfontes.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

aluno.numMatricula = 2020232692;
strcpy(aluno.nome,"Mila Gutierrez");
strcpy(aluno.email,"mgutierrez.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

aluno.numMatricula = 2021155801;
strcpy(aluno.nome,"Daniel Correia");
strcpy(aluno.email,"dcorreia.cic@uesc.br");
incLisAluno(aluno, l.lista, &l.tam);

printf("\n Lista original dos alunos:");
printLisAluno(l.lista, l.tam);


for(int i = 0; i< l.tam; i++ ){
  if(l.lista[i].numMatricula > 202010000){
  incAlunoNaPilha(l.lista[i], &cal);
}
//SE O NUMERO DE MATRICULA FOR MAIOR QUE O DO 1° SEMESTRE DE 2020, É CALOURO
else{
  incAlunoNaFila(l.lista[i], &vets);
  } //CASO SEJA MENOR, É VETERANO
}

printf("\n Calouros: ");
printLisAluno(cal.pilha, cal.topo);

printf("\n Veteranos: ");
printLisAluno(vets.fila, vets.fim);

return 0;

}
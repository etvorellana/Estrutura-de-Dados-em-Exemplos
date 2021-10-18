# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

* Exemplo_01: Implementação de lista linear numa estrutura de alocação sequencial. Definição do tipo TAluno e declaração das variáveis para definir a capacidade da estrutura sequencial e o tamanho da lista. Declaração do array utilizado para armazenar a lista. Teste com manipulação direta da lista;
* Exemplo_02: Modificação dos exemplos com base na utilização de função específica para busca de um elemento na lista com base no atributo chave;
* Exemplo_03: Modificação dos exemplos com base na utilização de função específica para incluir um elemento na lista mantendo a condição de não ter elementos repetidos. Uma função específica para imprimir a lista também é apresentada;
* Exemplo_04: Estruturação do código com a criação de um arquivo de cabeçalho e de um arquivo para implementação da biblioteca de funções. Adicionado também um  Makefile para automatizar o processo de compilação;
* Exemplo_05: Modificação da função de busca, do Exemplo_03, com a utilização de implementação recursiva, utilizando estruturação de código do Exemplo_04;
* Exemplo_06: Implementação recursiva otimizada para diminuir uma comparação por iteração no algoritmo de busca. Nesta implementação o tamanho do array é sempre a capacidade da lista mais um;
* Exemplo_07: Implementação não recursiva otimizada equivalente com a do Exemplo_06, para diminuir uma comparação por iteração no algoritmo de busca;
* Exemplo_08: Implementação das funções para trabalhar com a lista ordenada. A inclusão e a busca são feitas de forma a garantir que os nós estejam ordenados com base no atributo chave;
* Exemplo_09: Implementação das funções para trabalhar com a lista ordenada utilizando uma versão recursiva da busca binaria. A inclusão e a busca são feitas de forma a garantir que os nós estejam ordenadas com base no atributo chave;
* Exemplo_10: Implementação das funções para trabalhar com a lista ordenada utilizando uma versão não recursiva da busca binaria. A inclusão e a busca são feitas de forma a garantir que os nós estejam ordenadas com base no atributo chave;
* Exemplo_11: Implementação da classe TListAlunos assim como dos métodos 
    * void iniListAlunos(TListAlunos* list, int cap, int eOrd): Cria uma instância da classe alocando um array de tamanho cap (capacidade da lista) de instâncias da struct TAluno. A instância é criada como uma lista ordenada (eOrd = TRUE) ou não ordenada (eOrd = FALSE).
    * int buscaAluno(TListAlunos *lista, int chave): Procura numa instância da classe TListAluno por um TAluno com o número de matrícula específico (chave). 
        * Se a lista for não ordenada retorna: a posição em que o aluno está na lista ou a primeira posição disponível para adicionar o aluno na lista, casso não tenha de nenhum aluno com esse campo chave na lista;
        * Se a ista for ordenada: A posição em que o aluno está na lista ou a posição em que ele deveria ser inserido na lista, casso não tenha de nenhum aluno com esse campo chave na lista;
    * int incAluno(TAluno aluno, TListAlunos *lista): Inclui uma instância da struct TAluno na lista. Retorna TRUE se o aluno for incluído. Casso a lista esteja cheia ou se já tiver outro aluno com o mesmo número de matrícula na lista, retorna FALSE;
    * int remAluno(TAluno aluno, TListAlunos *lista): Remove uma instância da struct TAluno na lista. Retorna TRUE se o aluno for removido. Casso a lista esteja vazia ou se não tiver um aluno com o mesmo número de matrícula na lista, retorna FALSE;
    * O main.c implementa um teste de desempenho utilizando uma lista não ordenada de LSIZE alunos gerados de forma aleatório utilizando a função void geraAlunos(TListAlunos* lista); Com base nessa lista se faz teste de inclusão, busca e remoção de uma lista não ordenada e ordenada de tamanho LSIZE/2 a partir da lista de referência. 
* Exemplo_12:Implementação das classes TPilhaAlunos e TFilaAlunos que permite trabalhar com pilhas e filas de alunos. São implementados também os métodos:
    * void iniPilhaAlunos(TPilhaAlunos* pilha, int cap): Cria uma pilha de instâncias da classe TPilhaALuno alocando uma array de instâncias da strcut TAluno de tamanho cap (capacidade da pilha);
    * int incAlunoNaPilha(TAluno aluno, TPilhaAlunos* pilha): Inclui um TAluno na pilha (empilhar - push). Retorna False se a pilha estiver cheia;
    * int remAlunoDaPilha(TAluno* aluno, TPilhaAlunos* pilha): Remove um TAluno na pilha (desempilhar - pop). Retorna False se a pilha estiver vazia;
    * void iniFilaAlunos(TFilaAlunos* fila, int cap): Cria uma fila de instâncias da classe TPilhaALuno alocando uma array de instâncias da strcut TAluno de tamanho cap (capacidade da fila);
    * int incAlunoNaFila(TAluno aluno, TFilaAlunos* fila): Inclui um TAluno na fila. Retorna False se a fila estiver cheia;
    * int remAlunoDaFila(TAluno* aluno, TFilaAlunos* fila): Remove um TAluno na fila. Retorna False se a fila estiver vazia;
    * O main.c implementa um teste com inclusão e remoção de de filas e pilhas utilizando elementos de uma lista 







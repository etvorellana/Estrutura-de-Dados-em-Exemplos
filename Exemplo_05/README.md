# Estrutura-de-Dados-em-Exemplos
Exemplos para a disciplina de Estrutura de Dados

## Exemplo_05: Implementação de lista linear numa estrutura de alocação sequencial
* Modificação da função de busca, do Exemplo_03, com a utilização de uma versão recursiva, utilizando estruturação de código proposta no Exemplo_04;
* Em cada iteração é avaliado o primeiro elemento de uma sub lista da lista original (lista[0]); 
* São realizadas duas comparações (operações básica):
    * uma para verificar se chegou ao final da lista, ou seja, se a sub lista analisada é uma lista vazia;
    ```
    if (tam == 0)
    ``` 
    * uma para verificar se o primeiro elemento da sub lista analisada tem atributo chave igual ao procurado;
    ```
    lista[0].numMatricula == chave
    ``` 
* Caso a sub lista não seja uma lista vazia, ou o primeiro elemento da sub lista não tenha chave igual à procurada, se faz uma chamada recursiva passando a sub lista menor (tam - 1), começando no segundo elemento (&lista[1]).    
* Com base na implementação recursiva é possível determinar que a função de busca tem Complexidade da ordem de n (O(n));
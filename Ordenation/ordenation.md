# Info Sobre Ordenação

Funções de ordenação para aplicações em diversos códigos e utilidades. Este arquivo contém descrições, lógica de funcionamento, complexidades (tempo e espaço), estabilidade e funções utilitárias da biblioteca.


## Bubble Sort 
Bubble sort é o algoritmo mais simples, mas o menos eficiente. Neste algoritmo, cada elemento da posição i será comparado com o elemento da posição i + 1. Caso o elemento da primeira posição seja maior que o da segunda, eles trocam de lugar, e assim sucessivamente. Por causa dessa forma de execução, o vetor terá que ser percorrido repetidas vezes, tornando o algoritmo ineficiente para listas muito grandes. O método retorna ao início do vetor realizando os mesmos processos de comparações até que a lista esteja totalmente ordenada.
- **Complexidade de Tempo:** $O(n^2)$ em todos os casos.
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Estável.
     
## Bubble Sort Melhorado
É uma otimização simples do Bubble Sort tradicional. Ele introduz uma variável "flag" (sinalizador) para monitorar se alguma troca foi feita durante a passada atual pelo vetor. Se o algoritmo percorrer o vetor inteiro e não realizar nenhuma troca, significa que a lista já está ordenada e ele pode interromper a execução imediatamente, economizando processamento.
- **Complexidade de Tempo:** Melhor caso $O(n)$ (se já estiver ordenado), Pior/Médio caso $O(n^2)$.
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Estável.
   
## Insertion Sort
1. Inicie com uma lista de elementos desordenados.
2. Percorra a lista a partir do segundo elemento até o último.
3. Para cada elemento na parte não ordenada, armazene seu valor em uma variável temporária (chave).
4. Compare o valor do elemento temporário com os elementos na parte ordenada, da direita para a esquerda.
5. Enquanto o elemento temporário for menor que o elemento atual na parte ordenada, desloque o elemento atual para a direita.
6. Insira o elemento temporário na posição correta da parte ordenada.
7. Repita os passos até que toda a lista seja processada.
- **Complexidade de Tempo:** Melhor caso $O(n)$, Pior/Médio caso $O(n^2)$. Excelente para listas pequenas ou quase ordenadas.
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Estável.

## Selection Sort
O algoritmo divide conceitualmente o vetor em duas partes: a sub-lista dos itens já ordenados e a sub-lista dos itens restantes a serem ordenados. A cada iteração, ele busca o menor elemento na parte não ordenada e o troca com o primeiro elemento dessa mesma parte, movendo a "fronteira" da parte ordenada uma posição para a direita.
- **Complexidade de Tempo:** $O(n^2)$ em todos os casos, pois ele sempre precisa escanear o restante do vetor para achar o menor número, independente de como a lista esteja.
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Não estável.



## Heap Sort
O Heap Sort utiliza uma estrutura de dados baseada em árvores binárias chamada Heap Máximo. Primeiro, ele transforma o vetor desordenado em um Heap Máximo (onde o maior elemento fica na raiz/início do vetor). Depois, ele extrai esse maior elemento, coloca no final do vetor, e reconstrói o Heap com os elementos restantes.

> **Observação sobre a implementação:** O código da biblioteca (`ordenation.c`) implementa apenas a abordagem **usando vetores (árvore implícita)**. A comparação com lista encadeada abaixo é mantida apenas para contexto teórico.

```Usando uma lista encadeada:```

**Vantagens**: A implementação usando lista encadeada pode ser mais simples de implementar, pois não é necessário criar uma estrutura de árvore. A inserção e remoção de elementos em uma lista encadeada são mais eficientes do que em uma árvore.

**Desvantagens**: A busca em uma lista encadeada é menos eficiente em comparação com uma árvore, o que pode impactar o desempenho geral do algoritmo. Além disso, a complexidade espacial da lista encadeada é maior, pois são necessários ponteiros adicionais para os nós encadeados.

**Nota sobre Listas Encadeadas:** Implementar Heap Sort diretamente em uma lista encadeada padrão é altamente ineficiente, pois o algoritmo exige acesso direto aos nós (índices), e listas encadeadas requerem travessia sequencial, o que degradaria a performance severamente.

```Usando Vetores (Simulando árvores):```

**Vantagens**: A estrutura de árvore implícita em um vetor (usando índices matemáticos $2i+1$ e $2i+2$) é extremamente eficiente em memória ($O(1)$ de espaço extra) e garante um desempenho previsível e rápido.

**Desvantagens**: A implementação da função heapify exige um entendimento matemático mais sólido e o algoritmo não é estável (pode alterar a ordem original de elementos iguais).

### Funções Auxiliares do Heap Sort:
- `void heapify(int arr[], int n, int i)`: Garante a propriedade de Heap Máximo para a subárvore enraizada no índice `i`. Se um dos filhos for maior que a raiz, faz a troca e propaga o ajuste recursivamente ($O(\log n)$).
- `void swap(int *a, int *b)`: Troca os valores entre dois endereços de memória.

- **Complexidade de Tempo:** $O(n \log n)$ em todos os casos (Melhor, Médio e Pior).
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Não estável.

## QuickSort

**Particionamento**: Um elemento do conjunto é escolhido como pivô. Os elementos são rearranjados de forma que todos os elementos menores que o pivô fiquem à sua esquerda e todos os elementos maiores fiquem à sua direita. O pivô é então colocado em sua posição final e definitiva.

**Recursão**: O Quick Sort é aplicado recursivamente nas partições antes e depois do pivô. Ou seja, o algoritmo é chamado para ordenar os elementos à esquerda do pivô e os elementos à direita do pivô.

**Combinação**: Como o Quick Sort é aplicado de forma recursiva, as soluções parciais são combinadas para obter a solução final, que é o conjunto totalmente ordenado. Ou seja, processo se repete até que os sub-vetores tenham tamanho 1 ou 0, resultando no conjunto totalmente ordenado.

### Funções Auxiliares e Assinatura:
- `void quickSort(int arr[], int inicio, int fimMenosUm)`:
  - **Atenção aos parâmetros:** Diferente de outros métodos que recebem o tamanho total do vetor, o QuickSort espera o índice inicial (`inicio = 0`) e o índice do último elemento válido (`fimMenosUm = tamanho - 1`). Passar o tamanho do vetor diretamente causará acesso fora dos limites (*Out of Bounds*).
- `int particionar(int arr[], int inicio, int fim)`: Seleciona o último elemento como pivô, reorganiza os elementos ao redor dele e retorna o índice final do pivô.
- `void trocar(int *a, int *b)`: Troca os valores entre dois inteiros.

- **Complexidade de Tempo:** Melhor/Médio caso $O(n \log n)$. Pior caso $O(n^2)$ (ocorre se o pivô escolhido for sempre o maior ou menor elemento, embora otimizações na escolha do pivô evitem isso).
- **Complexidade de Espaço:** $O(\log n)$ no caso médio e $O(n)$ no pior caso (devido à profundidade da pilha de recursão).
- **Estabilidade:** Não estável.

## Shell Sort
É uma generalização muito inteligente do Insertion Sort. Em vez de comparar apenas elementos adjacentes, o Shell Sort compara elementos separados por uma certa distância (um "intervalo" ou "gap"). Esse intervalo vai diminuindo a cada iteração até chegar a 1. Isso permite que elementos que estão muito fora de posição cruzem o vetor rapidamente, reduzindo o trabalho das iterações finais.
- **Complexidade de Tempo:** Depende muito da sequência de intervalos escolhida, mas geralmente fica entre $O(n \log n)$ e $O(n^{1.5})$.
- **Complexidade de Espaço:** $O(1)$ (in-place).
- **Estabilidade:** Não estável.


## Funções Extras / Utilitárias

A biblioteca oferece funções auxiliares em `ordenation.h` e `ordenation.c`:

- `void print_vetor(int vetor[], int tamanho)`:
  Imprime na saída padrão todos os elementos do vetor formatados e separados por vírgula.

- `int tamArr(int vetor[], int tamanho_bits)`:
  Calcula a quantidade de elementos de um vetor. 
  - **Lógica e funcionamento:** Quando um vetor é passado como argumento para uma função em C, ele decai para um ponteiro (`int*`), perdendo a informação de quantos elementos possui. Por isso, calcula-se o total de bytes antes da chamada (`sizeof(vetor)`) e passa-se esse valor para a função, que divide pelo tamanho de um único elemento (`sizeof(vetor[0])`):
    $$\text{elementos} = \frac{\text{tamanho\_bits}}{\text{sizeof}(vetor[0])}$$


## Exemplo Prático de Uso

```c
#include <stdio.h>
#include "ordenation.h"

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    
    // Obtendo o tamanho usando tamArr com sizeof
    int n = tamArr(vetor, sizeof(vetor));

    printf("Vetor original:\n");
    print_vetor(vetor, n);

    // Exemplo chamando QuickSort (atenção ao índice final n - 1)
    quickSort(vetor, 0, n - 1);

    // Para outros métodos, a chamada é direta com o tamanho:
    // bubbleSort(vetor, n);
    // bubbleSort_plus(vetor, n);
    // insertionSort(vetor, n);
    // selectionSort(vetor, n);
    // heapSort(vetor, n);
    // shellSort(vetor, n);

    printf("Vetor ordenado:\n");
    print_vetor(vetor, n);

    return 0;
}
```

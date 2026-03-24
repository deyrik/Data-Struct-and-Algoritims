# Info Sobre Ordenação

Funcoes de ordenação para aplicaçoes de diversos codigos e ultilidades: 

Este arquivo contem descriçoes e complexibilidades:

## Bubble Sort 

Bubble sort é o algoritmo mais simples, mas o menos eficientes. 
Neste algoritmo cada elemento da posição i será comparado com o elemento da posição i + 1, ou seja,um elemento da posição 2 será comparado com o elemento da posição 3. Caso o elemento da posição 2 for maior que o da posição 3, eles trocam de lugar e assim sucessivamente. Por causa dessa forma de execução, o vetor terá que ser percorrido quantas vezes que for necessária, tornando o algoritmo ineficiente para listas muito grandes.
O método retorna ao início do vetor realizando os mesmos processos de comparações, isso é feito até que o vetor esteja ordenado.
     
## Bubble Sorte Melhorado
   
## Insertion Sort
Inicie com uma lista de elementos desordenados.
Percorra a lista a partir do segundo elemento até o último.
Para cada elemento na parte não ordenada, armazene seu valor em uma variável temporária.
Compare o valor do elemento temporário com os elementos na parte ordenada, da direita para a esquerda.
Enquanto o elemento temporário for menor que o elemento atual na parte ordenada, desloque o elemento atual para a direita.
Insira o elemento temporário na posição correta da parte ordenada.
Repita os passos 3 a 6 até que todos os elementos da parte não ordenada sejam processados.
A lista estará completamente ordenada.

## Selection Sort



## Heap Sort

```Usando uma lista encadeada:```

**Vantagens**: A implementação usando lista encadeada pode ser mais simples de implementar, pois não é necessário criar uma estrutura de árvore. A inserção e remoção de elementos em uma lista encadeada são mais eficientes do que em uma árvore.

**Desvantagens**: A busca em uma lista encadeada é menos eficiente em comparação com uma árvore, o que pode impactar o desempenho geral do algoritmo. Além disso, a complexidade espacial da lista encadeada é maior, pois são necessários ponteiros adicionais para os nós encadeados.

```Usando árvores:```

**Vantagens**: A estrutura de árvore é eficiente para realizar operações de inserção, remoção e busca, o que pode resultar em um desempenho melhor em comparação com a lista encadeada. Além disso, a complexidade espacial da árvore é menor do que a da lista encadeada.

**Desvantagens**: A implementação de uma árvore pode ser mais complexa do que a lista encadeada, exigindo um código mais elaborado.

## QuickSort

**Particionamento**: Um elemento do conjunto é escolhido como pivô. Os elementos são rearranjados de forma que todos os elementos menores que o pivô fiquem à sua esquerda e todos os elementos maiores fiquem à sua direita. O pivô é então colocado em sua posição final no conjunto ordenado.

**Recursão**: O Quick Sort é aplicado recursivamente nas partições antes e depois do pivô. Ou seja, o algoritmo é chamado para ordenar os elementos à esquerda do pivô e os elementos à direita do pivô.

**Combinação**: Como o Quick Sort é aplicado de forma recursiva, as soluções parciais são combinadas para obter a solução final, que é o conjunto totalmente ordenado.

## Shell Sort




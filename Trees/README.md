# Árvore de Busca Binária (BST - Binary Search Tree) em C

## Descrição da Árvore
A Árvore de Busca Binária (BST) é uma estrutura de dados baseada em nós, onde cada nó possui no máximo dois filhos (esquerda e direita). A principal regra que define uma BST é a sua propriedade de ordenação: para qualquer nó da árvore, todos os elementos na sua sub-árvore **esquerda** são menores ou iguais a ele, e todos os elementos na sua sub-árvore **direita** são estritamente maiores. Isso permite que operações como busca, inserção e remoção sejam feitas de forma muito mais eficiente do que em listas encadeadas simples.

**Pontos Positivos**
* **Busca Eficiente:** Em média, a busca tem complexidade de tempo `O(log n)`, o que significa que ela elimina metade da árvore a cada passo (similar a uma busca binária em vetores).
* **Dados Ordenados:** O percurso em `Ordem` permite recuperar todos os dados da árvore já ordenados de forma crescente instantaneamente.
* **Estrutura Dinâmica:** Cresce e diminui conforme a necessidade, sem precisar alocar um tamanho fixo de memória previamente (como acontece em vetores tradicionais).

**Pontos Negativos**
* **Risco de Desbalanceamento:** Se os dados forem inseridos já ordenados (ex: 1, 2, 3, 4, 5), a árvore perde seu formato e vira uma "linha reta" (lista encadeada), piorando o tempo de busca para `O(n)`.
* **Consumo de Memória:** Cada elemento armazena não apenas o dado, mas também dois ponteiros extras (para a esquerda e direita), ocupando mais espaço na memória.
* **Complexidade na Remoção:** A lógica de remoção de nós (especialmente aqueles com dois filhos) é mais complexa e exige cuidado na manipulação dos ponteiros.

### Descrição das Funções

* **`inicializa(Apontador* no)`**
  Garante que a raiz da árvore aponte para `NULL`, indicando que a árvore foi criada, mas ainda está vazia e pronta para receber elementos.

* **`insere(Apontador *no, Chave X)`**
  Busca recursivamente a posição correta para o novo valor `X` seguindo a regra da BST (menores à esquerda, maiores à direita) e aloca a memória para o novo nó quando encontra um espaço vazio (`NULL`).

* **`ordem(Apontador no)`**
  Percorre a árvore na sequência: Sub-árvore Esquerda -> Raiz -> Sub-árvore Direita. Esse percurso é famoso por imprimir os elementos da árvore em **ordem crescente**.

* **`preOrdem(Apontador no)`**
  Percorre a árvore na sequência: Raiz -> Sub-árvore Esquerda -> Sub-árvore Direita. É muito útil para criar uma cópia da árvore mantendo a mesma estrutura original.

* **`posOrdem(Apontador no)`**
  Percorre a árvore na sequência: Sub-árvore Esquerda -> Sub-árvore Direita -> Raiz. É a estratégia ideal para apagar (dar `free`) em toda a árvore, pois garante que os filhos sejam apagados antes de seus pais.

* **`pesquisarChave(Apontador no, Chave chaveBuscada)`**
  Realiza uma busca binária eficiente. Compara o valor buscado com a raiz atual e desce para a esquerda ou direita até encontrar a chave (retornando-a) ou chegar em um nó nulo (retornando `-1`).

* **`calculaAltura(Apontador no)`**
  Função recursiva que desce até as folhas e volta somando os níveis. Retorna a distância máxima da raiz até a folha mais profunda. Uma árvore com apenas a raiz tem altura 0 (e vazia tem altura -1).

* **`antecessor(Apontador q, Apontador *r)`**
  Função auxiliar usada exclusivamente pela função de remoção. Ela busca o nó mais à direita da sub-árvore esquerda (o maior valor dentre os menores). Esse valor substitui o nó que está sendo removido, mantendo as regras da BST intactas.

* **`retira(Apontador* no, int registro)`**
  Remove um elemento da árvore lidando com 3 casos possíveis:
  1. **Nó Folha / 1 Filho à Direita:** Remove o nó e liga o pai ao filho restante (ou a `NULL`).
  2. **1 Filho à Esquerda:** Remove o nó e liga o pai ao filho esquerdo.
  3. **2 Filhos:** O caso mais complexo. Usa a função `antecessor` para buscar o elemento correto para assumir a
#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Tipo_no* Apontador;// vai guardar o endereço do nó da arvore

/*
Tipo de dado armazenado na arvore, pode ser alterado para quelquer 
tipo de dado, apenas mundandoo typedef */
typedef int Chave;


typedef struct Tipo_no  {
    Chave registro;
    Apontador esq,dir; 

}No;


// inicializa a arvore, criando um nó nulo
void inicializa (Apontador *no);

/*
insere um elemento na arvore, elementos iguais são inseridos à esquerda,
seguindo as regras de inserção da Bynary Search Tree*/
void insere(Apontador *no, Chave X);

//Imprime elementos da arvore em ordem crescente (esquerda, raiz, direita)
void ordem (Apontador no);

//Imprime elementos da arvore em pre-ordem (raiz, esquerda, direita)
void preOrdem(Apontador no);

//Imprime elementos da arvore em pos-ordem (esquerda, direita, raiz)
void posOrdem(Apontador no);

//pesquisa um elemento na arvore, retorna a chave encontrada ou -1 se a chave não for encontrada
Chave pesquisarChave(Apontador no, Chave chaveBuscada);

//calcula a altura da arvore, retorna -1 para arvore vazia, 0 para arvore com um nó, e assim por diante
int calculaAltura(Apontador no);

// int calcularLargura(Apontador no){}

//onde o "q" é nó a ser retirado e "*r" é o nó a esquerda dele
void antecessor(Apontador q, Apontador *r);

//retira registro da arvore.
void retira(Apontador* no, Chave registro);

#endif
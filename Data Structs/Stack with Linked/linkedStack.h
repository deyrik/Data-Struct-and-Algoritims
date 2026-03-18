#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;

typedef struct {
    int Chave;
    /* outros componentes */
} TipoItem;

typedef struct TipoCelula *ApontadorCelula;

typedef struct TipoCelula {
    TipoItem Item;
    ApontadorCelula Prox;
} TipoCelula;

typedef struct {
    ApontadorCelula Fundo, Topo;
    int Tamanho;
} TipoPilha;


/*==================================================================*/

//Cria e inicializa uma pilha vazia, uma head (alocação dinâmica)
void FPVazia(TipoPilha *Pilha);

//Verifica se a pilha está vazia, ou seja, se o topo é igual ao fundo
int Vazia(TipoPilha Pilha);

//Insere um item no topo da pilha, alocando uma nova célula e ajustando os ponteiros
void Empilha(TipoItem x, TipoPilha *Pilha);

//Remove um item do topo da pilha, desalocando a célula correspondente e ajustando os ponteiros
void Desempilha(TipoPilha *Pilha, TipoItem *Item);

//Retorna o número de elementos atualmente na pilha, utilizando o campo Tamanho para contagem
int Tamanho(TipoPilha Pilha);

#endif 
#ifndef LINKEDLIST
#define LINKEDLIST

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula* ApontadorCelula;

typedef struct TipoCelula {
  TipoItem Item;
  ApontadorCelula Prox;
} TipoCelula;

typedef struct {
  ApontadorCelula Primeiro, Ultimo;
} TipoListaEncadeada;

/* ========================================================================= */

//Cria uma lista vazia
void FLVazia(TipoListaEncadeada *Lista);

//Verifica se a lista esta vazia
//Retorna 1 se vazia e 0 caso nao vazia
int Vazia(TipoListaEncadeada Lista);

//Insere um item no final da lista
void Insere(TipoItem x, TipoListaEncadeada *Lista);

//Retira um item da lista
void Retira(ApontadorCelula p, TipoListaEncadeada *Lista, TipoItem *Item);

//Imprime os itens da lista
void Imprime(TipoListaEncadeada Lista);

/* ========================================================================== */


#endif
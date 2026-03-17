/* ========================================================================== */
#ifndef LIST_H
#define LIST_H

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

/*
    quando for necessario mudar os tipos basta mudar as predefiniçoes 
    abaixo e o resto do codigo continua sem precisar alterar.
*/

typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================== */

//Faz a inicializacao da lista 
void FLVazia(TipoLista *Lista);

//Retorna 1 se a lista estiver vazia e 0 caso contrario
int Vazia(TipoLista Lista);

//Adiociona um item no final da lista se a lista nao estiver cheia
void Insere(TipoItem x, TipoLista *Lista);

//Retira um item da posicao p da lista se a posicao for valida
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);

//Percorre e imprime os itens da lista
void Imprime(TipoLista Lista);

/* ========================================================================== */

#endif 

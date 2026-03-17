#ifndef SIMPLESTACK_H
#define SIMPLESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM 1000


typedef int TipoApontador;
typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    /* --- outros componentes --- */
}TipoItem;

typedef struct {
    TipoItem Item[MAXTAM];
    TipoApontador Topo;
} TipoPilha;

//Inicializa a pilha
void FPVazia(TipoPilha *Pilha);

//Verifica se a pilha esta vazia
int Vazia(TipoPilha Pilha);

//adiciona um item a pilha
void Empilha(TipoItem x, TipoPilha *Pilha);

//remove um item da pilha
void Desempilha(TipoPilha *Pilha, TipoItem *Item);

//retorna o tamanho da pilha
int Tamanho(TipoPilha Pilha);

#endif 
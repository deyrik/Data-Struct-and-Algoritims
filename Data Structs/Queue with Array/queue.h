#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXTAM  1000 //util para manipular tamanhos de memoria predefinidos e evitar que sejam usados numeros magicos no codigo

typedef int TipoApontador;

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    /* outros componentes */
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM];
    TipoApontador Frente, Tras;
} TipoFila;

//cria e inicializa uma fila vazia, definindo os ponteiros de frente e tras para a posição inicial
void FFVazia(TipoFila *Fila);

//verifica se a fila está vazia e retorna 1 (verdadeiro) ou 0 (falso).
int Vazia(TipoFila Fila);

//insere item no final da fila
void Enfileira(TipoItem x, TipoFila *Fila);

//remove o item do início da fila e armazena em Item.
void Desenfileira(TipoFila *Fila, TipoItem *Item);

//imprime os itens da fila do mais antigo para o mais recente
void Imprime(TipoFila Fila);

#endif
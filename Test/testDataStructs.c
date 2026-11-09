#include <stdio.h>
#include <stdlib.h>

/* =========================================================================
 * 1. LISTA LINEAR COM ARRANJO (List)
 * ========================================================================= */
#define main main_list_unused
#define TipoChave TipoChave_List
#define TipoApontador TipoApontador_List
#define TipoItem TipoItem_List
#define TipoLista TipoLista_List
#define FLVazia FLVazia_List
#define Vazia Vazia_List
#define Insere Insere_List
#define Retira Retira_List
#define Imprime Imprime_List
#include "../Data Structs/List/list.c"
#undef main
#undef TipoChave
#undef TipoApontador
#undef TipoItem
#undef TipoLista
#undef FLVazia
#undef Vazia
#undef Insere
#undef Retira
#undef Imprime

/* =========================================================================
 * 2. LISTA ENCADEADA (Linked List)
 * ========================================================================= */
#define main main_linkedList_unused
#define TipoChave TipoChave_LinkedList
#define TipoItem TipoItem_LinkedList
#define ApontadorCelula ApontadorCelula_LinkedList
#define TipoCelula TipoCelula_LinkedList
#define TipoListaEncadeada TipoListaEncadeada_LinkedList
#define FLVazia FLVazia_LinkedList
#define Vazia Vazia_LinkedList
#define Insere Insere_LinkedList
#define Retira Retira_LinkedList
#define Imprime Imprime_LinkedList
#include "../Data Structs/Linked List/linkedList.c"
#undef main
#undef TipoChave
#undef TipoItem
#undef ApontadorCelula
#undef TipoCelula
#undef TipoListaEncadeada
#undef FLVazia
#undef Vazia
#undef Insere
#undef Retira
#undef Imprime

/* =========================================================================
 * 3. PILHA COM ARRANJO (Simple Stack)
 * ========================================================================= */
#define main main_simpleStack_unused
#define TipoApontador TipoApontador_SimpleStack
#define TipoChave TipoChave_SimpleStack
#define TipoItem TipoItem_SimpleStack
#define TipoPilha TipoPilha_SimpleStack
#define FPVazia FPVazia_SimpleStack
#define Vazia Vazia_SimpleStack
#define Empilha Empilha_SimpleStack
#define Desempilha Desempilha_SimpleStack
#define Tamanho Tamanho_SimpleStack
#include "../Data Structs/Simple Stack/simpleStack.c"
#undef main
#undef TipoApontador
#undef TipoChave
#undef TipoItem
#undef TipoPilha
#undef FPVazia
#undef Vazia
#undef Empilha
#undef Desempilha
#undef Tamanho

/* =========================================================================
 * 4. PILHA ENCADEADA (Stack with Linked List)
 * ========================================================================= */
#define main main_linkedStack_unused
#define TipoChave TipoChave_LinkedStack
#define TipoItem TipoItem_LinkedStack
#define ApontadorCelula ApontadorCelula_LinkedStack
#define TipoCelula TipoCelula_LinkedStack
#define TipoPilha TipoPilha_LinkedStack
#define FPVazia FPVazia_LinkedStack
#define Vazia Vazia_LinkedStack
#define Empilha Empilha_LinkedStack
#define Desempilha Desempilha_LinkedStack
#define Tamanho Tamanho_LinkedStack
#include "../Data Structs/Stack with Linked/linkedStack.c"
#undef main
#undef TipoChave
#undef TipoItem
#undef ApontadorCelula
#undef TipoCelula
#undef TipoPilha
#undef FPVazia
#undef Vazia
#undef Empilha
#undef Desempilha
#undef Tamanho

/* =========================================================================
 * 5. FILA COM ARRANJO (Queue with Array)
 * ========================================================================= */
#define main main_queue_unused
#define TipoApontador TipoApontador_Queue
#define TipoChave TipoChave_Queue
#define TipoItem TipoItem_Queue
#define TipoFila TipoFila_Queue
#define FFVazia FFVazia_Queue
#define Vazia Vazia_Queue
#define Enfileira Enfileira_Queue
#define Desenfileira Desenfileira_Queue
#define Imprime Imprime_Queue
#include "../Data Structs/Queue with Array/queue.c"
#undef main
#undef TipoApontador
#undef TipoChave
#undef TipoItem
#undef TipoFila
#undef FFVazia
#undef Vazia
#undef Enfileira
#undef Desenfileira
#undef Imprime


/* =========================================================================
 * FUNÇÕES DE TESTE
 * ========================================================================= */

void testListaLinear() {
    printf("==================================================\n");
    printf("  TESTE: LISTA LINEAR SEQUENCIAL (ARRAY)\n");
    printf("==================================================\n");
    TipoLista_List lista;
    TipoItem_List item;

    FLVazia_List(&lista);
    printf("1. Lista inicializada. Vazia? %s\n", Vazia_List(lista) ? "SIM (1)" : "NAO (0)");

    int valores[] = {10, 25, 40, 55, 70};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("2. Inserindo elementos: ");
    for (int i = 0; i < n; i++) {
        item.Chave = valores[i];
        Insere_List(item, &lista);
        printf("%d ", item.Chave);
    }
    printf("\n");

    printf("3. Vazia apos insercao? %s\n", Vazia_List(lista) ? "SIM (1)" : "NAO (0)");
    printf("4. Imprimindo lista completa:\n");
    Imprime_List(lista);

    printf("5. Retirando elemento da posicao 2 (chave esperada: 25)...\n");
    Retira_List(2, &lista, &item);
    printf("   Elemento retirado: %d\n", item.Chave);

    printf("6. Imprimindo lista apos remocao:\n");
    Imprime_List(lista);
    printf("\n");
}

void testListaEncadeada() {
    printf("==================================================\n");
    printf("  TESTE: LISTA ENCADEADA (PONTEIROS)\n");
    printf("==================================================\n");
    TipoListaEncadeada_LinkedList lista;
    TipoItem_LinkedList item;

    FLVazia_LinkedList(&lista);
    printf("1. Lista encadeada inicializada. Vazia? %s\n", Vazia_LinkedList(lista) ? "SIM (1)" : "NAO (0)");

    int valores[] = {100, 200, 300, 400, 500};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("2. Inserindo elementos: ");
    for (int i = 0; i < n; i++) {
        item.Chave = valores[i];
        Insere_LinkedList(item, &lista);
        printf("%d ", item.Chave);
    }
    printf("\n");

    printf("3. Vazia apos insercao? %s\n", Vazia_LinkedList(lista) ? "SIM (1)" : "NAO (0)");
    printf("4. Imprimindo lista encadeada completa:\n");
    Imprime_LinkedList(lista);

    printf("5. Retirando primeiro elemento util (chave esperada: 100)...\n");
    Retira_LinkedList(lista.Primeiro, &lista, &item);
    printf("   Elemento retirado: %d\n", item.Chave);

    printf("6. Imprimindo lista encadeada apos remocao:\n");
    Imprime_LinkedList(lista);
    printf("\n");
}

void testPilhaEstatica() {
    printf("==================================================\n");
    printf("  TESTE: PILHA SEQUENCIAL (SIMPLE STACK - ARRAY)\n");
    printf("==================================================\n");
    TipoPilha_SimpleStack pilha;
    TipoItem_SimpleStack item;

    FPVazia_SimpleStack(&pilha);
    printf("1. Pilha inicializada. Vazia? %s (Tamanho: %d)\n", 
           Vazia_SimpleStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_SimpleStack(pilha));

    int valores[] = {5, 15, 25, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("2. Empilhando elementos (Push): ");
    for (int i = 0; i < n; i++) {
        item.Chave = valores[i];
        Empilha_SimpleStack(item, &pilha);
        printf("%d ", item.Chave);
    }
    printf("\n");

    printf("3. Pilha apos push. Vazia? %s (Tamanho: %d)\n", 
           Vazia_SimpleStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_SimpleStack(pilha));

    printf("4. Desempilhando elementos (Pop - ordem LIFO):\n");
    while (!Vazia_SimpleStack(pilha)) {
        Desempilha_SimpleStack(&pilha, &item);
        printf("   Desempilhou: %d (Tamanho restante: %d)\n", item.Chave, Tamanho_SimpleStack(pilha));
    }
    printf("5. Pilha ao final. Vazia? %s (Tamanho: %d)\n\n", 
           Vazia_SimpleStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_SimpleStack(pilha));
}

void testPilhaEncadeada() {
    printf("==================================================\n");
    printf("  TESTE: PILHA ENCADEADA (STACK WITH LINKED)\n");
    printf("==================================================\n");
    TipoPilha_LinkedStack pilha;
    TipoItem_LinkedStack item;

    FPVazia_LinkedStack(&pilha);
    printf("1. Pilha encadeada inicializada. Vazia? %s (Tamanho: %d)\n", 
           Vazia_LinkedStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_LinkedStack(pilha));

    int valores[] = {11, 22, 33, 44, 55};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("2. Empilhando elementos (Push): ");
    for (int i = 0; i < n; i++) {
        item.Chave = valores[i];
        Empilha_LinkedStack(item, &pilha);
        printf("%d ", item.Chave);
    }
    printf("\n");

    printf("3. Pilha apos push. Vazia? %s (Tamanho: %d)\n", 
           Vazia_LinkedStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_LinkedStack(pilha));

    printf("4. Desempilhando elementos (Pop - ordem LIFO):\n");
    while (!Vazia_LinkedStack(pilha)) {
        Desempilha_LinkedStack(&pilha, &item);
        printf("   Desempilhou: %d (Tamanho restante: %d)\n", item.Chave, Tamanho_LinkedStack(pilha));
    }
    printf("5. Pilha ao final. Vazia? %s (Tamanho: %d)\n\n", 
           Vazia_LinkedStack(pilha) ? "SIM (1)" : "NAO (0)", Tamanho_LinkedStack(pilha));
}

void testFilaCircular() {
    printf("==================================================\n");
    printf("  TESTE: FILA CIRCULAR COM ARRANJO (QUEUE)\n");
    printf("==================================================\n");
    TipoFila_Queue fila;
    TipoItem_Queue item;

    FFVazia_Queue(&fila);
    printf("1. Fila inicializada. Vazia? %s\n", Vazia_Queue(fila) ? "SIM (1)" : "NAO (0)");

    int valores[] = {7, 14, 21, 28, 35};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("2. Enfileirando elementos: ");
    for (int i = 0; i < n; i++) {
        item.Chave = valores[i];
        Enfileira_Queue(item, &fila);
        printf("%d ", item.Chave);
    }
    printf("\n");

    printf("3. Fila apos insercoes. Vazia? %s\n", Vazia_Queue(fila) ? "SIM (1)" : "NAO (0)");
    printf("4. Imprimindo fila:\n");
    Imprime_Queue(fila);

    printf("5. Desenfileirando 2 elementos (ordem FIFO):\n");
    for (int i = 0; i < 2; i++) {
        Desenfileira_Queue(&fila, &item);
        printf("   Desenfileirou: %d\n", item.Chave);
    }

    printf("6. Imprimindo fila restante:\n");
    Imprime_Queue(fila);

    printf("7. Esvaziando fila restante:\n");
    while (!Vazia_Queue(fila)) {
        Desenfileira_Queue(&fila, &item);
        printf("   Desenfileirou: %d\n", item.Chave);
    }
    printf("8. Fila ao final. Vazia? %s\n\n", Vazia_Queue(fila) ? "SIM (1)" : "NAO (0)");
}

int main(int argc, char const *argv[]) {
    printf("##################################################\n");
    printf("#     BATERIA DE TESTES - ESTRUTURAS DE DADOS    #\n");
    printf("##################################################\n\n");

    testListaLinear();
    testListaEncadeada();
    testPilhaEstatica();
    testPilhaEncadeada();
    testFilaCircular();

    printf("##################################################\n");
    printf("#     TODOS OS TESTES CONCLUIDOS COM SUCESSO!    #\n");
    printf("##################################################\n");

    return 0;
}

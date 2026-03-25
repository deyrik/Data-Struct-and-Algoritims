#include "BST.h"

//cria um nó nulo de arvore BST
void inicializa (Apontador* no){
    *no = NULL;
    printf("Criada arvore BST com sucesso...\n");

};

void insere (Apontador *no, Chave X){
    if (*no == NULL){
        *no = (Apontador) malloc(sizeof(No));
        (*no)->registro = X;
        (*no)->esq = NULL;
        (*no)->dir = NULL; 
        printf("Incersao bem sucedida\n");
        return;
    }

    //se no for menor que o numero for inserido vai para direita dele
    if (X > (*no)->registro)
    {
        insere(&(*no)->dir,X);
        return;
    }

    //se no for maior que o numero for inserido vai para esquerda dele
    if (X <= (*no)->registro)
    {
        insere(&(*no)->esq,X);
        return;
    }
};

void ordem(Apontador no){
    if (no == NULL) {

        return; 
    }
    
    ordem(no->esq);
    printf("%d ", no->registro);
    ordem(no->dir);
}

void preOrdem(Apontador no){
    if (no == NULL) {
        return;
    }

    printf("%d ", no->registro);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void posOrdem(Apontador no){
    if (no == NULL) {
        return;
    }
    
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ", no->registro);
}

Chave pesquisarChave(Apontador no, Chave chaveBuscada){
    if (no == NULL) {
        printf("Chave %d nao encontrada na arvore.\n", chaveBuscada);
        return -1; // Retorna -1 se a chave não for encontrada
    }

    if (chaveBuscada == no->registro) {
        printf("Chave %d encontrada na arvore.\n", chaveBuscada);
        return no->registro; // Retorna a chave encontrada
    }

    if (chaveBuscada < no->registro) {
        return pesquisarChave(no->esq, chaveBuscada);
    } else {
        return pesquisarChave(no->dir, chaveBuscada);
    }

}

int calculaAltura(Apontador no){
    if (no == NULL) {
        return -1; // Altura de uma árvore vazia é -1
    }

    int alturaEsq = calculaAltura(no->esq);
    int alturaDir = calculaAltura(no->dir);

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

//int calcularLargura(Apontador no){}

void antecessor(Apontador q, Apontador *r){
    Apontador aux;
    if ((*r)->dir != NULL)
    {
        antecessor(q, &(*r)->dir);
        return;
    }
    q->registro = (*r) ->registro;
    aux = *r;
    *r = (*r)->esq;
    free(aux);
    
}

void retira(Apontador* no, int registro) {
    // 1. Caso base: Chegou no fim e não achou
    if ((*no) == NULL) {
        printf("Elemento nao existe ou a arvore esta vazia\n");
        return; // É importante dar return aqui para parar!
    }

    // 2. Busca pelo nó
    if (registro < (*no)->registro) {
        retira(&(*no)->esq, registro);
    } 
    else if (registro > (*no)->registro) {
        retira(&(*no)->dir, registro);
    } 
    // 3. ACHOU O NÓ! (registro == (*no)->registro)
    else {
        Apontador auxiliar = *no;

        // Caso A: O nó só tem filho na direita (ou é uma folha sem filhos)
        if ((*no)->esq == NULL) {
            *no = (*no)->dir; // O pai agora aponta para o filho da direita
            free(auxiliar);
            printf("Registro retirado com sucesso!!!\n");
        }
        // Caso B: O nó só tem filho na esquerda
        else if ((*no)->dir == NULL) {
            *no = (*no)->esq; // O pai agora aponta para o filho da esquerda
            free(auxiliar);
            printf("Registro retirado com sucesso!!!\n");
        }
        // Caso C: O nó tem os dois filhos
        else {
            // Usa a sua função antecessor maravilhosa
            // Ela vai pegar o maior elemento da sub-árvore esquerda
            antecessor(*no, &(*no)->esq);
            printf("Registro retirado com sucesso!!!\n");
        }
    }
}
#include "../Trees/BST.h"

int main()
{
    
    Apontador arvore;

    inicializa(&arvore);
    ordem(arvore); // nao pode imprimir nada, pois a arvore esta vazia

    insere(&arvore,3);
    insere(&arvore,7);
    insere(&arvore,6);
    insere(&arvore,8);
    insere(&arvore,1);
    insere(&arvore,2);
    insere(&arvore,5);
    insere(&arvore,4);
    insere(&arvore,9);
    insere(&arvore,12);
    insere(&arvore,13);
    insere(&arvore,22);
    insere(&arvore,24);
      


    printf("\nImprimindo a arvore em ordem crescente: \n");
    ordem(arvore);
    printf("\nImprimindo a arvore em pre-ordem: \n");
    preOrdem(arvore);
    printf("\nImprimindo a arvore em pos-ordem: \n");
    posOrdem(arvore);
    printf("\n");

    printf("\n");
    pesquisarChave(arvore, 8);
    pesquisarChave(arvore, 1);
    pesquisarChave(arvore, 100);
    pesquisarChave(arvore, -1);
    printf("\n");

    printf("\n");
    retira(&arvore, 100);
    retira(&arvore, 24);
    retira(&arvore, 3);
    printf("\n");


    printf("\nImprimindo a arvore em ordem crescente: \n");
    ordem(arvore);
    printf("\n");

    return 0;
}
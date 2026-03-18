#include "linkedStack.h"

void FPVazia(TipoPilha *Pilha){ 
    Pilha->Topo = (ApontadorCelula) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
} 

int Vazia(TipoPilha Pilha){ 
    return (Pilha.Topo == Pilha.Fundo); 
} 

void Empilha(TipoItem x, TipoPilha *Pilha){ 
    ApontadorCelula Aux;
    Aux = (ApontadorCelula) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;

    //o aux aponta para o prox ("topo da lista"), e o topo da lista passa a ser o aux.

} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item){ 
    if (Vazia(*Pilha)) { 
        printf("Erro: lista vazia\n"); 
        return; 
    }
    ApontadorCelula q;
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);  
    Pilha->Tamanho--;

    // q recebe topo da pilha 
    //"topo da pilha" recebe o de baixo (q->prox)
    // o item recebe o item do topo da pilha (q->prox->item) e pode ser usado fora da função
    // libera memoria de q, que era o topo da pilha, e decrementa o tamanho da pilha

} 

int Tamanho(TipoPilha Pilha){
    return (Pilha.Tamanho); 
} 

/*====================================================================*/

int main(int argc, char *argv[])
{ struct timeval t;
  TipoPilha pilha;
  TipoItem item;
  int vetor[MAX];
  int i, j, k, n;
 
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
 
  FPVazia(&pilha);
  
  /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
  for(i = 0; i < MAX; i++) vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
    { k =  (int) (10.0*rand()/(RAND_MAX + 1.0));

      j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Empilha cada chave */
  for (i = 0; i < MAX; i++)
    { item.Chave = vetor[i];
      Empilha(item, &pilha);
      printf("Empilhou: %d \n", item.Chave);
    }
  printf("Tamanho da pilha: %d \n", Tamanho(pilha));
  

  /*Desempilha cada chave */
  for(i = 0; i < MAX; i++)
    { Desempilha (&pilha,&item);
      printf ("Desempilhou: %d \n", item.Chave);
    }
  printf("Tamanho da pilha: %d\n", Tamanho(pilha));
  return(0);
}



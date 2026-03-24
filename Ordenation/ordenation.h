#include <stdio.h>
#include <stdlib.h>


//_____________________________ORDENAÇÂO SIMPLES _____________________________________



//Bubble Sort normal 
void bubbleSort(int*, int);

//Bubble Sort melhorado.
void bubbleSort_plus(int*, int);

//Inseroin Sort
void insertionSort(int*, int);

//Selection Sort
void selectionSort(int*, int);



//_____________________________ORDENAÇÂO COMPLEXA _____________________________________


//HEAP SORT - Usando arvores binarias 

// Função auxiliar para trocar dois elementos
void swap(int*, int*);

// Função para ajustar um sub-árvore enraizada em um índice específico
void heapify(int*, int, int);

// Função principal que implementa o algoritmo Heap Sort
void heapSort(int*, int);





//QuickSort
// Função para trocar os valores de dois elementos
void trocar(int* a, int* b);

// Função para particionar o array e retornar o índice do pivô
int particionar(int arr[], int inicio, int fim);

// Função principal do Quick Sort
//inicio == 0 &&  fim == posiçao final - 1 
void quickSort(int arr[], int inicio, int fimMenosUm);





//shell  sort 
void shellSort(int*, int); 

//_____________________________EXTRAS_____________________________________
 
void print_vetor(int*,int);

//calcula tamanho de qualquer vetor
int tamArr(int*,int); 





























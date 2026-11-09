#include "../Ordenation/ordenation.h"

int main(int argc, char const *argv[]){


    int vetor1[] = {2,0,1,7,3,5,4,6};
    int vetor2[] = {2,0,1,7,3,5,4,6};
    int vetor3[] = {2,0,1,7,3,5,4,6};
    int vetor4[] = {2,0,1,7,3,5,4,6};
    int vetor5[] = {2,0,1,7,3,5,4,6};
    int vetor6[] = {2,0,1,7,3,5,4,6};
    int vetor7[] = {2,0,1,7,3,5,4,6};
    int vetor8[] = {2,0,1,7,3,5,4,6};

    int tamanho = tamArr(vetor1,sizeof(vetor1));
    printf("oririnal array:\n");
    print_vetor(vetor1,tamanho);
    printf("\n\n");

    printf("ordenated arrays:\n");

    printf("bubble sort:\n");
    bubbleSort(vetor1,tamanho);
    print_vetor(vetor1,tamanho);

    printf("bubble sort plus:\n");
    bubbleSort_plus(vetor2, tamanho);
    print_vetor(vetor2,tamanho);

    printf("insertion sort:\n");
    insertionSort(vetor3,tamanho);
    print_vetor(vetor3,tamanho);

    printf("selection sort:\n");
    selectionSort(vetor4,tamanho);
    print_vetor(vetor4,tamanho);

    printf("heap sort:\n");
    heapSort(vetor5,tamanho);
    print_vetor(vetor5,tamanho);

    printf("quick sort:\n");
    quickSort(vetor6,0,tamanho-1);
    print_vetor(vetor6,tamanho);

    printf("shell sort:\n");
    shellSort(vetor7,tamanho);
    print_vetor(vetor7,tamanho);
    
    //printf("merge sort:\n");
    //mergeSort(vetor8,0,tamanho-1);
    //print_vetor(vetor8,tamanho);

    return 0;

}
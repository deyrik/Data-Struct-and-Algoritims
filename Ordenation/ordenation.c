#include "ordenation.h"

//Bubble Sort normal 
void bubbleSort(int vetor[], int tamanho){
	int buffer, i, j;
	for(j=tamanho-1; j>=1; j--){ 
		for(i=0; i<j; i++){ 
			if(vetor[i]>vetor[i+1]){ 
				buffer=vetor[i];
                    vetor[i]=vetor[i+1];//posiçao recebe o valor da seguinte (que é menor)
                    vetor[i+1]=buffer;//posiçao seguinte recebe o valor que esta no buffeer (que é maior)
            }
        }
    }
}

//Bubble Sort melhorado.
void bubbleSort_plus(int vetor[], int tamanho){   
	int buffer, troca, i, j;
	troca=1; /*A variável "troca" será a verificação da troca em cada passada*/
	for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0; /*Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.*/
		for(i=0; i<j; i++){
				if(vetor[i]>vetor[i+1]){
					buffer=vetor[i];
					vetor[i]=vetor[i+1];
					vetor[i+1]=buffer;  
					troca=1; /*Se houve troca, "troca" recebe 1 para continuar rodando.*/
			}
		}
	}
}

//insertion Sort.
void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
                       j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

//Selection Sort.
void selectionSort(int vetor[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Encontra o índice do menor elemento restante
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o elemento atual pelo menor elemento encontrado
        temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}




//_____________________________ORDENAÇÂO COMPLEXA _____________________________________


//____HEAP SORT COM ARVORE:
// Função auxiliar para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar um sub-árvore enraizada em um índice específico
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // Índice do filho esquerdo
    int right = 2 * i + 2; // Índice do filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Se o filho direito for maior que a raiz
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursivamente ajusta a sub-árvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal que implementa o algoritmo Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai elementos um a um do heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Move a raiz atual para o final
        heapify(arr, i, 0); // Chama heapify na heap reduzida
    }
}

//____HEAP SORT COM LISTA ENCADEADA:





//QuickSort 
// Função para trocar os valores de dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array e retornar o índice do pivô
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim];    // Considera o último elemento como pivô
    int i = inicio - 1;     // Índice do menor elemento

    for (int j = inicio; j < fim; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++;    // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);
    return i + 1;
}

// Função principal do Quick Sort
//inicio == 0 &&  fim == posiçao final - 1 
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice do pivô após a partição
        int indicePivo = particionar(arr, inicio, fim);

        // Ordena recursivamente os elementos antes e depois do pivô
        quickSort(arr, inicio, indicePivo - 1);
        quickSort(arr, indicePivo + 1, fim);
    }
}





//Shell sort 
void shellSort(int arr[], int n) {
    // Define o tamanho do intervalo inicial
    int intervalo = 1;
    while (intervalo < n / 3) {
        intervalo = 3 * intervalo + 1;
    }

    // Aplica o algoritmo de inserção para cada intervalo
    while (intervalo > 0) {
        for (int i = intervalo; i < n; i++) {
            int chave = arr[i];
            int j = i;

            // Move os elementos do intervalo ordenadamente
            while (j >= intervalo && arr[j - intervalo] > chave) {
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }

            arr[j] = chave;
        }

        // Reduz o tamanho do intervalo
        intervalo /= 3;
    }
}










//extra
void print_vetor(int vetor[],int tamanho){

	for ( int i = 0; i < tamanho; i++)
	{
		printf("%d, ",vetor[i]);
	}
	printf("\n");
}


/*
calcula o tamanho do vetor: (tamanho array)
 (caso mude o tipo do vetor, deve-se mudar o tipo no paramtro da função, nao no retorno)
 nao podemos passar apenas um vetor para a função , pois qndo entra na funcao , o vetor e tratado/decai 
 para um ponteiro, perdendo assim a informação de tamanho;
 entao basta calcular o tamnho de bits do vetor antes de entrar na função, levar a informaçao para dentro
 da funcao e la dividir pelo numero de bits de uma so elemnto do vetor(e possivel pois o ponteiro 
 esta apontando para um endereço , e podemos saber quantos bits esse endereço gasta), assim achamos o 
 numero total de elementos. 
*/
int tamArr(int vetor[],int tamanho_bits){

    int elementos;
    return elementos = tamanho_bits / sizeof(vetor[0]);

}

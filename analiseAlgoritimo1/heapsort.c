#include <stdio.h>

// Função swap corrigida e usando ponteiros corretamente
void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void maxHeap(int arr[], int tam, int i){
    int pai = i; // pai começa igual ao índice do loop
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // CORREÇÃO 1: Compara valor com valor (arr[left] > arr[pai])
    if(left < tam && arr[left] > arr[pai]){ 
        pai = left;
    }

    if(right < tam && arr[right] > arr[pai]){
        pai = right;
    }

    if (pai != i){
        // CORREÇÃO 2: Passa os endereços corretos (&) e troca a raiz original (i) com o maior (pai)
        swap(&arr[i], &arr[pai]);

        // Chama o maxheap com o mesmo valor porém em uma posição inferior da árvore
        maxHeap(arr, tam, pai); 
    }
}

void heapSort(int arr[], int tam){
    // Começa pelo último pai possível e constrói o Heap Perfeito
    for(int pai = tam / 2 - 1; pai >= 0; pai--){ 
        maxHeap(arr, tam, pai); 
    }

    // Extração e rearranjo
    for(int i = tam - 1; i > 0; i--){
        swap(&arr[i], &arr[0]); // Move o maior para o final

        // CORREÇÃO 3: Passa 'i' como o novo tamanho para isolar o final
        maxHeap(arr, i, 0); 
    }
}

int main(){
    int arr[] = {430, 189, 96, 999, 4, 170, 531, 391, 111};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    
    heapSort(arr, tam);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
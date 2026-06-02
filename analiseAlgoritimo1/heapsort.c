#include <stdio.h>

int swap(int* a, int* b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

int maxHeap(int arr[],int tam,int i){
    int pai=i; //pai e igual ao indice do loop
    int left=2*i+1;
    int right=2*i+2;
    

    if(left<tam && arr[left]>arr[pai]){ // se o filho esquerdo for maior que o pai
        pai=left;
    }

    if(right<tam && arr[right]>arr[pai]){
        pai=right;
    }

    if (pai != i){
        swap(&arr[pai],&arr[pai]);

        maxHeap(arr,tam,pai); 
//chama o maxheap com o mesmo valor pai porem em uma posição inferior da arvore
    }
    

}

int heapSort(int arr[],int tam){

    for(int pai = tam/2-1;pai>=0;pai--){ //começa pelo ultimo pai possivel
        //constroi uma base solida (heap perfeito) 
        //para o proximo for (extração e rearanjo)
        maxHeap(arr,tam,pai); 
        
    }

    for(int i=tam-1;i>=0;i--){
        swap(&arr[i],&arr[0]);

        maxHeap(arr,i,0);
    }
}





int main(){
    int arr[]={430,189,96,999,4,170,531,391,111};

    int tam= sizeof(arr)/sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    
    heapSort(arr, tam);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
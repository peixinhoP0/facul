#include <stdio.h>

void troca(int *a,int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
    

}

void quick(int arr[],int tam){

}

void partition(int arr[],int tam){
    int pivot=arr[0];
    int aux[tam],aux2[tam];
    int idx=0;
    for(int i=1; i<tam-1;i++){
        if(arr[i]<=pivot){
            aux[idx]=arr[i];
            idx++;
        }
        else{

        }

    }

}



int main(){
    int arr[]={4,6,10,1,8,99,1,35,2,0,10,20};
    int tam;
    tam= sizeof(arr)/sizeof(arr[0]);

    quick(arr,tam);

    printf("Vetor ordenado sem nos: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    

    return 0;

}
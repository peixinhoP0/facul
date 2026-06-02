#include <stdio.h>

void coutingS(int arr[], int exp, int tam){

    int aux[tam];
    int count[10]={0};

    //calcula qnt dos numeros

    for(int i=0;i<tam;i++){

        int digito = (arr[i]/exp)%10;

        count[arr[digito]]++;
    }

    //calcula os prefixos

    for(int i=1;i<tam;i++){

        count[i]+= count[i-1];
    }

    //aloca os elementos baseando-se na posição dos prefixos
    //digamos que o prefixo count[7]=3; então o proximo elemento
    //menor que 7 Será colocado na posição 3 de depois decrementa o count[7]
    for (int i =tam-1;i>=0;i--){
        int digito= (arr[i]/exp)%10;

        aux[count[digito]-1]=arr[i];
        count[digito]--;
    }

    for(int i=0;i<tam;i++){
        arr[i]=aux[i];
    }
}

void radix(int arr[],int tam){

    int max=0;
    for(int i=0; i<tam-1;i++){
        if (max<arr[i]){
            max=arr[i];
        }
    }

    for (int exp=1;max/exp;exp*=10){
        coutingS(arr, exp,tam);
    }

}




int main(){
    int arr[]={430,189,96,999,4,170,531,391,111};

    int tam= sizeof(arr)/sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    
    radix(arr, tam);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


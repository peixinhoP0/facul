#include <stdio.h>
//#include <omp.h>

void troca(int*a, int*b){
int aux;
aux=*a;
*a=*b;
*b=aux;
}

void bubble(int arr[], int tam){
    for (int i=0; i<=tam-1;i++){
        for (int j=0; j<=tam-i-1;j++){
            if(arr[j]>arr[j+1]){
                troca(&arr[j],&arr[j+1]);
            }

        }
    }
}


void bucket(int arr[],int tam){
    int maior=arr[0];
    for(int i=0;i<tam;i++){
        if(arr[i]>maior){
            maior=arr[i];
        }
    }

    int buckets=maior;
    int qnt_baldes= (maior/10)+1;
    int matriz_buckets [buckets] [tam];
    int balde_idx [qnt_baldes];

    //coloca no barde
    for(int i=0; i<=tam-1;i++){
        int balde= arr[i]/10;
        matriz_buckets [balde][balde_idx[balde]]= arr[i];
        balde_idx[balde]++;
    
}
    //ordena os numeros nos bardes
    for (int i=0;i<tam;i++){
        if (balde_idx[i]>1){//se o barde tiver mais de um elemento
        bubble(matriz_buckets[i], balde_idx[i]);    //ordena 
        }

    }
    //recoloca os numeros dos bardes na ordem certa
    int indice_vazio=0;//indice do arr original para sobrepor pelos valores ordenados
    for(int i=0;i<buckets;i++){
        for(int j=0;j<balde_idx[i];j++){
        arr[indice_vazio]=matriz_buckets[i][j];
        indice_vazio++;

        }

    }

}




int main(){
    int arr[]={4,6,10,1,8,99,1,35,2,0,10,20};
    int tam;
    tam= sizeof(arr)/sizeof(arr[0]);

    bucket(arr,tam);

    printf("Vetor ordenado sem nos: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    

    return 0;

}
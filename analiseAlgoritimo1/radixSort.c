#include <stdio.h>


int obterMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


void countingSort(int arr[], int n, int exp) {
    int saida[n];
    int count[10] = {0}; 

    // armazena a contagem das ocorrencias de cada digito
    for (int i = 0; i < n; i++) {
        int digito = (arr[i] / exp) % 10;
        count[digito]++;
    }

    // Altera count[i] para que ele contenha a posição real 
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constroi o array de saída (andando de tras para frente para manter a estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;
        saida[count[digito] - 1] = arr[i];
        count[digito]--;
    }

    // Copia o array de saída para arr[], para que arr[] contenha os números ordenados pelo dígito atual
    for (int i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
}


void radixSort(int arr[], int n) {
    // Encontra o maior numero para saber a quantidade de digitos
    int max = obterMax(arr, n);

    // Executa o Counting Sort para cada digito. 
    // exp é 1 para unidades, 10 para dezenas, 100 para centenas, etc
    for (int exp = 1; max / exp > 0; exp *= 10) { //exp: (20/1) ou (20/10)
        countingSort(arr, n, exp);
    }
}


void imprimirArray(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação:\n");
    imprimirArray(arr, tam);

    radixSort(arr, tam);

    printf("\nArray ordenado:\n");
    imprimirArray(arr, tam);

    return 0;
}
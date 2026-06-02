#include <stdio.h>

int tamanho = 10;

int pegar_maior(int arr[], int n) {
    int maior = arr[0];
    int i = 1;
    while (i < n) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
        i++;
    }
    return maior;
}

void contar_sort(int arr[], int n, int exp) {
    int saida[100];
    int contagem[10];
    int i;

    contagem[0] = 0;
    contagem[1] = 0;
    contagem[2] = 0;
    contagem[3] = 0;
    contagem[4] = 0;
    contagem[5] = 0;
    contagem[6] = 0;
    contagem[7] = 0;
    contagem[8] = 0;
    contagem[9] = 0;

    for (i = 0; i < n; i++) {
        int digito = (arr[i] / exp) % 10;
        contagem[digito] = contagem[digito] + 1;
    }

    i = 1;
    while (i <= 9) {
        contagem[i] = contagem[i] + contagem[i - 1];
        i++;
    }

    for (i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;
        saida[contagem[digito] - 1] = arr[i];
        contagem[digito] = contagem[digito] - 1;
    }

    for (i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
}

void radix_sort(int arr[], int n) {
    int maior = pegar_maior(arr, n);

    int exp = 1;
    while (maior / exp > 0) {
        contar_sort(arr, n, exp);
        exp = exp * 10;
    }
}

void imprimir(int arr[], int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int numeros[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    printf("Array antes: ");
    imprimir(numeros, n);

    radix_sort(numeros, n);

    printf("Array depois: ");
    imprimir(numeros, n);

    return 0;
}
#include <stdio.h>

// Protótipo necessário para o compilador conhecer a função antes de bucket
void bubble(int arr[], int tam);

void troca(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int arr[], int tam) {
    // Correção sutil no j=0 (algoritmos de ordenação começam do índice 0)
    for (int i = 0; i <= tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                troca(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bucket(int arr[], int tam) {
    // 1. Encontra o maior elemento de forma segura
    int maior = arr[0]; 
    for (int i = 1; i < tam; i++) { // Varre até o último elemento (i < tam)
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }

    // Define quantos baldes precisamos com base no maior número
    // Ex: se maior é 99, 99/10 = 9. Precisamos de 10 baldes (índices 0 a 9)
    int qtd_baldes = (maior / 10) + 1;

    // Criamos a matriz e o contador baseados na quantidade real necessária
    int matriz_buckets[qtd_baldes][tam];
    int balde_idx[qtd_baldes]; 
    
    // Inicializa o array de contadores com zero
    for (int i = 0; i < qtd_baldes; i++) {
        balde_idx[i] = 0;
    }

    // 2. Coloca nos baldes correspondentes
    for (int i = 0; i < tam; i++) {
        int balde = arr[i] / 10;
        matriz_buckets[balde][balde_idx[balde]] = arr[i];
        balde_idx[balde]++;
    }

    // 3. Ordena os números nos baldes
    // O limite aqui deve ser a quantidade de baldes criados, não o tamanho do vetor original
    for (int i = 0; i < qtd_baldes; i++) {
        if (balde_idx[i] > 1) {
            bubble(matriz_buckets[i], balde_idx[i]);    
        }
    }

    // 4. Recoloca os números dos baldes na ordem certa
    int indice_vazio = 0; // CORREÇÃO: Inicializado com zero
    for (int i = 0; i < qtd_baldes; i++) {
        for (int j = 0; j < balde_idx[i]; j++) {
            arr[indice_vazio] = matriz_buckets[i][j];
            indice_vazio++;
        }
    }
}

int main() {
    int arr[] = {4, 6, 10, 1, 8, 99, 1, 35, 2, 0, 10, 20};
    int tam = sizeof(arr) / sizeof(arr[0]);

    bucket(arr, tam);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
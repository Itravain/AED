#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int encontrar(int *vetor, int numero, int qtd_num, bool *vetor_visitado) {
    int inicio = 0, fim = qtd_num - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == numero && !vetor_visitado[meio]) {
            return meio;  // Retorna o índice em vez do número
        } else if (numero > vetor[meio]) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;  // Retorna -1 se não for encontrado
}

void troca(int vetor[], int i, int j) {
    int aux;
    aux = vetor[j];
    vetor[j] = vetor[i];
    vetor[i] = aux;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivot = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivot) {
            i++;
            troca(vetor, i, j);
        }
    }
    troca(vetor, fim, i + 1);
    return i + 1;
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int q = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, q - 1);
        quickSort(vetor, q + 1, fim);
    }
}

int main() {
    int qtd_num, res_soma, qtd_pares = 0;
    scanf("%d %d", &qtd_num, &res_soma);

    bool *vetor_visitado = calloc(qtd_num, sizeof(bool));
    int vetor[qtd_num];

    for (int i = 0; i < qtd_num; i++) {
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, qtd_num - 1);

    for (int i = 0; i < qtd_num; i++) {
        if (!vetor_visitado[i]) {
            int chave = res_soma - vetor[i];
            vetor_visitado[i] = 1;
            int indice = encontrar(vetor, chave, qtd_num, vetor_visitado);
            if (indice != -1) {
                qtd_pares++;
                vetor_visitado[i] = true;
                vetor_visitado[indice] = true;
                //printf("%d + %d\n", vetor[i], chave);
            }
        }
    }
    printf("%d\n", qtd_pares);

    free(vetor_visitado);

    return 0;
}

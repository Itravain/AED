#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int a, int b){
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

void selectionSort(int *vetor, int tam){
	for(int i = tam - 1; i > 0; i--){
        int maior = 0;
		for(int j = 1; j <= i; j++){
			if(vetor[j] > vetor[maior]){
				maior = j;
			}
		}
		troca(vetor, maior, i);
	}
}

int main(void){
    const int TAM = 20;
    int vetor[TAM];

    //preencher vetor com numeros aleatorios
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % 100;
    }
    //imprimir vetor desordenado
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    //ordenar vetor
    selectionSort(vetor, TAM);

    //imprimir vetor ordenado
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");


    return 0;
}
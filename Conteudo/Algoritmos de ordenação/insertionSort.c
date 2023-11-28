#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int a, int b){
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

void insertionSort(int *vetor, int tam){
	int j;
	for(int i = 1; i < tam; i++){
		j = i;
		while(vetor[j] < vetor[j-1]){
			troca(vetor, j, j-1);
			if(j > 1){
                j--;    
            }
		}
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
    insertionSort(vetor, TAM);

    //imprimir vetor ordenado
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");


    return 0;
}
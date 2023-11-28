#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int *vetor, int primeiro, int meio, int ultimo){
    int i, j;

	//definir o tamanho dos vetores a serem montados
	int tamV1 = meio - primeiro + 1;
	int tamV2 = ultimo - meio;

	//cria os vetores
	int V1[tamV1 + 1], V2[tamV2 + 1];

	//copia os vetores
	for(i = primeiro; i <= meio; i++){
		V1[i - primeiro] = vetor[i];
	}
	V1[tamV1] = 100000000;
	for(j = meio + 1; j <= ultimo; j++){
		V2[j - meio - 1] = vetor[j];
	}
	V2[tamV2] = 100000000;

	//ordenar as partes no vetor original
	i = 0;
	j = 0;
	for(int k = primeiro; k <= ultimo; k++){
		if(V1[i] < V2[j]){
			vetor[k] = V1[i];
			i++;
		}
		else{
			vetor[k] = V2[j];
			j++;
		}
	}	
}

void mergeSort(int *vetor, int primeiro, int ultimo){
    if(primeiro < ultimo){
        int meio = (primeiro+ultimo)/2;
        mergeSort(vetor, primeiro, meio);
        mergeSort(vetor, meio + 1, ultimo);
        merge(vetor, primeiro, meio, ultimo);
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
    mergeSort(vetor, 0, TAM - 1);

    //imprimir vetor ordenado
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");


    return 0;
}
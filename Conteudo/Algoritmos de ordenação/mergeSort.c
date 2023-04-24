<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge(int *V, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio +1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i = 0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(V[p1] < V[p2]){
					temp[i]= V[p1++];
				}
				else{
					temp[i] = V[p2++];
				}
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1)
					temp[i]= V[p1++];
				else
					temp[i]= V[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			V[k]=temp[j];
		}
	}
	free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if (inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
}


int main(void){
	int num[6] = {12, 2, 45, 4, 2, 9}, size = 6;
	int i;
	for ( i = 0; i < size; i++){
		printf("%d\n", num[i]);
	}
	mergeSort(num, 0, size-1);
	for ( i = 0; i < size; i++){
	printf("%d\n", num[i]);
	}



    return 0;
}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if (inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
}

void merge(int *V, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim 2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio +1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i = 0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(V[p1] < V[p2]){
					temp[i]= V[p1++];
				}
				else{
					temp[i] = V[p2++];
				}
				if(p1>meio) fim1=1;
				if(p2>meio) fim2=2;
			}
		}
	}
			else{
				if(!fim1)
					temp[i]= V[p1++];
				else
					temp[i]= V[p2++];
			}



int main(void){





    return 0;
}
>>>>>>> 9ef932380309f16928e2e8e276878a1d739946a8

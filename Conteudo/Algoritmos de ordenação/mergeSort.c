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



    
}


int main(void){





    return 0;
}
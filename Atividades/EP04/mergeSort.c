#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge(char **V, int inicio, int meio, int fim){
	char **temp;
	int p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio +1;
	temp = (char **) malloc(tamanho*sizeof(char *));
	if(temp != NULL){
		for(i = 0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(strcmp(V[p1], V[p2]) < 0){
					temp[i] = V[p1++];
				}
				else{
					temp[i] = V[p2++];
				}
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1)
					temp[i] = V[p1++];
				else
					temp[i] = V[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			V[k] = temp[j];
		}
	}
	free(temp);
}

void mergeSort(char **V, int inicio, int fim){
    int meio;
    if (inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
}


int main (void){
    int qt, pos, i;
    char **nomes;
    

    //leitura da quantidade de nomes inseridos e a posição desejada
    scanf("%d %d", &qt, &pos);
    getchar();

    nomes = (char **) malloc(qt*sizeof(char *));
    for ( i = 0; i < qt; i++)
    {
        //leitura dos nomes
        nomes[i] = (char *) malloc(50*sizeof(char));
        fgets(nomes[i], 50 ,stdin);
    }

    //organizar a lista de nomes
    mergeSort(nomes, 0, qt-1);

    printf("%s", nomes[pos-1]);

    for ( i = 0; i < qt; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

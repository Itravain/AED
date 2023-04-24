#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge(char **Words, int inicio, int meio, int fim){
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
				if(strcmp(Words[p1], Words[p2]) < 0){
					temp[i] = Words[p1++];
				}
				else{
					temp[i] = Words[p2++];
				}
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1)
					temp[i] = Words[p1++];
				else
					temp[i] = Words[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			Words[k] = temp[j];
		}
	}
	free(temp);
}

void mergeSort(char **Words, int inicio, int fim){
    int meio;
    if (inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(Words, inicio, meio);
        mergeSort(Words, meio+1, fim);
        merge(Words, inicio, meio, fim);
    }
}


int main (void){
    int qt, pos, i;
    char **nomes;
    

    //leitura da quantidade de nomes inseridos e a posição desejada
    scanf("%d %d", &qt, &pos);
    getchar();

    nomes = (char **) malloc(qt*sizeof(char *));
    for (i = 0; i < qt; i++)
    {
        //leitura dos nomes
        nomes[i] = (char *) malloc(50*sizeof(char));
        fgets(nomes[i], 50 ,stdin);
    }

    //organizar a lista de nomes
    mergeSort(nomes, 0, qt-1);

    printf("%s", nomes[pos-1]);

    for (i = 0; i < qt; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

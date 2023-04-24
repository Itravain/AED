#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge(char **Words, int inicio, int meio, int fim){
    //ponteiro para armazenar o ponteiro temporário
	char **temp;
	int p1, p2, tamanho, i, j, k;
    //variáveis para determinar o se os vetores parciais chegaram ao fim
	int fim1 = 0, fim2 = 0;
    //determina o tamanho do vetor que precisará ser alocado
	tamanho = fim-inicio+1;
    //p1 e p2 são usados para percorrer os menores vetores
	p1 = inicio;
	p2 = meio +1;
    //alocamento de memória para o vetor que vai armazenar os valores temporariamente
	temp = (char **) malloc(tamanho*sizeof(char *));
	
    //se o alocamento de memória tiver sido realizado com sucesso
    if(temp != NULL){
        //percorre o vetor 
		for(i = 0; i<tamanho; i++){ 
            //se nenhum dos vetores parciais tiverem chegado ao fim   
			if(!fim1 && !fim2){
                //se o vetor 1 for menor que o vetor 2
				if(strcmp(Words[p1], Words[p2]) < 0){
                    //copia o valor de p1 para o vetor temporário e avança uma posição
					temp[i] = Words[p1++];
				}
				else{
					temp[i] = Words[p2++];
				}
                //Testa se os vetores parciais chegaram ao fim e atribui o valor de 1 se tiverem
				if(p1>meio){
                    fim1=1;
                }
				if(p2>fim){
                    fim2=1;
                } 
            }
            //Caso algum dos vetores parciais tiverem chegado ao fim o reto do outro vetor é copiado no vetor temporário    
            else{
				if(!fim1)
					temp[i] = Words[p1++];
				else
					temp[i] = Words[p2++];
			}
		}
        //retorna os valores ordenados ao vetor words, da função main
		for(j=0, k=inicio; j<tamanho; j++, k++){
			Words[k] = temp[j];
		}
	}
	free(temp);
}

void mergeSort(char **Words, int inicio, int fim){
    int meio;
    //função recursiva para dividir o vetor até chegar em sua menor parte
    if (inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(Words, inicio, meio);
        mergeSort(Words, meio+1, fim);

        //A partir deste momento o vetor passa a ser montado novamente, de maneira ordenada
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

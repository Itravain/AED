#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void criar_vetor(int **num, int tam){
    srand(time(NULL));
    int i;

    *num = malloc(tam * sizeof(int));
    if(*num){
        for ( i = 0; i < tam; i++){
            (*num)[i] = rand()%100 +1;
        }
    }
    else{
        printf("Erro ao alocar memória.");
    }    
}

void copiar_vetor(int **original, int **copia, int tam){
    int i;
    *copia = malloc(tam * sizeof(int));
    if (*copia){
        for (i = 0; i < tam; i++){
            (*copia)[i] = (*original)[i];
        }
    }
    else{
        printf("Não foi possível alocar memória.\n");
    }
}

void imprimir_vetor(int num[], int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void insertionSort(int num[], int tam){
    int aux, i = 1, j = 1;
    for (i = 1; i < tam; i++, j = i){
        while(j > 0){
            if(num[j] < num[j-1]){
                //troca adjacentes
                aux = num[j], num[j] = num[j-1], num[j-1] = aux;
            }
            j--;
        }
    }
}

void selectionSort(int num[], int tam){
    int i, j, aux, min;
    for (i = 0; i < tam-1; i++){
        min = i;
        for (j = i+1; j < tam; j++){
            if (num[j] < num[min]){
                min = j;
            }    
        }
        aux = num[i], num[i] = num[min], num[min] = aux;
    }
}

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





int main(){
    int *original = NULL, tam, seletor = -1;
    double tempo = 0.0;    
    clock_t begin, end;

    printf("---------------------------------------------\n");
    printf("Quantos números você deseja adicionar a lista? ");
    scanf("%d", &tam);
    criar_vetor(&original, tam);

    //imprimir_vetor(original, tam);

    printf("---------------------------------------------\n");
    printf("Selecione o algoritmo para medir o tempo de execução\n0-Sair\n1-InsertSort\n2-SelectionSort\n3-mergeSort\n");
    printf("---------------------------------------------\n");

    while (seletor != 0){
        scanf("%d", &seletor);
        switch (seletor){
        case 1:
            tempo = 0.0; 
            int *cop_insertion = NULL;
            copiar_vetor(&original, &cop_insertion, tam);

            begin = clock();
            insertionSort(cop_insertion, tam);
            end = clock();

            tempo += (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo de execução insertionSort: %f s\n", tempo);

            break;
        case 2:
            tempo = 0.0; 
            int *cop_selection = NULL;
            copiar_vetor(&original, &cop_selection, tam);

            begin = clock();
            selectionSort(cop_selection, tam);
            end = clock();

            tempo += (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo de execução selectionSort: %f s\n", tempo);
           
            break;
        case 3:
            tempo = 0.0; 
            int *cop_merge = NULL;
            copiar_vetor(&original, &cop_merge, tam);
            
            begin = clock();
            mergeSort(cop_merge, 0, tam);
            end = clock();

            tempo += (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo de execução mergeSort: %f s\n", tempo);
        
            break;
        default:
            break;
        }
    }
    
    return 0;
}
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

void Intercala (int v[], int inicio, int meio, int fim){
    int i, j, k, *w;
    w = malloc ((fim-inicio) * sizeof(int));
    i = inicio; j = meio; k = 0;
    while (i < meio && j < fim){
        if (v[j] >= v[i]){
            w[k] = v[i];
            k++;
            i++;
        }
        else{ 
            w[k] = v[j];
            k++;
            j++;
        }
    }
    while (i < meio){
        w[k] = v[i];
        k++;
        i++;
    }
    while (j < fim){
        w[k] = v[j];
        k++;
        j++;
    }
    for (i = inicio; i < fim; i++){
        v[i] = w[i-inicio];
    }       
    free (w); 
}

void mergeSort(int v[], int inicio, int fim){
    int meio;
    if (fim>inicio){
        meio = floor((inicio+fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        Intercala(v, inicio, meio, fim);
    }
}

void Insere_Heap(int num[], int novo){
    int f, aux;
    f = novo + 1;
    while (num[f/2] < num[f] && f > 1) {
        aux = num[f/2]; 
        num[f/2] = num[f]; 
        num[f] = aux;
        f = f/2;       
    }
}


void heapify(int num[], int tam){
    int aux, f = 2;
    while (tam >= f){
        if (num[f] < num[f+1] && f < tam){
            f++;
        }
        if (num[f/2] >= num[f]){
            break;
        }
        aux = num[f/2]; 
        num[f/2] = num[f]; 
        num[f] = aux;
        f *= 2;
    }
}

void Heapsort (int num[], int tam){
    int x;
    for (x = 1; x < tam; x++)
        Insere_Heap (num, x);
    for (x = tam; x > 1; x--){
        //troca de posições
        int t = num[1]; 
        num[1] = num[x]; 
        num[x] = t;
        heapify(num, x-1);
    }
}

int particionar (int num[], int inicio, int fim){
    int c, aux, k, j;
    j = inicio;
    c = num[fim];
    for (k = inicio; fim > k; k++){
        if (c >= num[k]){
            aux = num[j];
            num[j] = num[k];
            num[k] = aux;
            j++;
        }
    }
    num[fim] = num[j];
    num[j] = c;

    return j;
}


void Quicksort (int num[], int inicio, int fim){
    int pivo;
    if (inicio < fim){
        pivo = particionar (num, inicio, fim);
        Quicksort (num, inicio, pivo - 1);
        Quicksort (num, pivo + 1, fim);
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
    printf("Selecione o algoritmo para medir o tempo de execução\n0-Sair\n1-InsertSort\n2-SelectionSort\n3-mergeSort\n4-heapSort\n5-quickSort\n");
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

        case 4:
            tempo = 0.0; 
            int *cop_heap = NULL;
            copiar_vetor(&original, &cop_heap, tam);
            
            begin = clock();
            Heapsort(cop_heap, tam);
            end = clock();

            tempo += (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo de execução heapSort: %f s\n", tempo);
        
            break;

        case 5:
            tempo = 0.0; 
            int *cop_quick = NULL;
            copiar_vetor(&original, &cop_quick, tam);
            
            begin = clock();
            Quicksort(cop_quick, 0, tam);
            end = clock();

            tempo += (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo de execução quickSort: %f s\n", tempo);
        
            break;
        default:
            break;
        }
    }
    
    return 0;
}
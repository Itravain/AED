#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codon[4];
    char proteina;
} Codon;

void troca(Codon *vetor, int a, int b)
{
    Codon aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

void insertion(Codon *vetor, int tamanho){
    for (int i = 1; i < tamanho; i++)
    {
        int j = i;
        while (j > 0 && strcmp(vetor[j].codon, vetor[j-1].codon) < 0)
        {
            troca(vetor, j, j-1);
            j--;
        }        
    }
}

char busca_binaria(Codon *vetor, char codon[4], int inicio, int fim)
{
    if(inicio <= fim){
        int meio = (inicio + fim)/2;
        if (strcmp(vetor[meio].codon, codon) == 0)
        {
            return vetor[meio].proteina;
        }
        else if(strcmp(vetor[meio].codon, codon) > 0)
        {
            return busca_binaria(vetor, codon, inicio, meio-1);
        }
        else
        {
            return busca_binaria(vetor, codon, meio+1, fim);
        }
    }
    return '*';
}

int main()
{
    int qtd_entradas, qtd_dna;

    scanf("%d", &qtd_entradas);
    getchar();

    Codon *lista = malloc(qtd_entradas * sizeof(Codon));

    for (int i = 0; i < qtd_entradas; i++)
    {
        fgets(lista[i].codon, 4, stdin);
        getchar(); 
        scanf("%c", &lista[i].proteina);
        getchar();
    }

    insertion(lista, qtd_entradas);

    scanf("%d", &qtd_dna);
    getchar();
    
    char aux[4];

    for (int i = 0; i < qtd_dna; i++)
    {
        do
        {
            aux[0] = getchar();
            aux[1] = getchar();
            aux[2] = getchar();
            aux[3] = '\0';
            printf("%c", (lista, aux, 0, qtd_entradas));
        } while (aux[0] != ' ');
        printf("\n");
    }

    return 0;
}

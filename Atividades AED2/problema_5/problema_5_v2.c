#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int converter(char codon[4]){
    int conversao = 0;
    for (int i = 0; i < 3; i++)
    {
        conversao += (codon[i] - 65) * pow(26, i);
    }
    return conversao;
}

typedef struct lista{
    char proteina;
    char codon[4];
    struct lista *proximo;
}Lista;

Lista *criar_no(char proteina, char codon[4]){
    Lista *novo = malloc(sizeof(Lista));
    strcpy(novo->codon, codon);
    novo->proteina = proteina;
    return novo;
}

void inserir_Lista(Lista *lista, char proteina, char codon[4]){
    if (lista->proximo == NULL)
    {
        lista->proximo = criar_no(proteina, codon);
    }
    else{
        Lista *aux = lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = criar_no(proteina, codon);
    }
}

Lista *criar_hash(int qtd_hash){
    Lista *hash = malloc(sizeof(Lista) * qtd_hash);
    for (int i = 0; i < qtd_hash; i++)
    {
        hash[i].proximo = NULL;
    }
    return hash;
}

void inserir_hash(char codon[4], Lista *hash, char proteina, int tam_hash){
    int posicao = converter(codon) % tam_hash;
    inserir_Lista(&hash[posicao], proteina, codon);
}

char busca_hash(Lista *hash, char codon[4], int tam_hash){
    int posicao = converter(codon) % tam_hash;
    Lista *aux = hash[posicao].proximo;
    while (aux != NULL)
    {
        if (strcmp(aux->codon, codon) == 0)
        {
            return aux->proteina;
        }
        aux = aux->proximo;
    }
    return '*';
}

int main()
{
    int qtd_entradas, qtd_dna;
    char codon[4];
    char proteina;

    scanf("%d", &qtd_entradas);
    getchar();

    Lista *hash = criar_hash(qtd_entradas + 1);

    for (int i = 0; i < qtd_entradas; i++)
    {
        fgets(codon, 4, stdin);
        getchar(); 
        scanf("%c", &proteina);
        getchar();
        inserir_hash(codon, hash, proteina, qtd_entradas + 1);
    }


    scanf("%d", &qtd_dna);
    getchar();
    
    char aux[4];
    char *dna = malloc(10000001 * sizeof(char));
    int contador = 0;

    for (int i = 0; i < qtd_dna; i++)
    {
        scanf("%s", dna); 
        contador = 0;
        while (contador < strlen(dna))
        {
            strncpy(aux, &dna[contador], 3);
            aux[3] = '\0';
            printf("%c", busca_hash(hash, aux, qtd_entradas + 1));
            contador += 3;
        }
        printf("\n");
    }

    free(dna);

    return 0;
}
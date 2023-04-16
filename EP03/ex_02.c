#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char nome[20];
    struct no *proximo;
}No;

void inserir_meio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Não foi possível alocar a memória")
    }
}
void inserir_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if (novo){
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->proximo){
                aux = aux->proximo 
            }
            aux->proximo = novo;
        }
    }
    else
    {
        printf("Não foi possível alocar a memória")
    }
}


int main(){

    return 0;
}
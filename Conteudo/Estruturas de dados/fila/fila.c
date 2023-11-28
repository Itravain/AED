#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no{
    int numero;
    struct no *proximo;
    struct no *anterior;
}No;

typedef struct fila{
    int qt_elementos;
    No *comeco;
    No *fim;
    
}Fila;

Fila *criarFila(Fila *novaFila){
    novaFila = malloc(sizeof(Fila));
    novaFila->qt_elementos = 0;
    novaFila->comeco = NULL;
    novaFila->fim = NULL;

    return novaFila;
}

void inserirFila(Fila *fila, int numero){
    No *novoNo = malloc(sizeof(No));
    novoNo->numero = numero;
    novoNo->proximo = NULL;
    novoNo->anterior = fila->fim;

    if(fila->qt_elementos == 0)
    {
        fila->comeco = novoNo;
        fila->fim = novoNo;
        fila->qt_elementos++;
        return;
    }
    fila->fim->proximo = novoNo;
    fila->fim = novoNo;
    fila->qt_elementos++;
}

void removerFila(Fila *fila){
    fila->comeco = fila->comeco->proximo;
    free(fila->comeco->anterior);
    fila->comeco->anterior = NULL;
}

void imprimirFila(Fila *fila){
    No *aux = fila->fim;
    while(aux != NULL)
    {
        printf("%d->", aux->numero);
        aux = aux->anterior;
    }
    printf("NULL\n");
}
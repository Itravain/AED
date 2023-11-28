#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no{
   int numero;
   struct no *proximo;
   struct no *anterior;
}No;

typedef struct lista{
    int qt_elementos;
    No *inicio;
    No *fim;
}Lista;

Lista *criarLista(Lista* lista){
    lista = malloc(sizeof(Lista));
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->qt_elementos = 0;

    return lista;
}

void inserirInicioLista(Lista *lista, int numero){
    No *novoNo = malloc(sizeof(No));
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    novoNo->numero = numero;

    if(lista->qt_elementos == 0){
        lista->fim = novoNo;
        lista->inicio = novoNo;
    }
    else{
        lista->inicio->anterior = novoNo;
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    }
    lista->qt_elementos++;
}

void inserirFimLista(Lista *lista, int numero){
    No *novoNo = malloc(sizeof(No));
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    novoNo->numero = numero;

    if(lista->qt_elementos == 0){
        lista->fim = novoNo;
        lista->inicio = novoNo;
    }
    else{
        lista->fim->proximo = novoNo;
        novoNo->anterior = lista->fim;
        lista->fim = novoNo;
    }
    lista->qt_elementos++;
}

int buscarLista(Lista *lista, int numero){
    No *aux = lista->inicio;

    while(aux != NULL){
        if(aux->numero == numero) return 1;
        aux = aux->proximo;
    }
    return 0;
}

void removerLista(Lista *lista, int numero){
    

    if(lista->qt_elementos == 0)
    {
        printf("A lista esta vazia\n");
    }
    else if(lista->qt_elementos == 1 && lista->fim->numero == numero)
    {
        free(lista->fim);
        lista->fim = NULL;
        lista->inicio = NULL;
        lista->qt_elementos--;
    }
    else if(lista->fim->numero > 1){
        if (lista->fim->numero == numero)
        {
            lista->fim = lista->fim->anterior;
            free(lista->fim->proximo);
            lista->fim->proximo = NULL;
            lista->qt_elementos--;
        }
        else if (lista->inicio->numero == numero)
        {
            lista->inicio = lista->inicio->proximo;
            free(lista->inicio->anterior);
            lista->fim->anterior = NULL;
            lista->qt_elementos--;
        }
        else {
            No *aux = lista->inicio->proximo;
            while(aux != lista->fim && aux->numero != numero){
                aux = aux->proximo;
            }
            if (aux->numero == numero)
            {
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
                lista->qt_elementos--;            
                free(aux);
            }
            /*else{
                printf("Número não encontrado.\n");
            }*/
            
            
        }
    }
}

void imprimirLista(Lista *lista){
    No *aux = lista->inicio;

    printf("inicio -> ");

    while (aux != NULL)
    {
        printf("%d -> ", aux->numero);
        aux = aux->proximo;
    }
    printf("fim\n");
}
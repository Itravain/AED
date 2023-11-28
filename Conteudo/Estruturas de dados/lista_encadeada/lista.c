#include <stdio.h>
#include <stdlib.h>

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
    
}

void imprimirLista(Lista *lista){
    No *aux = lista->inicio;

    printf("inicio -> ");

    while (aux != NULL)
    {
        printf("%d -> ", aux->numero);
        aux = aux->proximo;
    }
    printf("fim");
}
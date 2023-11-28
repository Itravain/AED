#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct no{
    int numero;
    struct no *proximo;
}No;

typedef struct pilha{
    int qtdElementos;
    No *topo;
}Pilha;

Pilha *criarPilha(){
    Pilha *novaPilha = malloc(sizeof(Pilha));
    novaPilha->qtdElementos = 0;
    novaPilha->topo = NULL;
    return novaPilha;
}

void empilhar(Pilha *pilha, int numero){
    No *novoNo = malloc(sizeof(No));
    novoNo->numero = numero;
    novoNo->proximo = pilha->topo;

    pilha->topo = novoNo;

    pilha->qtdElementos++;
}

int desempilhar(Pilha *pilha){
    if(pilha->topo == NULL){
        printf("A pilha está vazia\n");
    }
    else{
        No *aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
        pilha->qtdElementos--;
    }
}

void imprimirPilha(Pilha *pilha){
    if(pilha->qtdElementos == 0){
        printf("A pilha está vazia\n");
    }
    else{
        printf("topo -> ");
        No *aux = pilha->topo;
        while(aux != NULL){
            printf("%d -> ", aux->numero);
            aux = aux->proximo;
        }
        printf("fim\n");
    }    
}
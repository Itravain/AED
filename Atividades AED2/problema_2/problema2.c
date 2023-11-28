#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    int indice;
    struct no *esq;
    struct no *dir;
} No;

No *inserir(No *raiz, int num_adicionar, int indice) {
    // cria um novo nó
    No *novo = malloc(sizeof(No));
    novo->indice = indice;
    novo->numero = num_adicionar;
    novo->esq = NULL;
    novo->dir = NULL;

    // código para inserir
    No *aux1 = raiz;
    No *aux2 = NULL;

    while (aux1 != NULL) {
        aux2 = aux1;
        if (novo->numero > aux1->numero) {
            aux1 = aux1->dir;
        } else {
            aux1 = aux1->esq;
        }
    }
    if (aux2 == NULL) {
        raiz = novo;
    } else if (num_adicionar > aux2->numero) {
        aux2->dir = novo;
    } else {
        aux2->esq = novo;
    }
    return raiz;
}

No *remove_maior(No *raiz) {
    if (raiz) {
        No *aux = raiz;
        No *pai = NULL;
        while (aux->dir != NULL) {
            pai = aux;
            aux = aux->dir;
        }
        if (pai != NULL) {
            pai->dir = aux->esq;
        } else {
            raiz = aux->esq;
        }
        printf("%d\n", aux->indice);
        free(aux);
    } else {
        printf("0\n");
    }
    return raiz;
}

int main() {
    char op = 'a';
    int valor, indice = 1;
    No *raiz = NULL;

    do {
        scanf(" %c", &op);
        if (op == 'c') {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor, indice);
            indice++;
        } else if (op == 'v') {
            raiz = remove_maior(raiz);
        }
    } while (op != 'f');

    return 0;
}

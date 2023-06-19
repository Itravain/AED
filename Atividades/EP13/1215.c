#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no {
    char palavra[201];
    struct no *prox;
} No;

int busca(No *lista, char *palavra) {
    No *aux = lista;
    while (aux != NULL) {
        if (strcmp(aux->palavra, palavra) == 0) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

No *insert(No *lista, char *palavra) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return lista;
    }
    strcpy(novo->palavra, palavra);
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    } else {
        No *aux = lista;
        No *ant = NULL;
        while (aux != NULL && strcmp(aux->palavra, palavra) < 0) {
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL) {
            novo->prox = lista;
            return novo;
        } else {
            ant->prox = novo;
            novo->prox = aux;
            return lista;
        }
    }
}

void imprime_lista(No *lista) {
    No *aux = lista;
    while (aux != NULL) {
        printf("%s\n", aux->palavra);
        aux = aux->prox;
    }
}

char corrige_letra(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return letra + 32;
    }
    return letra;
}

int main() {
    char linha[201];
    No *lista = NULL;

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        int i, len = strlen(linha);
        char palavra[201];
        int index = 0;

        for (i = 0; i < len; i++) {
            char letra = linha[i];
            if (isalpha(letra)) {
                palavra[index++] = corrige_letra(letra);
            } else if (index > 0) {
                palavra[index] = '\0';

                if (busca(lista, palavra) == 0) {
                    lista = insert(lista, palavra);
                }

                index = 0;
            }
        }
    }

    imprime_lista(lista);

    return 0;
}

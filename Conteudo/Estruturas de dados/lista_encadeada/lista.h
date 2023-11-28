#ifndef LISTA_H
#define LISTA_H

typedef struct no No;

typedef struct lista Lista;

Lista *criarLista();

void inserirInicioLista(Lista *lista, int numero);

void inserirFimLista(Lista *lista, int numero);

int buscarLista(Lista *lista, int numero);

void removerLista(Lista *lista, int numero);

void imprimirLista(Lista *lista);

#endif
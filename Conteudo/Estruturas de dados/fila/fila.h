#ifndef LISTA_H
#define FILA_H

typedef struct no No;

typedef struct fila Fila;

Fila *criarFila();

void inserirFila(Fila *fila, int numero);

void removerFila(Fila *fila);

void imprimirFila(Fila *fila);

#endif
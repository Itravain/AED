#ifndef PILHA_H
#define PILHA_H

typedef struct no No;
typedef struct pilha Pilha;

Pilha *criarPilha();

void empilhar(Pilha *pilha, int numero);

int desempilhar(Pilha *pilha);

void imprimirPilha(Pilha *pilha);

#endif
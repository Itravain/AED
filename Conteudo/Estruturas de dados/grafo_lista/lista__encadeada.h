#ifndef __LISTA_H
#define __LISTA_H


typedef struct no No;


void inserir_no_inicio(No **lista, int num);


void inserir_no_meio(No **lista, int num, int ant);


void inserir_no_inicio(No **lista, int num);


void inserir_no_fim(No **lista, int num);


void inserir_no_meio(No **lista, int num, int ant);


void inserir_ordenado(No **lista, int num);


No* remover(No **lista, int num);


No* buscar(No **lista, int num);


void copiar_lista(No **l, No **C);


void imprimir(No *no);


#endif
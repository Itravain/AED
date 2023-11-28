#ifndef __GRAFO_H
#define __GRAFO_H


typedef struct grafo grafo_t;


grafo_t *init_grafos(int vertices);


void criar_aresta(grafo_t *Grafo, int inicial, int final, int peso);


void remover_aresta(grafo_t *Grafo, int inicial, int final);


void imprimir_grafo(grafo_t *Grafo);
    

int *dijkstra(grafo_t *grafo, int vertice);


#endif
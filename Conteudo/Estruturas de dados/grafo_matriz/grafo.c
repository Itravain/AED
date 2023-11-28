#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct grafo{
    int qtd_vertices;
    int qtd_arestas;
    int **matriz;
} grafo_t;


int **criar_matriz(int linhas, int colunas){
    int i, j;
    
    int **matriz = malloc(sizeof(int*)*linhas);
    for (i = 0; i < linhas; i++){
        matriz[i] = calloc(colunas, sizeof(int));
    }
    return matriz;
}


grafo_t *init_grafos(int vertices){
    grafo_t *grafo = malloc(sizeof(grafo_t));
    grafo->qtd_arestas = 0;
    grafo->qtd_vertices = vertices;
    grafo->matriz = criar_matriz(vertices, vertices);
    return grafo;
}


void criar_aresta(grafo_t *grafo, int inicial, int final, int peso){
    if (grafo->matriz[inicial][final] == 0){
        grafo->matriz[inicial][final] = peso;
        grafo->qtd_arestas++;
    }
}


void remover_aresta(grafo_t *grafo, int inicial, int final){
    if (grafo->matriz[inicial][final] != 0){
        grafo->matriz[inicial][final] = 0;
        grafo->qtd_arestas--;
    }
}


void imprimir_grafo(grafo_t *grafo){
    for (int i = 0; i < grafo->qtd_vertices; i++){
        printf("%d:  ", i);
        for (int j = 0; j < grafo->qtd_vertices; j++){
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
    
}


void liberar_grafo(grafo_t *grafo){
    for (int i = 0; i < grafo->qtd_vertices; i++){
        free(grafo->matriz[i]);
    }
    free(grafo->matriz);
    free(grafo);
}


//funcao de busca em profundidade
void busca_profundidade(grafo_t *grafo, int vertice, int *visitado){
    visitado[vertice] = 1;
    printf("%d ", vertice);
    for (int i = 0; i < grafo->qtd_vertices; i++){
        if (grafo->matriz[vertice][i] != 0 && !visitado[i]){
            busca_profundidade(grafo, i, visitado);
        }
    }
}


//funcao de busca em largura
void busca_largura(grafo_t *grafo, int vertice, int *visitado){
    int fila[grafo->qtd_vertices];
    int inicio = 0;
    int fim = 0;
    
    visitado[vertice] = 1;
    fila[fim++] = vertice;
    
    while (inicio != fim){
        vertice = fila[inicio++];
        printf("%d ", vertice);
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (grafo->matriz[vertice][i] != 0 && !visitado[i]){
                visitado[i] = 1;
                fila[fim++] = i;
            }
        }
    }
}

//dijkstra algorithm returning distances from a given vertex
int *dijkstra(grafo_t *grafo, int vertice){
    //distancia[i] = distancia do vertice inicial ate o vertice i
    int *distancia = malloc(sizeof(int)*grafo->qtd_vertices);
    //visitado[i] = 1 se o vertice i ja foi visitado
    int *visitado = calloc(grafo->qtd_vertices, sizeof(int));
    //minimo = menor distancia encontrada
    int minimo, proximo;
    
    //inicializa o vetor de distancias com um valor muito alto
    for (int i = 0; i < grafo->qtd_vertices; i++){
        distancia[i] = 999999;
    }
    //a distancia do vertice inicial ate ele mesmo eh 0
    distancia[vertice] = 0;
    //enquanto houver vertices nao visitados
    while (1){
        //encontra o vertice nao visitado com a menor distancia
        minimo = 999999;
        //proximo = vertice nao visitado com a menor distancia
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (distancia[i] < minimo && !visitado[i]){
                minimo = distancia[i];
                proximo = i;
            }
        }
        //se nao houver mais vertices nao visitados, para o loop      
        if (minimo == 999999){
            break;
        }
        //marca o vertice como visitado
        visitado[proximo] = 1;
        
        //atualiza a distancia dos vertices adjacentes ao vertice visitado
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (grafo->matriz[proximo][i] != 0){
                if (distancia[i] > distancia[proximo] + grafo->matriz[proximo][i]){
                    distancia[i] = distancia[proximo] + grafo->matriz[proximo][i];
                }
            }
        }
    }
    
    free(visitado);
    return distancia;
}

//algoritmo de kruskal
void kruskal(grafo_t *grafo){
    int *pai = malloc(sizeof(int)*grafo->qtd_vertices);
    int *peso = malloc(sizeof(int)*grafo->qtd_vertices);
    int *visitado = calloc(grafo->qtd_vertices, sizeof(int));
    int minimo, proximo;
    
    //inicializa os vetores
    for (int i = 0; i < grafo->qtd_vertices; i++){
        pai[i] = i;
        peso[i] = 999999;
    }
    
    //enquanto houver vertices nao visitados
    while (1){
        //encontra o vertice nao visitado com a menor distancia
        minimo = 999999;
        //proximo = vertice nao visitado com a menor distancia
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (peso[i] < minimo && !visitado[i]){
                minimo = peso[i];
                proximo = i;
            }
        }
        //se nao houver mais vertices nao visitados, para o loop      
        if (minimo == 999999){
            break;
        }
        //marca o vertice como visitado
        visitado[proximo] = 1;
        
        //atualiza o peso dos vertices adjacentes ao vertice visitado
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (grafo->matriz[proximo][i] != 0){
                if (peso[i] > grafo->matriz[proximo][i] && !visitado[i]){
                    peso[i] = grafo->matriz[proximo][i];
                    pai[i] = proximo;
                }
            }
        }
    }
    
    //imprime as arestas da arvore geradora minima
    for (int i = 0; i < grafo->qtd_vertices; i++){
        if (pai[i] != i){
            printf("%d - %d\n", pai[i], i);
        }
    }
    
    free(pai);
    free(peso);
    free(visitado);
}

//prim algorithm returning distances from a given vertex
int *prim(grafo_t *grafo, int vertice){
    //distancia[i] = distancia do vertice inicial ate o vertice i
    int *distancia = malloc(sizeof(int)*grafo->qtd_vertices);
    //visitado[i] = 1 se o vertice i ja foi visitado
    int *visitado = calloc(grafo->qtd_vertices, sizeof(int));
    //minimo = menor distancia encontrada
    int minimo, proximo;
    
    //inicializa o vetor de distancias com um valor muito alto
    for (int i = 0; i < grafo->qtd_vertices; i++){
        distancia[i] = 999999;
    }
    //a distancia do vertice inicial ate ele mesmo eh 0
    distancia[vertice] = 0;
    //enquanto houver vertices nao visitados
    while (1){
        //encontra o vertice nao visitado com a menor distancia
        minimo = 999999;
        //proximo = vertice nao visitado com a menor distancia
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (distancia[i] < minimo && !visitado[i]){
                minimo = distancia[i];
                proximo = i;
            }
        }
        //se nao houver mais vertices nao visitados, para o loop      
        if (minimo == 999999){
            break;
        }
        //marca o vertice como visitado
        visitado[proximo] = 1;
        
        //atualiza a distancia dos vertices adjacentes ao vertice visitado
        for (int i = 0; i < grafo->qtd_vertices; i++){
            if (grafo->matriz[proximo][i] != 0){
                if (distancia[i] > grafo->matriz[proximo][i] && !visitado[i]){
                    distancia[i] = grafo->matriz[proximo][i];
                }
            }
        }
    }
    
    free(visitado);
    return distancia;
}

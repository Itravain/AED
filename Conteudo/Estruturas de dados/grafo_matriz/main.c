#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct grafo{
    int qtd_vertices;
    int qtd_arestas;
    int **matriz;
} grafo_t;

//dijkstra algorithm reteurning distances from a given vertex
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


int main(){
    int opcao, qtd_vertices, inicial, final, peso;

    printf("Digite a quantidade de vertices do grafo: ");
    scanf("%d", &qtd_vertices);

    grafo_t *grafo = init_grafos(qtd_vertices);

    
    printf("\n____________________________\n0: Sair\n1: Cria aresta\n2: Remover Aresta\n3: Printar Grafo\n 4: Menor caminho ate um vertice\nOpcao: ");
    
    do
    {
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            scanf("%d %d %d", &inicial, &final, &peso);
            criar_aresta(grafo, inicial, final, peso);
            break;
        case 2:
            scanf("%d %d", &inicial, &final);
            remover_aresta(grafo, inicial, final);
            break;
        case 3:
            imprimir_grafo(grafo);
            break;
        case 4:
            int *distancia = NULL;
            printf("Selecione o vertice inicial: ");
            scanf("%d", &inicial);
            distancia = dijkstra(grafo, inicial);
            printf("Selecione a qual vertice deseja chegar: ");
            scanf("%d", &final);
            printf("Distancia: %d\n", distancia[final]);
            break;
        default:
            break;
        }

    } while (opcao != 0);

    
    

    return 0;
}
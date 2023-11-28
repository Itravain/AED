#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define true 1
#define false 0
typedef int bool;

typedef int boolean;
typedef int WeightType;

typedef struct Adjacency {
    int vertex;
    WeightType weight;
    struct Adjacency *next;
} Adjacency;

typedef struct Vertex {
    Adjacency *head;
} Vertex;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Vertex *adjList;
} Graph;

Graph *createGraph(int numVertices) {
    int i;

    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->adjList = (Vertex *)malloc(numVertices * sizeof(Vertex));
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i].head = NULL;
    }
    return graph;
}

Adjacency *createAdjacency(int vertex, WeightType weight) {
    Adjacency *temp = (Adjacency *)malloc(sizeof(Adjacency));
    temp->vertex = vertex;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

boolean addEdge(Graph *graph, int source, int destination, WeightType weight) {
    if (!graph) return false;
    if (source < 0 || source >= graph->numVertices) return false;
    if (destination < 0 || destination >= graph->numVertices) return false;

    Adjacency *newNode = createAdjacency(destination, weight);
    newNode->next = graph->adjList[source].head;
    graph->adjList[source].head = newNode;
    graph->numEdges++;
    return true;
}

int minDistance(int dist[], bool sptSet[], int numVertices, int avoid) {
    int min = INT_MAX;
    int min_index = -1;
    int v;

    for (v = 0; v < numVertices; v++) {
        if (!sptSet[v] && dist[v] <= min && v != avoid) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int parent[], int src, int dest) {

    printPath(parent, dest);
    printf("\n");
}

void dijkstra(Graph *graph, int src, int dest, int avoid) {
    int numVertices = graph->numVertices;
    int dist[numVertices];
    bool sptSet[numVertices];
    int parent[numVertices];
    int i;

    for (i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    int count;
    for (count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet, numVertices, avoid);
        sptSet[u] = true;

        Adjacency *v = graph->adjList[u].head;
        while (v != NULL) {
            if (!sptSet[v->vertex] && dist[u] != INT_MAX && dist[u] + v->weight < dist[v->vertex]) {
                dist[v->vertex] = dist[u] + v->weight;
                parent[v->vertex] = u;
            }
            v = v->next;
        }
    }

    printSolution(dist, parent, src, dest);
}

int main() {
    int num_cities, num_routes, i, e_city, c_city, r_city, a, b;

    while (scanf("%d %d", &num_cities, &num_routes) == 2) {
        Graph *mapa = createGraph(num_cities);

        for (i = 0; i < num_routes; i++) {
            scanf("%d %d", &a, &b);
            getchar();
            addEdge(mapa, a, b, 1);
            addEdge(mapa, b, a, 1);
        }
        scanf("%d %d %d", &c_city, &r_city, &e_city);

        dijkstra(mapa, c_city, r_city, e_city);

        free(mapa->adjList);
        free(mapa);
    }

    return 0;
}

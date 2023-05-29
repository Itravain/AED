#include <stdio.h>
#include <stdlib.h>

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
//function to print the graph
void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        Adjacency *temp = graph->adjList[i].head;
        printf("\n Adjacency list of vertex %d\n ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
//breadth first search algorithm
void bfs(Graph *graph, int source) {
    int i, j, k, count;
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    int *path = (int *)malloc(graph->numVertices * sizeof(int));
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    visited[source] = true;
    queue[rear++] = source;
    while (front < rear) {
        k = queue[front++];
        for (j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->adjList[k].head != NULL) {
                visited[j] = true;
                path[j] = k;
                queue[rear++] = j;
            }
        }
    }
    printf("\nVertex\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", i);
    }
    printf("\nVisited\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", visited[i]);
    }
    printf("\nPath\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}

//depth first search algorithm
void dfs(Graph *graph, int source) {
    int i, j, k, count;
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    int *path = (int *)malloc(graph->numVertices * sizeof(int));
    int *stack = (int *)malloc(graph->numVertices * sizeof(int));
    int top = -1;

    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    visited[source] = true;
    stack[++top] = source;
    while (top != -1) {
        k = stack[top--];
        for (j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->adjList[k].head != NULL) {
                visited[j] = true;
                path[j] = k;
                stack[++top] = j;
            }
        }
    }
    printf("\nVertex\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", i);
    }
    printf("\nVisited\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", visited[i]);
    }
    printf("\nPath\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}

// Djikstra's algorithm to find shortest path from source to all other vertices and print the shortest path
void dijkstra(Graph *graph, int source) {
    int i, j, k, min, count;
    int *distance = (int *)malloc(graph->numVertices * sizeof(int));
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    int *path = (int *)malloc(graph->numVertices * sizeof(int));

    for (i = 0; i < graph->numVertices; i++) {
        distance[i] = 9999;
        visited[i] = false;
        path[i] = -1;
    }

    distance[source] = 0;
    for (count = 0; count < graph->numVertices - 1; count++) {
        min = 9999;
        for (i = 0; i < graph->numVertices; i++) {
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                k = i;
            }
        }
        visited[k] = true;
        for (j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->adjList[k].head != NULL && distance[k] != 9999 && distance[k] + graph->adjList[k].head->weight < distance[j]) {
                distance[j] = distance[k] + graph->adjList[k].head->weight;
                path[j] = k;
            }
        }
    }
    printf("\nVertex\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", i);
    }
    printf("\nDistance\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", distance[i]);
    }
    printf("\nPath\t\t: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}


int main() {

    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 2, 0, 40);
    addEdge(graph, 2, 3, 50);
    addEdge(graph, 3, 3, 60);
    addEdge(graph, 3, 1, 70);
    //printGraph(graph);
    bfs(graph, 0);

    return 0;
}

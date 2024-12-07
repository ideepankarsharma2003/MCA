#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void prims(int graph[V][V], int vertices) {
    int parent[vertices], key[vertices];
    bool mstSet[vertices];

    for (int i = 0; i < vertices; i++) key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (int i = 1; i < vertices; i++)
        printf("Edge (%d, %d) with weight %d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    prims(graph, vertices);
    return 0;
}
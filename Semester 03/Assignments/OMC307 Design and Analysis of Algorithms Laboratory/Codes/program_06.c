#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int n, int e) {
    int parent[n];
    for (int i = 0; i < n; i++) parent[i] = -1;

    qsort(edges, e, sizeof(Edge), compare);

    printf("Edges in Minimum Spanning Tree:\n");
    int minCost = 0;
    for (int i = 0; i < e; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y) {
            printf("Edge (%d, %d) with weight %d\n", edges[i].u, edges[i].v, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(parent, x, y);
        }
    }
    printf("Minimum Cost: %d\n", minCost);
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    Edge edges[e];
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u, v, weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, n, e);
    return 0;
}
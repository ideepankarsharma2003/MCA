#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]); // Path compression
    return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int kruskal(Edge edges[], int n, int e) {
    int parent[n + 1];
    int rank[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // Each node is its own parent initially
        rank[i] = 0;   // Initialize rank
    }

    qsort(edges, e, sizeof(Edge), compare);

    printf("Edges in Minimum Spanning Tree:\n");
    int minCost = 0;
    for (int i = 0; i < e; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y) {
            printf("Edge (%d, %d) with weight %d\n", edges[i].u, edges[i].v, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(parent, rank, x, y);
        }
    }
    return minCost;
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

    int minCost = kruskal(edges, n, e);
    printf("Minimum Cost: %d\n", minCost);
    return 0;
}


/**
 * @test1
 *
 * Input:
 *    Number of vertices: 3  
 *    Number of edges: 3  
 *    Edges:
 *    1 2 10  
 *    2 3 15  
 *    1 3 5
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (1, 3) with weight 5
 *    Edge (1, 2) with weight 10
 *    Minimum Cost: 15
 */

/**
 * @test2
 *
 * Input:
 *    Number of vertices: 4  
 *    Number of edges: 2  
 *    Edges:
 *    1 2 6  
 *    3 4 4
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (3, 4) with weight 4
 *    Edge (1, 2) with weight 6
 *    Minimum Cost: 10
 */

/**
 * @test3
 *
 * Input:
 *    Number of vertices: 4  
 *    Number of edges: 6  
 *    Edges:
 *    1 2 1  
 *    1 3 5  
 *    1 4 3  
 *    2 3 4  
 *    2 4 2  
 *    3 4 6
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (1, 2) with weight 1
 *    Edge (2, 4) with weight 2
 *    Edge (1, 4) with weight 3
 *    Minimum Cost: 6
 */

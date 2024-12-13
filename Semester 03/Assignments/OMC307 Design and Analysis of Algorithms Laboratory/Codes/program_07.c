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


/**
 * @test1
 *
 * Input:
 *    Number of vertices: 5
 *    Adjacency matrix:
 *    0   2   0   6   0
 *    2   0   3   8   5
 *    0   3   0   0   7
 *    6   8   0   0   9
 *    0   5   7   9   0
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (0, 1) with weight 2
 *    Edge (1, 2) with weight 3
 *    Edge (0, 3) with weight 6
 *    Edge (1, 4) with weight 5
 */

/**
 * @test2
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0   10  6   5
 *    10  0   0   15
 *    6   0   0   4
 *    5   15  4   0
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (0, 3) with weight 5
 *    Edge (3, 2) with weight 4
 *    Edge (0, 1) with weight 10
 */

/**
 * @test3
 *
 * Input:
 *    Number of vertices: 3
 *    Adjacency matrix:
 *    0   1   3
 *    1   0   2
 *    3   2   0
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (0, 1) with weight 1
 *    Edge (1, 2) with weight 2
 */

/**
 * @test4
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0   99999   3   99999
 *    99999   0   99999   7
 *    3   99999   0   4
 *    99999   7   4   0
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (0, 2) with weight 3
 *    Edge (2, 3) with weight 4
 *    Edge (3, 1) with weight 7
 */

/**
 * @test5
 *
 * Input:
 *    Number of vertices: 2
 *    Adjacency matrix:
 *    0   1
 *    1   0
 *
 * Expected Output:
 *    Edges in Minimum Spanning Tree:
 *    Edge (0, 1) with weight 1
 */

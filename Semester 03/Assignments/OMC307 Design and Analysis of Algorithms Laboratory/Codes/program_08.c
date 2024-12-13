#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100

int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src, int vertices) {
    int dist[vertices];
    bool sptSet[vertices];
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < vertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
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

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, vertices);
    return 0;
}

/**
 * @test1
 *
 * Input:
 *    Number of vertices: 5
 *    Adjacency matrix:
 *    0   10  0   0   5
 *    0   0   1   0   2
 *    0   0   0   4   0
 *    7   0   6   0   0
 *    0   3   9   2   0
 *    Source vertex: 0
 *
 * Expected Output:
 *    Vertex      Distance from Source 0
 *    0           0
 *    1           8
 *    2           9
 *    3           7
 *    4           5
 */

/**
 * @test2
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0   1   4   0
 *    0   0   4   2
 *    0   0   0   3
 *    0   0   0   0
 *    Source vertex: 0
 *
 * Expected Output:
 *    Vertex      Distance from Source 0
 *    0           0
 *    1           1
 *    2           4
 *    3           3
 */

/**
 * @test3
 *
 * Input:
 *    Number of vertices: 3
 *    Adjacency matrix:
 *    0   0   0
 *    0   0   0
 *    0   0   0
 *    Source vertex: 0
 *
 * Expected Output:
 *    Vertex      Distance from Source 0
 *    0           0
 *    1           2147483647
 *    2           2147483647
 */

/**
 * @test4
 *
 * Input:
 *    Number of vertices: 6
 *    Adjacency matrix:
 *    0   2   0   1   0   0
 *    0   0   3   2   0   0
 *    0   0   0   0   2   3
 *    0   0   0   0   1   0
 *    0   0   0   0   0   1
 *    0   0   0   0   0   0
 *    Source vertex: 0
 *
 * Expected Output:
 *    Vertex      Distance from Source 0
 *    0           0
 *    1           2
 *    2           5
 *    3           1
 *    4           2
 *    5           3
 */

/**
 * @test5
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0   5   99999   10
 *    99999   0   3   99999
 *    99999   99999   0   1
 *    99999   99999   99999   0
 *    Source vertex: 0
 *
 * Expected Output:
 *    Vertex      Distance from Source 0
 *    0           0
 *    1           5
 *    2           8
 *    3           9
 */

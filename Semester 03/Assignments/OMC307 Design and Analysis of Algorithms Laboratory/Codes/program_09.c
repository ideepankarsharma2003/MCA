#include <stdio.h>

#define INF 99999
#define V 100

void floydWarshall(int graph[V][V], int vertices) {
    int dist[V][V];
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("All-Pairs Shortest Paths:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter adjacency matrix (use 99999 for INF):\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, vertices);
    return 0;
}



/**
 * @test1
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0    5   99999 10
 *    99999 0   3   99999
 *    99999 99999 0   1
 *    99999 99999 99999 0
 *
 * Expected Output:
 *    All-Pairs Shortest Paths:
 *    0 5 8 9
 *    INF 0 3 4
 *    INF INF 0 1
 *    INF INF INF 0
 */

/**
 * @test2
 *
 * Input:
 *    Number of vertices: 3
 *    Adjacency matrix:
 *    0   1 99999
 *    99999 0 1
 *    1 99999 0
 *
 * Expected Output:
 *    All-Pairs Shortest Paths:
 *    0 1 2
 *    2 0 1
 *    1 2 0
 */

/**
 * @test3
 *
 * Input:
 *    Number of vertices: 5
 *    Adjacency matrix:
 *    0   3  99999 7  99999
 *    99999 0  1  99999 99999
 *    99999 99999 0  2  99999
 *    99999 99999 99999 0  1
 *    6   99999 99999 99999 0
 *
 * Expected Output:
 *    All-Pairs Shortest Paths:
 *    0 3 4 6 7
 *    INF 0 1 3 4
 *    INF INF 0 2 3
 *    INF INF INF 0 1
 *    6 9 10 12 0
 */

/**
 * @test4
 *
 * Input:
 *    Number of vertices: 2
 *    Adjacency matrix:
 *    0 99999
 *    99999 0
 *
 * Expected Output:
 *    All-Pairs Shortest Paths:
 *    0 INF
 *    INF 0
 */

/**
 * @test5
 *
 * Input:
 *    Number of vertices: 4
 *    Adjacency matrix:
 *    0   2 99999 99999
 *    99999 0   1   99999
 *    99999 99999 0   3
 *    1 99999 99999 0
 *
 * Expected Output:
 *    All-Pairs Shortest Paths:
 *    0 2 3 6
 *    INF 0 1 4
 *    INF INF 0 3
 *    1 3 4 0
 */

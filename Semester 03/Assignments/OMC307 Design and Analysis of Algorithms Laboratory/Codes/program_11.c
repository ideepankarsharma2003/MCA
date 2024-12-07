#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int graph[][10], bool visited[], int vertex, int n) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}



void bfs(int graph[][10], int start, int n) {
    bool visited[10] = {false};
    int queue[10], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, graph[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    bool visited[10] = {false};
    // dfs
    printf("DFS Traversal: ");
    dfs(graph, visited, 0, n);
    // bfs
    printf("BFS Traversal: ");
    bfs(graph, 0, n);
    return 0;
}
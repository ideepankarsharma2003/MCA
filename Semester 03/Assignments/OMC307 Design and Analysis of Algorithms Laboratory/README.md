# Lab Assignment: **Design and Analysis of Algorithms**

---

### [Program 01: GCD using Recursion](Codes/program_01.c)

```c
#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/50272d4d-6f4b-4db0-9ab8-0cef3ce79830)|![image](https://github.com/user-attachments/assets/fdd736ac-ae0a-404f-ab59-1d263f5dbbcc)|![image](https://github.com/user-attachments/assets/671e9acd-6a63-4394-bd8e-5db47cb405e2)|


---

### [Program 02: Towers of Hanoi](Codes/program_02.c)

```c
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
```


|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/14d446dd-949e-4347-a657-6ba8f3a7a96a)|![image](https://github.com/user-attachments/assets/29cdadb4-b849-43cb-b24f-3d7b869774c0)|![image](https://github.com/user-attachments/assets/c5798791-141b-4680-822d-2269e555eb02)|

---



### [Program 03: Merge Sort](Codes/program_03.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, *arr;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}
```


|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/8b4f03a7-0ee5-4206-9fed-16ec1c5d987e)|![image](https://github.com/user-attachments/assets/cab5bf6a-7f74-43f1-82c8-4bfd532246bd)|![image](https://github.com/user-attachments/assets/e4cce7bc-1b9d-4a21-b312-d7168c125918)|

---




### [Program 04: Quick Sort](Codes/program_04.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, temp;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[++i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, *arr;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/f9a59495-6bd6-463d-b61f-e22542cb0d69)|![image](https://github.com/user-attachments/assets/3401564f-5772-4bb8-9a6a-897f34ddba2c)|![image](https://github.com/user-attachments/assets/cdc89a71-94fd-4b6f-8322-b9170d582d33)|

---





### [Program 05: Job Sequencing Problem](Codes/program_05.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id, deadline, profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    }

    bool slot[maxDeadline];
    int result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    printf("Job sequence for maximum profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) printf("Job %d (Profit: %d)\n", jobs[result[i]].id, jobs[result[i]].profit);
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter job id, deadline, and profit for job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/afc69b95-9acd-4823-a8dc-7a088c78456a)|![image](https://github.com/user-attachments/assets/c7df8704-489d-4222-8411-802ebdeffba6)|![image](https://github.com/user-attachments/assets/a46c5cab-98a6-4b83-b020-10f5f1e12e3f)|


---

### [Program 06: Minimum Cost Spanning Tree using Kruskal's Method](Codes/program_06.c)

```c
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
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/2d005a39-4a27-4427-9c3c-6b6f763d8d9a)|![image](https://github.com/user-attachments/assets/0022a13b-4dfb-4698-9034-790c49e862c2)|![image](https://github.com/user-attachments/assets/3ae577d8-71fe-46d1-a60c-a83469c4f2f9)|

---

### [Program 07: Minimum Cost Spanning Tree using Prim's Method](Codes/program_07.c)

```c
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
```
|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/67f537a5-31d5-41e1-aea3-468f01c01153)|![image](https://github.com/user-attachments/assets/0b6f88dd-223e-4b3f-baa9-298e9d9abfac)|![image](https://github.com/user-attachments/assets/18855291-282e-4d25-ab4b-f4c3d8dd716b)|

---

### [Program 08: Dijkstra’s Algorithm](Codes/program_08.c)

```c
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
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/1808b1b7-5257-414e-b4a8-92f886ef935b)|![image](https://github.com/user-attachments/assets/88b0c36d-bddb-487c-9179-8690f927d4b4)|![image](https://github.com/user-attachments/assets/f05033df-4522-4085-ab45-8de59010d1c4)|

---

### [Program 09: Floyd’s Algorithm](Codes/program_09.c)

```c
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
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/fa86dc41-1ada-45ad-bdd6-fb3cc6d8726f)|![image](https://github.com/user-attachments/assets/52e32824-65a8-4e8c-a344-432c3a59b5ff)|![image](https://github.com/user-attachments/assets/6d437bbd-edb9-4e1e-a808-c23192a5a085)|

---

### [Program 10: 0/1 Knapsack Problem using Dynamic Programming](Codes/program_10.c)

```c
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("Maximum value in Knapsack = %d\n", K[n][W]);
}

int main() {
    int n, W;
    printf("Enter number of items and capacity of knapsack: ");
    scanf("%d %d", &n, &W);

    int val[n], wt[n];
    printf("Enter weights and values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &wt[i], &val[i]);

    knapsack(W, wt, val, n);
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/77ed685e-076e-4bb6-9c32-46856cc77971)|![image](https://github.com/user-attachments/assets/1ddaac3e-c9c3-4b36-a7d0-ee0284b50282)|![image](https://github.com/user-attachments/assets/e4e2e734-6b53-45bd-aeea-8768bfa0a774)|
---

### [Program 11: Graph Traversal: BFS and DFS](Codes/program_11.c)

```c
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
```
|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/d0db7a08-9139-4546-9585-fbb9263fcf67)|![image](https://github.com/user-attachments/assets/3e0210c8-5af9-43d9-adcc-68cdf2c3d8ba)|![image](https://github.com/user-attachments/assets/599e9b02-4d3b-498d-ad2c-dc3f017c59b6)|

---



### [Program 12: Subset Sum Problem using Backtracking](Codes/program_12.c)

```c
#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int arr[], int subset[], int n, int index, int currentSum, int targetSum) {
    if (currentSum == targetSum) {
        printSubset(subset, index);
        return;
    }

    if (n == 0) return;

    subset[index] = arr[0];
    subsetSum(arr + 1, subset, n - 1, index + 1, currentSum + arr[0], targetSum);
    subsetSum(arr + 1, subset, n - 1, index, currentSum, targetSum);
}

int main() {
    int n, targetSum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], subset[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with target sum:\n");
    subsetSum(arr, subset, n, 0, 0, targetSum);
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/6d43a724-b4ad-440c-bc89-6fc38d6240d8)|![image](https://github.com/user-attachments/assets/e00beaa7-e3f9-43e0-84c7-a670764f4daf)|![image](https://github.com/user-attachments/assets/e1a15ba5-0293-438d-91ce-475aa39dc86a)|

---

### [Program 13: N-Queens Problem using Backtracking](Codes/program_13.c)

```c
#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1)) return true;
            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int board[N][N] = {0};
    if (solveNQUtil(board, 0))
        printSolution(board);
    else
        printf("No solution exists\n");
    return 0;
}
```

|output 1| output 2| output 3|
|------------|------------|------------|
|![image](https://github.com/user-attachments/assets/d86c2163-18af-4aca-ad9f-541075d59f31)|![image](https://github.com/user-attachments/assets/606dbaa6-47d4-4645-a164-c123a0314800)|![image](https://github.com/user-attachments/assets/62f57214-7da1-4706-8831-50335b8690b0)|

---

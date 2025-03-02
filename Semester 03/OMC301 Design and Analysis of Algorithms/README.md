# **Design and Analysis of Algorithms Laboratory (OMC307)**  
### **Master of Computer Applications (MCA) - Semester III**  

---

## **Unit 1: Introduction to Algorithm Analysis**  

### **Key Concepts:**
1. **Asymptotic Notations:**  
   - **Big O (O)**: Upper bound (worst case)
   - **Theta (Θ)**: Tight bound (average case)
   - **Omega (Ω)**: Lower bound (best case)

2. **Algorithm Complexity:**  
   - **Time Complexity:** How execution time grows with input size.
   - **Space Complexity:** How much memory an algorithm needs.

3. **Efficiency Classes:**  
   - **P (Polynomial Time):** Problems solvable in polynomial time.
   - **NP (Nondeterministic Polynomial Time):** Problems verifiable in polynomial time.
   - **NP-Hard & NP-Complete:** Computationally difficult problems.

---

## **Unit 2: List of Experiments with C Programs**

---

### **1. GCD Calculation using Recursion**  
- **Concepts Used:** Recursion, Euclidean algorithm  
- **Time Complexity:** O(log min(a, b))  
- **Space Complexity:** O(log min(a, b)) (Recursive Call Stack)  

#### **C Program:**
```c
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a = 56, b = 98;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}
```

---

### **2. Towers of Hanoi Problem**  
- **Concepts Used:** Recursion  
- **Time Complexity:** O(2^n)  
- **Space Complexity:** O(n) (Recursive Stack)  

#### **C Program:**
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
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
```

---

### **3. Merge Sort Algorithm**  
- **Concepts Used:** Divide and Conquer  
- **Time Complexity:** O(n log n)  
- **Space Complexity:** O(n)  

#### **C Program:**
```c
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

---

### **4. Quick Sort Algorithm**  
- **Concepts Used:** Divide and Conquer  
- **Time Complexity:**  
  - Best/Average Case: O(n log n)  
  - Worst Case: O(n²)  
- **Space Complexity:** O(log n)  

#### **C Program:**
```c
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```



---

### **5. Job Sequencing Problem (Greedy Method)**  
- **Concepts Used:** Greedy Algorithm  
- **Time Complexity:** O(n log n) (sorting jobs by profit)  
- **Space Complexity:** O(n)  

#### **C Program:**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    char id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int result[n];
    int slot[n];
    for (int i = 0; i < n; i++) slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline - 1); j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", jobs[result[i]].id);
}

int main() {
    Job jobs[] = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}
```

---

### **6. Minimum Cost Spanning Tree using Kruskal’s Algorithm**  
- **Concepts Used:** Greedy Algorithm, Disjoint-Set Union (DSU)  
- **Time Complexity:** O(E log E) (Sorting edges + Union-Find)  
- **Space Complexity:** O(V + E)  

#### **C Program:**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge *edge;
} Graph;

Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskalMST(Graph *graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0, i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    int *parent = (int *)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(parent, x, y);
        }
    }

    printf("Edges in MST:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4, E = 5;
    Graph *graph = createGraph(V, E);
    graph->edge[0] = (Edge){0, 1, 10};
    graph->edge[1] = (Edge){0, 2, 6};
    graph->edge[2] = (Edge){0, 3, 5};
    graph->edge[3] = (Edge){1, 3, 15};
    graph->edge[4] = (Edge){2, 3, 4};

    kruskalMST(graph);
    return 0;
}
```

---

### **7. Minimum Cost Spanning Tree using Prim’s Algorithm**  
- **Concepts Used:** Greedy Algorithm, Priority Queue  
- **Time Complexity:** O(E log V) (Priority Queue Operations)  
- **Space Complexity:** O(V²)  

#### **C Program:**
```c
#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primMST(graph);
    return 0;
}
```


---

### **8. Dijkstra’s Algorithm (Single Source Shortest Path)**
- **Concepts Used:** Greedy Algorithm, Priority Queue (Min Heap)
- **Time Complexity:** O((V + E) log V) (Using Min Heap)
- **Space Complexity:** O(V)  

#### **C Program:**
```c
#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 5},
                       {0, 0, 1, 0, 2},
                       {0, 0, 0, 4, 0},
                       {7, 0, 6, 0, 0},
                       {0, 3, 9, 2, 0}};
    
    dijkstra(graph, 0);
    return 0;
}
```

---

### **9. Floyd’s Algorithm (All-Pairs Shortest Paths)**
- **Concepts Used:** Dynamic Programming
- **Time Complexity:** O(n³)
- **Space Complexity:** O(n²)

#### **C Program:**
```c
#include <stdio.h>

#define INF 99999
#define V 4

void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printSolution(dist);
}

int main() {
    int graph[V][V] = {{0, 3, INF, 5},
                       {2, 0, INF, 4},
                       {INF, 1, 0, INF},
                       {INF, INF, 2, 0}};

    floydWarshall(graph);
    return 0;
}
```

---

### **10. 0/1 Knapsack Problem (Dynamic Programming)**
- **Concepts Used:** Dynamic Programming, Subproblem Optimization
- **Time Complexity:** O(nW) (where W is the capacity of the knapsack)
- **Space Complexity:** O(nW)

#### **C Program:**
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

    printf("Maximum Value in Knapsack = %d\n", K[n][W]);
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    knapsack(W, wt, val, n);
    return 0;
}
```

---

### **11. Graph Operations and Traversal (BFS & DFS)**
- **Concepts Used:** Graph Representation, DFS (Recursion), BFS (Queue)
- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V)

#### **C Program for BFS & DFS:**
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    printf("BFS Traversal: ");
    BFS(0);
    printf("\n");

    return 0;
}
```

---

## **Final Summary**
1. **Efficiency Analysis**  
   - Understand algorithmic efficiency using **asymptotic notations**.

2. **Algorithm Design Strategies**  
   - **Divide & Conquer:** Merge Sort, Quick Sort  
   - **Greedy Method:** Kruskal’s, Prim’s, Dijkstra’s, Job Sequencing  
   - **Dynamic Programming:** Floyd’s, 0/1 Knapsack  

3. **Graph Algorithms**  
   - **Graph Representation:** Adjacency Matrix/List  
   - **Graph Traversals:** DFS, BFS  
   - **Shortest Paths:** Dijkstra’s, Floyd’s  
   - **Minimum Spanning Trees:** Kruskal’s, Prim’s  

4. **Optimization Problems**  
   - Greedy method provides **locally optimal** solutions.  
   - Dynamic Programming ensures **globally optimal** solutions.  

---

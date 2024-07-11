### EXPERIMENT- 1
Problem definition: Write a C Program to find minimum and maximum in an array.

Algorithm:
1. Start
2. Initialize variables `min` and `max` with the first element of the array.
3. Traverse through the array from the second element to the last element.
4. For each element, compare it with `min` and `max`:
   - If the element is smaller than `min`, update `min` with this element.
   - If the element is greater than `max`, update `max` with this element.
5. Stop

Source Program:
```c
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);

    return 0;
}
```

Sample Input/Output:
```
Enter the number of elements in the array: 5
Enter the elements of the array:
1 2 3 4 5
Minimum element is 1
Maximum element is 5
```

---

### EXPERIMENT- 2
Problem definition: Write a C Program to demonstrate stack operations using an array.

Algorithm:
1. Start
2. Initialize top to -1
3. Implement functions for push, pop, and display operations
   - Push: Check if stack is full, if not, add element to stack and increment top.
   - Pop: Check if stack is empty, if not, remove element from stack and decrement top.
   - Display: Print all elements from top to bottom.
4. Perform stack operations based on user choice.
5. Stop

Source Program:
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
```

Sample Input/Output:
```
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to be pushed: 5
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements are:
5
```

---

### EXPERIMENT- 3
Problem definition: Write a C Program to demonstrate Queue operations using arrays.

Algorithm:
1. Start
2. Initialize front and rear to -1
3. Implement functions for enqueue, dequeue, and display operations:
   - Enqueue: Check if queue is full, if not, add element to queue and increment rear.
   - Dequeue: Check if queue is empty, if not, remove element from queue and increment front.
   - Display: Print all elements from front to rear.
4. Perform queue operations based on user choice.
5. Stop

Source Program:
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
```

Sample Input/Output:
```
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to be enqueued: 10
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements are:
10
```

---

### EXPERIMENT- 4
Problem definition: Write C Programs to demonstrate the following operations on a linked list:
- Creation of a list
- Adding an element at the beginning of the list
- Adding an element at the end of the list
- Deleting the first element
- Deleting the last element

Algorithm:
1. Start
2. Implement functions for linked list operations:
   - Create list
   - Add element at the beginning
   - Add element at the end
   - Delete first element
   - Delete last element
3. Perform linked list operations based on user choice.
4. Stop

Source Program:
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    struct Node* newNode, *temp;
    int data, i;

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Unable to allocate memory.\n");
        exit(0);
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Unable to allocate memory.\n");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void addAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void addAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFirst() {
    struct Node* temp;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    struct Node* temp = head;
    struct Node* prevNode;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
}

void displayList() {
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data, n;

    while (1) {
        printf("1. Create List\n2. Add at Beginning\n3. Add at End\n4. Delete First\n5. Delete Last\n6. Display List\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                addAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                displayList();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
```

Sample Input/Output:
```
1. Create List
2. Add at Beginning
3. Add at End
4. Delete First
5. Delete Last
6. Display List
7. Exit
Enter your choice: 1
Enter the number of nodes: 3
Enter the data of node 1: 10
Enter the data of node 2: 20
Enter the data of node 3: 30
1. Create List
2. Add at Beginning
3. Add at End
4. Delete First
5. Delete Last
6. Display List
7. Exit
Enter your choice: 6
Data = 10
Data = 20
Data = 30
```

---

### EXPERIMENT- 5
Problem definition: Write a C Program to develop a binary tree and perform tree traversal.

Algorithm:
1. Start
2. Implement functions for binary tree operations:
   - Create tree
   - Preorder traversal
   - Inorder traversal
   - Postorder traversal
3. Perform tree operations based on user choice.
4. Stop

Source Program:
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root)

 {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
```

Sample Input/Output:
```
1. Insert Node
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 50
1. Insert Node
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 30
1. Insert Node
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 70
1. Insert Node
2. Preorder Traversal
3. Inorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 3
Inorder traversal: 30 50 70 
```

---

### EXPERIMENT- 6
Problem definition: Write a C Program to demonstrate Quick Sort.

Algorithm:
1. Start
2. Implement functions for quick sort:
   - Partition the array
   - Recursively sort the subarrays
3. Call the quick sort function and print the sorted array.
4. Stop

Source Program:
```c
#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
```

Sample Input/Output:
```
Enter the number of elements: 5
Enter the elements of the array:
5 2 9 1 5
Sorted array: 1 2 5 5 9
```

---

### EXPERIMENT- 7
Problem definition: Write a C Program to implement the Linear Search.

Algorithm:
1. Start
2. Traverse through the array and compare each element with the target.
3. If the element is found, print its position.
4. If the element is not found, print a message indicating so.
5. Stop

Source Program:
```c
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", result + 1);

    return 0;
}
```

Sample Input/Output:
```
Enter the number of elements: 5
Enter the elements of the array:
1 2 3 4 5
Enter the element to search: 3
Element found at position 3
```

---

### EXPERIMENT- 8
Problem definition: Write a C Program to implement the Binary Search.

Algorithm:
1. Start
2. Sort the array
3. Implement binary search:
   - Compare the target element with the middle element of the array.
   - If equal, return the position.
   - If less, repeat the process with the left subarray.
   - If greater, repeat the process with the right subarray.
4. If the element is not found, print a message indicating so.
5. Stop

Source Program:
```c
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", result + 1);

    return 0;
}
```

Sample Input/Output:
```
Enter the number of elements: 5
Enter the elements of the array:
5 1 4 2 3
Enter the element to search: 3
Element found at position 3
```

---

### EXPERIMENT- 9
Problem definition: Write a C Program on a graph to perform the Depth First Search (DFS) and the Breadth First Search (BFS).

Algorithm:
1. Start
2. Implement functions for DFS and BFS:
   - Initialize visited array
   - For DFS, use stack or recursion
   - For BFS, use queue
3. Call the DFS and BFS functions and print the traversal.
4. Stop

Source Program:
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    int queue[MAX], front = -1, rear = -1;
    printf("%d ", v);
    visited[v] = 1;
    queue[++rear] = v;

    while (front != rear)

 {
        v = queue[++front];
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    printf("DFS Traversal: ");
    DFS(v);
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("\nBFS Traversal: ");
    BFS(v);

    return 0;
}
```

Sample Input/Output:
```
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the starting vertex: 0
DFS Traversal: 0 1 3 2 
BFS Traversal: 0 1 2 3 
```

---

### EXPERIMENT- 10
Problem definition: Write a C Program to find the shortest path in a graph using Floyd Warshall’s Algorithm.

Algorithm:
1. Start
2. Implement the Floyd Warshall algorithm:
   - Initialize the distance matrix with graph weights
   - Update the distance matrix for all pairs using intermediate vertices
3. Print the shortest distance matrix.
4. Stop

Source Program:
```c
#include <stdio.h>

#define INF 99999
#define MAX 10

void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 99999 for INF):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
```

Sample Input/Output:
```
Enter the number of vertices: 4
Enter the adjacency matrix (use 99999 for INF):
0 3 99999 7
8 0 2 99999
5 99999 0 1
2 99999 99999 0
Shortest distances between every pair of vertices:
      0       3       5       6
      5       0       2       3
      3       6       0       1
      2       5       7       0
```

---

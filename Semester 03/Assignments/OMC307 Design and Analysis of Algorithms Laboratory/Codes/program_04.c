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
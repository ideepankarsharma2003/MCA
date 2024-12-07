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
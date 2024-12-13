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


/**
 * @test1
 *
 * Input:
 *    Number of elements: 5  
 *    Elements:  
 *    1 2 3 4 5  
 *    Target sum: 5
 *
 * Expected Output:
 *    Subsets with target sum:  
 *    2 3  
 *    1 4  
 *    5  
 */

/**
 * @test2
 *
 * Input:
 *    Number of elements: 4  
 *    Elements:  
 *    1 3 6 8  
 *    Target sum: 20
 *
 * Expected Output:
 *    Subsets with target sum:  
 *    (No output, as no subset matches the target sum.)  
 */

/**
 * @test3
 *
 * Input:
 *    Number of elements: 6  
 *    Elements:  
 *    10 15 20 25 5 30  
 *    Target sum: 5
 *
 * Expected Output:
 *    Subsets with target sum:  
 *    5  
 */

/**
 * @test4
 *
 * Input:
 *    Number of elements: 3  
 *    Elements:  
 *    2 2 2  
 *    Target sum: 6
 *
 * Expected Output:
 *    Subsets with target sum:  
 *    2 2 2  
 */

/**
 * @test5
 *
 * Input:
 *    Number of elements: 4  
 *    Elements:  
 *    1 2 3 4  
 *    Target sum: 6
 *
 * Expected Output:
 *    Subsets with target sum:  
 *    1 2 3  
 *    2 4  
 */

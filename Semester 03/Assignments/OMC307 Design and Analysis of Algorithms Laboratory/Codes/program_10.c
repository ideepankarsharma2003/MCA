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

/**
 * @test1
 *
 * Input:
 *    Number of items: 3  
 *    Capacity of knapsack: 50  
 *    Weights and values of items:  
 *    10 60  
 *    20 100  
 *    30 120  
 *
 * Expected Output:
 *    Maximum value in Knapsack = 220  
 */

/**
 * @test2
 *
 * Input:
 *    Number of items: 4  
 *    Capacity of knapsack: 10  
 *    Weights and values of items:  
 *    1 10  
 *    2 15  
 *    3 40  
 *    4 50  
 *
 * Expected Output:
 *    Maximum value in Knapsack = 65  
 */

/**
 * @test3
 *
 * Input:
 *    Number of items: 5  
 *    Capacity of knapsack: 7  
 *    Weights and values of items:  
 *    1 1  
 *    3 4  
 *    4 5  
 *    5 7  
 *    6 10  
 *
 * Expected Output:
 *    Maximum value in Knapsack = 9  
 */

/**
 * @test4
 *
 * Input:
 *    Number of items: 2  
 *    Capacity of knapsack: 5  
 *    Weights and values of items:  
 *    10 50  
 *    20 100  
 *
 * Expected Output:
 *    Maximum value in Knapsack = 0  
 */

/**
 * @test5
 *
 * Input:
 *    Number of items: 6  
 *    Capacity of knapsack: 15  
 *    Weights and values of items:  
 *    5 10  
 *    4 40  
 *    6 30  
 *    3 50  
 *    2 60  
 *    1 90  
 *
 * Expected Output:
 *    Maximum value in Knapsack = 220  
 */

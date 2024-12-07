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
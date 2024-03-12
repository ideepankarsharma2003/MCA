#include <stdio.h>

// Function to allocate memory
void BestFit(int m, int n, int partitions[], int process[])
{
    int allocation[n]; // To store the partition allocated to processes
    int i, j;

    // Initialize to -1 as no block is assigned to processes
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    // For every process, select the best fit partition
    for (i = 0; i < n; i++) // Select process
    {
        int bestPart = -1;
        for (int j = 0; j < m; j++) // Search the partition
        {
            if (partitions[j] >= process[i])
            {
                if (bestPart == -1)
                    bestPart = j;
                else if (partitions[bestPart] > partitions[j])
                    bestPart = j;
            }
        }

        // If best partition is found
        if (bestPart != -1)
        {
            // Allocate partition j to process i
            allocation[i] = bestPart;

            // Reduce the partition size of this block
            partitions[bestPart] -= process[i];
        }
    }

    printf("\nProcess No.\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    int m;            // number of partitions in the memory
    int n;            // number of processes in the input queue
    int i;
    int partitions[10];
    int process[10];

    printf("Enter the number of partitions\n");
    scanf("%d", &m);

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter the partition sizes\n");
    for (i = 0; i < m; i++)
        scanf("%d", &partitions[i]);

    printf("Enter the process sizes\n");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    BestFit(m, n, partitions, process);

    return 0;
}

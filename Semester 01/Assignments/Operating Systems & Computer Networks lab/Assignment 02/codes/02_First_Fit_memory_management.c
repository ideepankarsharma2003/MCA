#include <stdio.h>

// Function to allocate memory
void firstFit(int m, int n, int Blocks[], int Process[])
{
    int i, j;

    // Stores block id of the allocation
    int allocation[n];

    // Initialize to -1 as no block is assigned to processes
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    // Look for available block to the process and allocate if it fits
    for (i = 0; i < n; i++) // n number of processes
    {
        for (j = 0; j < m; j++) // m number of blocks
        {
            if (Blocks[j] >= Process[i])
            {
                // Allocating block j to the ith process
                allocation[i] = j;

                // Reduce available memory in this block.
                Blocks[j] -= Process[i];

                break; // goto the next process in the queue
            }
        }
    }

    printf("\nProcess No.\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t", i + 1, Process[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    int m;         // number of blocks in the memory
    int n;         // number of processes in the input queue
    int i;
    int Blocks[10];
    int Process[10];

    printf("Enter the number of blocks\n");
    scanf("%d", &m);

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter the block sizes\n");
    for (i = 0; i < m; i++)
        scanf("%d", &Blocks[i]);

    printf("Enter the process sizes\n");
    for (i = 0; i < n; i++)
        scanf("%d", &Process[i]);

    firstFit(m, n, Blocks, Process);

    return 0;
}

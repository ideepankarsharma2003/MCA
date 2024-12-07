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
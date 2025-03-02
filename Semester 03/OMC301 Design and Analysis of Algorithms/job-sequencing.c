#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
  return (x < y) ? x : y;
}

int main(void) {
    int i, j;
    Job jobs[10], temp;
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("\nEnter the Job id, Deadline and Profit: ");
        scanf("%s%d%d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Corrected Sorting (Descending Order of Profit)
    for(i = 1; i <= n-1; i++) {  
        for(j = 1; j <= n - i; j++) {  
            if(jobs[j+1].profit > jobs[j].profit) {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("\n%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(i = 1; i <= n; i++) {
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    jobSequencingWithDeadline(jobs, n);
    return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) {
    int i, j, k, maxprofit;
    int timeslot[MAX];
    int filledTimeSlot = 0;
    
    // Find maximum deadline
    int dmax = 0;
    for(i = 1; i <= n; i++) {
        if(jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }

    // Initialize time slots as empty (-1)
    for(i = 1; i <= dmax; i++) {
        timeslot[i] = -1;
    }

    printf("\ndmax: %d\n", dmax);

    for(i = 1; i <= n; i++) {
        k = minValue(dmax, jobs[i].deadline);  // FIXED: Correct index `jobs[i]`
        while(k >= 1) {
            if(timeslot[k] == -1) {
                timeslot[k] = i;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        // Stop if all slots are filled
        if(filledTimeSlot == dmax) {
            break;
        }
    }

    // Required jobs
    printf("\nRequired Jobs: ");
    for(i = 1; i <= dmax; i++) {
        printf("%s", jobs[timeslot[i]].id);
        if(i < dmax) {
            printf(" --> ");
        }
    }

    // Maximum profit calculation
    maxprofit = 0;
    for(i = 1; i <= dmax; i++) {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);
}


/**
 * 
Enter the number of jobs: 4

Enter the Job id, Deadline and Profit:
J1 3 20
J2 1 10
J3 2 40
J4 2 30


Enter the number of jobs: 6

Enter the Job id, Deadline and Profit:
J1 5 200
J2 3 180
J3 3 190
J4 2 300
J5 4 120
J6 2 100


 * 
 */
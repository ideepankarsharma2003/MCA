/* SJF Final */

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void main() {
    int n, i, j;

    struct Process temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for the array of processes
    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    // Reading burst time of each process
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    // Sort the processes based on their burst time in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                // Swap the processes
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print the results
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    // Sort the processes based on their ID in ascending order to print in proper order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].pid > processes[j].pid) {
                // Swap the processes
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time = %.2f ms\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f ms\n", avg_turnaround_time);

    // Free the allocated memory
    free(processes);
}

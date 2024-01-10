#include<stdio.h>
#include<stdlib.h>


struct Process
{
    /* data */
    int pid; 
    int bt;
    int at;
};

void fcfs_scheduling(struct Process*proc, int n){
    int i, wt[n], tat[n], total_wt=0, total_tat=0;
    // calculate waiting time for each process
    wt[0]= 0;
    for ( i = 1; i < n; i++)
    {
        /* code */
        wt[i]= wt[i-1]+ proc[i-1].bt;
    }
    // calculate turnaround time for each process
    for ( i = 0; i < n; i++)
    {
        /* code */
        tat[i]= wt[i]+ proc[i].bt;
    }

    // calculate total waiting and turnaround time
    for (i = 0; i < n; i++)
    {
        /* code */
        total_wt+=wt[i];
        total_tat+=tat[i];
    }

    printf("\nPID\tBT\tAT\tWT\tTAT\n");
    for ( i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f\n", (float)total_wt/n);   
    printf("\nAverage turnaround time: %.2f\n", (float)total_tat/n);   
    
    
}




int main(){
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];

    for ( i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the burst time and arrival time for process %d: ", i+1);
        scanf("%d%d", &proc[i].bt, &proc[i].at);
        proc[i].pid= i+1;
    }

    fcfs_scheduling(proc, n);
    return 0;
    
}
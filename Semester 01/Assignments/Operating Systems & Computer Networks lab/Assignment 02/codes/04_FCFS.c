#include <stdio.h>

struct Process {
    int pid;
    int bt; // burst time
    int at; // arrival time
    int wt; // waiting time
    int tat; // turnaround time
};

void findWaitingTime(struct Process proc[], int n) {
    int rt[n];
    for (int i = 0; i < n; i++) {
        rt[i] = proc[i].bt;
    }

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0) {
            minm = INT_MAX;
        }

        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            proc[shortest].wt = finish_time - proc[shortest].bt - proc[shortest].at;
            proc[shortest].tat = finish_time - proc[shortest].at;
        }
        t++;
    }
}


#include <stdio.h>
#include <string.h>

#define MAX 10

void priority_np() {
    printf("Non-Preemptive Priority Scheduling ----------- \n");

    int n = 5;
    char name[MAX][5] = {"P0", "P1", "P2", "P3", "P4"};
    int at[] = {0, 2, 0, 2, 5};
    int bt[] = {5, 3, 4, 3, 2};
    int pr[] = {1, 3, 4, 6, 3};
    int ct[MAX], wt[MAX], tat[MAX];
    int done[MAX];
    memset(done, 0, sizeof(done));

    int time = 0, completed = 0;
    while (completed < n) {
        int max_pr = -1, sel = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && pr[i] > max_pr) {
                max_pr = pr[i];
                sel    = i;
            }
        }
        if (sel == -1) { time++; continue; }
        ct[sel] = time + bt[sel];
        tat[sel] = ct[sel] - at[sel];
        wt[sel] = tat[sel] - bt[sel];
        time = ct[sel];
        done[sel] = 1;
        completed++;
    }

    printf("%-6s %-12s %-10s %-10s %-14s %-12s %-14s\n", "Proc", "ArrivalTime", "BurstTime", "Priority", "CompletionTime", "WaitingTime", "TurnaroundTime");
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("%-6s %-12d %-10d %-10d %-14d %-12d %-14d\n", name[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
        avg_wt  += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAvg Waiting Time     : %.2f\n", avg_wt / n);
    printf("Avg Turnaround Time  : %.2f\n", avg_tat / n);
}

int main() {
    priority_np();
    return 0;
}
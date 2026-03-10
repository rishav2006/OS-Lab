#include <stdio.h>
#include <string.h>

#define MAX 10

void sjf() {
    printf("Non-Preemptive SJF Scheduling ----------- \n");

    int n = 5;
    char name[MAX][5] = {"P0", "P1", "P2", "P3", "P4"};
    int at[] = {0, 1, 2, 4, 6};
    int bt[] = {5, 6, 3, 9, 4};
    int ct[MAX], wt[MAX], tat[MAX];
    int done[MAX];
    memset(done, 0, sizeof(done));

    int time = 0, completed = 0;
    while (completed < n) {
        int min_bt = 99999, sel = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                sel = i;
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

    printf("%-6s %-12s %-10s %-14s %-12s %-14s\n", "Proc", "ArrivalTime", "BurstTime", "CompletionTime", "WaitingTime", "TurnaroundTime");
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("%-6s %-12d %-10d %-14d %-12d %-14d\n", name[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt  += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAvg Waiting Time     : %.2f\n", avg_wt / n);
    printf("Avg Turnaround Time  : %.2f\n", avg_tat / n);
}

int main() {
    sjf();
    return 0;
}
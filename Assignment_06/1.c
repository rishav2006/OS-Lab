#include <stdio.h>
#include <string.h>

#define MAX 10

void fcfs() {
    printf("FCFS Scheduling ----------- \n");

    int n = 5;
    char name[MAX][5] = {"P0", "P1", "P2", "P3", "P4"};
    int at[] = {0, 1, 2, 4, 3};
    int bt[] = {2, 5, 7, 12, 6};
    int ct[MAX], wt[MAX], tat[MAX];
    int order[MAX];

    for (int i = 0; i < n; i++) order[i] = i;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[order[i]] > at[order[j]]) {
                int tmp = order[i]; order[i] = order[j]; order[j] = tmp;
            }
        }
    }

    int time = 0;
    for (int i = 0; i < n; i++) {
        int idx = order[i];
        if (time < at[idx]) time = at[idx];
        ct[idx] = time + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        time = ct[idx];
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
    fcfs();
    return 0;
}
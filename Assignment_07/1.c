#include <stdio.h>
#include <string.h>

#define MAX 10
#define INF 99999

void srtf() {
    printf("SRTF Scheduling ----------- \n");

    int n = 5;
    char name[MAX][5] = {"P0", "P1", "P2", "P3", "P4"};
    int at[] = {0, 2, 3, 2, 5};
    int bt[] = {5, 3, 4, 9, 2};
    int rem[MAX], ct[MAX], wt[MAX], tat[MAX], start[MAX];
    int done[MAX];
    memset(done, 0, sizeof(done));
    for (int i = 0; i < n; i++) { rem[i] = bt[i]; start[i] = -1; }

    int time = 0, completed = 0;
    while (completed < n) {
        int min_rem = INF, sel = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && rem[i] < min_rem) {
                min_rem = rem[i];
                sel = i;
            }
        }
        if (sel == -1) { time++; continue; }
        if (start[sel] == -1) start[sel] = time;
        rem[sel]--;
        time++;
        if (rem[sel] == 0) {
            ct[sel]  = time;
            tat[sel] = ct[sel] - at[sel];
            wt[sel]  = tat[sel] - bt[sel];
            done[sel] = 1;
            completed++;
        }
    }

    printf("%-6s %-12s %-10s %-14s %-12s %-14s\n", "Proc", "ArrivalTime", "BurstTime", "CompletionTime", "WaitingTime", "TurnaroundTime");
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("%-6s %-12d %-10d %-14d %-12d %-14d\n",
               name[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt  += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAvg Waiting Time     : %.2f\n", avg_wt / n);
    printf("Avg Turnaround Time  : %.2f\n", avg_tat / n);
}

int main() {
    srtf();
    return 0;
}
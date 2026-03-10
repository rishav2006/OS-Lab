#include <stdio.h>
#include <string.h>

#define MAX 10
#define INF 99999

void round_robin() {
    printf("Round Robin Scheduling (TQ = 2) ----------- \n");

    int n = 6;
    int tq = 2;
    char name[MAX][5] = {"P0", "P1", "P2", "P3", "P4", "P5"};
    int at[] = {0, 2, 0, 4, 6, 1};
    int bt[] = {10, 5, 4, 7, 2, 3};
    int rem[MAX], ct[MAX], wt[MAX], tat[MAX];
    int done[MAX];
    memset(done, 0, sizeof(done));
    for (int i = 0; i < n; i++) rem[i] = bt[i];

    int queue[MAX * 20], front = 0, rear = 0;
    int in_queue[MAX];
    memset(in_queue, 0, sizeof(in_queue));

    int time = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        if (at[i] == 0) { queue[rear++] = i; in_queue[i] = 1; }
    }

    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!done[i] && !in_queue[i] && at[i] <= time) {
                    queue[rear++] = i; in_queue[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        in_queue[idx] = 0;
        int exec = (rem[idx] < tq) ? rem[idx] : tq;
        time += exec;
        rem[idx] -= exec;

        for (int i = 0; i < n; i++) {
            if (!done[i] && !in_queue[i] && at[i] <= time && i != idx) {
                queue[rear++] = i; in_queue[i] = 1;
            }
        }

        if (rem[idx] == 0) {
            ct[idx]  = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx]  = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        } else {
            queue[rear++] = idx;
            in_queue[idx] = 1;
        }
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
    round_robin();
    return 0;
}
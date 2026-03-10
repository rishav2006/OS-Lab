#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void graph2() {
    printf("\n========================================\n");
    printf("  Graph 2: P1->P2->P3->{P4,P5,P6}\n");
    printf("========================================\n");

    printf("P1 executing (PID: %d)\n", getpid());
    printf("P1 executing (PID: %d)\n", getpid());

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2 executing (PID: %d)\n", getpid());
        printf("P2 executing (PID: %d)\n", getpid());

        pid_t p3 = fork();
        if (p3 == 0) {
            printf("P3 executing (PID: %d)\n", getpid());
            printf("P3 executing (PID: %d)\n", getpid());

            pid_t p4 = fork();
            if (p4 == 0) {
                printf("P4 executing (PID: %d)\n", getpid());
                printf("P4 executing (PID: %d)\n", getpid());
                _exit(0);
            }
            pid_t p5 = fork();
            if (p5 == 0) {
                printf("P5 executing (PID: %d)\n", getpid());
                printf("P5 executing (PID: %d)\n", getpid());
                _exit(0);
            }
            pid_t p6 = fork();
            if (p6 == 0) {
                printf("P6 executing (PID: %d)\n", getpid());
                printf("P6 executing (PID: %d)\n", getpid());
                _exit(0);
            }
            wait(NULL); wait(NULL); wait(NULL); /* P3 waits for P4, P5, P6 */
            _exit(0);
        }

        wait(NULL); /* P2 waits for P3 */
        _exit(0);
    }

    wait(NULL); /* P1 waits for P2 */
    printf("P1 finished.\n");
}

int main() {
    graph2();
    return 0;
}
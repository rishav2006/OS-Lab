#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void graph4() {
    printf("\n========================================\n");
    printf("  Graph 4: Diamond DAG\n");
    printf("  P1->{P2,P3}->P4->{P5,P6}->P7\n");
    printf("========================================\n");

    printf("P1 (PID: %d)\n", getpid());
    printf("P1 (PID: %d)\n", getpid());

    /* Fork P2 and P3 in parallel, then P4 runs after both */
    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2 (PID: %d)\n", getpid());
        printf("P2 (PID: %d)\n", getpid());
        _exit(0);
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        printf("P3 (PID: %d)\n", getpid());
        printf("P3 (PID: %d)\n", getpid());
        _exit(0);
    }

    wait(NULL); wait(NULL); /* P1 waits for P2 and P3 */

    pid_t p4 = fork();
    if (p4 == 0) {
        printf("P4 (PID: %d)\n", getpid());
        printf("P4 (PID: %d)\n", getpid());

        pid_t p5 = fork();
        if (p5 == 0) {
            printf("P5 (PID: %d)\n", getpid());
            printf("P5 (PID: %d)\n", getpid());
            _exit(0);
        }
        pid_t p6 = fork();
        if (p6 == 0) {
            printf("P6 (PID: %d)\n", getpid());
            printf("P6 (PID: %d)\n", getpid());
            _exit(0);
        }
        wait(NULL); wait(NULL); /* P4 waits for P5 and P6 */

        pid_t p7 = fork();
        if (p7 == 0) {
            printf("P7 (PID: %d)\n", getpid());
            printf("P7 (PID: %d)\n", getpid());
            _exit(0);
        }
        wait(NULL); /* P4 waits for P7 */
        _exit(0);
    }

    wait(NULL); /* P1 waits for P4 subtree */
    printf("P1 finished.\n");
}

int main() {
    graph4();
    return 0;
}
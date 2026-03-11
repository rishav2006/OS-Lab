#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void graph3() {
    printf("\n========================================\n");
    printf("  Graph 3: Complex Tree\n");
    printf("  P1->{P2->{P4->P7->P9, P5}, P3->P6->P8}\n");
    printf("========================================\n");

    printf("P1 (PID: %d)\n", getpid());

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2 (PID: %d)\n", getpid());

        pid_t p4 = fork();
        if (p4 == 0) {
            printf("P4 (PID: %d)\n", getpid());

            pid_t p7 = fork();
            if (p7 == 0) {
                printf("P7 (PID: %d)\n", getpid());

                pid_t p9 = fork();
                if (p9 == 0) {
                    printf("P9 (PID: %d)\n", getpid());
                    _exit(0);
                }
                wait(NULL);
                _exit(0);
            }
            wait(NULL); /* P4 waits for P7 */
            _exit(0);
        }

        pid_t p5 = fork();
        if (p5 == 0) {
            printf("P5 (PID: %d)\n", getpid());
            _exit(0);
        }

        wait(NULL); wait(NULL); /* P2 waits for P4 and P5 */
        _exit(0);
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        printf("P3 (PID: %d)\n", getpid());

        pid_t p6 = fork();
        if (p6 == 0) {
            printf("P6 (PID: %d)\n", getpid());

            pid_t p8 = fork();
            if (p8 == 0) {
                printf("P8 (PID: %d)\n", getpid());
                _exit(0);
            }
            wait(NULL); /* P6 waits for P8 */
            _exit(0);
        }

        wait(NULL); /* P3 waits for P6 */
        _exit(0);
    }

    wait(NULL); wait(NULL); /* P1 waits for P2 and P3 */
    printf("P1 finished.\n");
}

int main() {
    graph3();
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
void graph1() {
    printf("\n========================================\n");
    printf("  Graph 1: P1->P2->{P3->P5, P4}\n");
    printf("========================================\n");

    printf("P1 executing (PID: %d)\n", getpid());
    printf("P1 executing (PID: %d)\n", getpid());

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
        printf("P2 executing (PID: %d, Parent: %d)\n", getpid(), getppid());

        pid_t p3 = fork();
        if (p3 == 0) {
            printf("P3 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
            printf("P3 executing (PID: %d, Parent: %d)\n", getpid(), getppid());

            pid_t p5 = fork();
            if (p5 == 0) {
                printf("P5 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
                printf("P5 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
                _exit(0);
            }
            wait(NULL); /* P3 waits for P5 */
            _exit(0);
        }

        pid_t p4 = fork();
        if (p4 == 0) {
            printf("P4 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
            printf("P4 executing (PID: %d, Parent: %d)\n", getpid(), getppid());
            _exit(0);
        }

        wait(NULL); /* P2 waits for P3 */
        wait(NULL); /* P2 waits for P4 */
        _exit(0);
    }

    wait(NULL); /* P1 waits for P2 */
    printf("P1 finished.\n");
}

int main() {
    graph1();
    return 0;
}
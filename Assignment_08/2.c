#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void example_class() {
    printf("\n--- Class Example ---\n");
    printf("a\n");
    int a = getpid();
    fork();
    int b = getpid();
    printf("%d\n", b);
}

void graph2() {
    printf("Graph 2: Chain with Branch -----------\n");
    printf("P1 (PID: %d)\n", getpid());
    printf("P1 (PID: %d)\n", getpid());

    pid_t c1 = fork();
    if (c1 == 0) {
        /* P2 */
        printf("P2 (PID: %d)\n", getpid());
        printf("P2 (PID: %d)\n", getpid());

        pid_t c2 = fork();
        if (c2 == 0) {
            /* P3 - sibling branch */
            printf("P3 (PID: %d)\n", getpid());
            printf("P3 (PID: %d)\n", getpid());
            _exit(0);
        }
        pid_t c3 = fork();
        if (c3 == 0) {
            /* P4 */
            printf("P4 (PID: %d)\n", getpid());
            printf("P4 (PID: %d)\n", getpid());

            pid_t c4 = fork();
            if (c4 == 0) {
                /* P5 */
                printf("P5 (PID: %d)\n", getpid());
                printf("P5 (PID: %d)\n", getpid());
                _exit(0);
            }
            wait(NULL);
            _exit(0);
        }

        wait(NULL);
        wait(NULL);
        _exit(0);
    }

    wait(NULL);
    printf("P1 finished.\n");
}

int main() {
    example_class();
    wait(NULL); /* wait for children from example */

    graph2();
    return 0;
}
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

void graph1() {
    printf("Graph 1: Tree Precedence Graph -----------\n");

    pid_t pid1, pid2;
    printf("Root PID: %d\n", getpid());
    printf("Root PID: %d\n", getpid());

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child1 PID: %d\n", getpid());
        printf("Child1 PID: %d\n", getpid());

        pid_t pid3 = fork();
        if (pid3 == 0) {
            printf("GrandChild PID: %d\n", getpid());
            printf("GrandChild PID: %d\n", getpid());
            _exit(0);
        }
        wait(NULL);
        _exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Child2 PID: %d\n", getpid());
        printf("Child2 PID: %d\n", getpid());
        _exit(0);
    }

    wait(NULL);
    wait(NULL);
    printf("Root finished.\n");
}

int main() {
    example_class();
    wait(NULL); /* wait for children from example */

    graph1();
    return 0;
}
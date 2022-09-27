#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    pid_t pid = 1;
    clock_t start = clock();
    for (int i = 0; i < 2; i++) {
        if (pid > 0) {
            if (!(pid = fork())) {
                start = clock();
            }

        }
    }
    while(wait(0)>0);
    printf("I'm the process with ID: %i, my parent has ID: %i, and my execution time is %ld milliseconds.\n\n",
            getpid(), getppid(), clock() - start);
}

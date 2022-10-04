#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buf;

    if (pipe(pipefd) == -1) {
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]);

        char message[1024];
        read(pipefd[0], message, 1024);
        printf("The message received by subscriber (pid = %i):\n", getpid());
        printf("%s", message);

        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[0]);

        printf("Enter a message to be sent by publisher (pid = %i):\n", getpid());
        char message[1024];
        fgets(message, 1024, stdin);

        write(pipefd[1], message, 1024);

        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}

// pipe reference
// https://man7.org/linux/man-pages/man2/pipe.2.html

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

char PIPENAME[] = "/tmp/ex1";
const int BUFSIZE = 1024;

int main(int argc, char* argv[]) {
    printf("Hello, I'm publisher. Provide messages line by line here:\n");
    int pipefd;
    char message[BUFSIZE];
    int n = atoi(argv[1]);

    mkfifo(PIPENAME, 0666);
    while(1) {
        pipefd = open(PIPENAME, O_WRONLY);

        fgets(message, BUFSIZE, stdin);
        for (int i = 0; i < n; i++) {
            write(pipefd, message, BUFSIZE);
        }

        close(pipefd);
    }

    return EXIT_SUCCESS;
}

// mkfifo reference
// https://man7.org/linux/man-pages/man3/mkfifo.3.html

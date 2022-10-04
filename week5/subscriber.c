#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

const char PIPENAME[] = "/tmp/ex1";
const int BUFSIZE = 1024;

int main() {
    printf("Hello, I'm subscriber. I will recieve messages from publisher and write them here:\n");
    int pipefd;
    char message[BUFSIZE];

    while (1) {
        if ( (pipefd = open(PIPENAME, O_RDONLY) ) <= 0) {
            continue;
        }
        sleep(1);
        read(pipefd, message, BUFSIZE);
        printf("%s", message);

        close(pipefd);
    }

    return EXIT_SUCCESS;
}

// mkfifo reference
// https://man7.org/linux/man-pages/man3/mkfifo.3.html

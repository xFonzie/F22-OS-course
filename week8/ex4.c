#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
    int* ptrs[11];
    for (int i = 1; i <= 10; i++) {
        int* ptr = malloc(10 * 1024 * 1024);
        ptrs[i] = ptr;
        memset(ptr, 0, 10 * 1024 * 1024);

        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);

        printf("%lu\n", usage.ru_maxrss);
        fflush(stdin);

        sleep(1);
    }

    for (int i = 1; i <= 10; i++) {
        free(ptrs[i]);
    }
}

#include <stdio.h>
#include <sys/dir.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    DIR *dir = opendir("/");
    struct dirent *file;
    while ((file = readdir(dir)) != NULL) {
        printf("%s\n", file->d_name);
    }
    (void) closedir(dir);
    return 0;
}

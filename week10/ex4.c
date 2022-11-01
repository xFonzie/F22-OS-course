#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <string.h>

void print_files_with_ino(ino_t ino) {
    DIR* dir = opendir("./tmp");

    struct dirent* file;
    while ((file = readdir(dir)) != NULL) {
        if (file->d_ino == ino) {
            printf("%s, ", file->d_name);
        }
    }
    closedir(dir);
}

int main() {
    DIR* dir = opendir("./tmp");
    char path[256] = "./tmp/";
    struct stat buf;
    struct dirent* file;
    while ((file = readdir(dir)) != NULL) {
        stat(strcat(path, file->d_name), &buf);
        if (file->d_type == DT_REG && buf.st_nlink >= 2) {
            printf("%s - ", file->d_name);
            print_files_with_ino(buf.st_ino);
            printf("\n");
        }
        strcpy(path, "./tmp/");
    }
    closedir(dir);
}

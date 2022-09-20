#include <stdio.h>
#include <string.h>

struct File;
struct Directory;

struct File {
    int id;
    char name[64];
    struct Directory* parent;
    char data[1024];
    unsigned int size;
};

struct Directory {
    int nf;
    int nd;
    char path[2048];
    struct File* files[256];
    struct Directory* directories[8];
};

typedef struct File File;
typedef struct Directory Directory;

void add_to_file(File* file, const char* str) {
    if (file) {
        strcpy(file->data, str);
        file->size = sizeof(char) * strlen(file->data);
    }

}

void append_to_file(File* file, const char* str) {
    strcat(file->data, str);
    file->size = sizeof(char) * strlen(file->data);
}

void pwd_file(File* file) {
    char path[2048];
    strcpy(path, file->parent->path);
    strcat(path, file->name);
    printf("%s\n", path);
}

void add_file(File* file, Directory* dir) {
    if (file && dir) {
        dir->files[dir->nf++] = file;
        file->parent = dir;
    }
}

void add_dir(Directory* dir1, Directory* dir2) {
    if (dir1 && dir2) {
        dir2->directories[dir2->nd++] = dir1;
    }
}

void pwd(Directory* source) {
    for (int i = 0; i < source->nf; i++) {
        pwd_file(source->files[i]);
    }

    for (int i = 0; i < source->nd; i++) {
        pwd(source->directories[i]);
    }
}

int main() {
    Directory root = {0, 0, "/"};
    Directory home = {0, 0, "/home/"};
    Directory bin = {0, 0, "/bin/"};

    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash = {rand(), "bash"};
    add_file(&bash, &bin);

    File ex3_1c = {rand(), "ex3_1.c"};
    add_file(&ex3_1c, &home);
    add_to_file(&ex3_1c, "int printf(const char * format, ...);");

    File ex3_2c = {rand(), "ex3_2.c"};
    add_file(&ex3_2c, &home);
    add_to_file(&ex3_2c, "//This is a comment in C language");

    add_to_file(&bash, "Bourne Again Shell!!");

    append_to_file(&ex3_1c, "int main(){printf(\"Hello, World!\")}");

    pwd(&root);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[1024] = "";
    while(strcmp(command, "exit\n")) {
        printf(">");
        fgets(command, 1024, stdin);
        system(command);
    }
    return 0;
}

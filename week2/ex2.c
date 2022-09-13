#include <stdio.h>
#include <string.h>

int main() {
    printf("Please, provide the string below (maximum 256 characters):");
    char str[257]; str[0] = 0;
    char current = 0;
    while (current != '.' && current != '\n') {
        str[strlen(str) + 1] = 0;
        str[strlen(str)] = current;
        current = getchar();
    }

    for (int i = strlen(str); i > 0; i--) {
        printf("%c", str[i - 1]);
    }
}

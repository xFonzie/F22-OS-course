#include <stdio.h>
#include <string.h>

void printTriangle(int n) {
    char str[256] = "*";
    int i = 1;
    while (i <= n) {
        printf("%s\n", str);
        str[i++] = '*';
        str[i] = '\0';
    }
}

void printPyramid(int n) {
    n--; // honestly, idk why, but with this it works :0
    char str[256] = "*";
    int i = 1;
    while (i <= n / 2) {
        printf("%s\n", str);
        str[i++] = '*';
        str[i] = '\0';
    }
    if (n % 2)
        printf("%s\n", str);
    while (i-- > 0) {
        printf("%s\n", str);
        str[i] = '\0';
    }
}

void printSquare(int n) {
    char str[256] = "";
    for (int i = 0; i < n; i++) {
        str[i] = '*';
        str[i+1] = '\0';
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", str);
    }
}

int main() {
    printTriangle(7);
    printPyramid(7);
    printSquare(7);
}

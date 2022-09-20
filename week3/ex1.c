#include <stdio.h>
#include <stdlib.h>

int foo(int age) {
    return 2022 - age;
}

int main() {
    const int x = 10;
    const int *q = &x;

    const int const *p = (const int *) malloc(sizeof(const int) * 5);
    for (int i = 0 ; i < 5 ; i++) {
        int * temp = p + i;
        *temp = x;
        printf("%p\n", temp);
    }
    printf("\nProvide the ages of 5 users (positive integer values):\n");
    for (int i = 0 ; i < 5 ; i++) {
        int * temp = p + i;
        scanf("%i", temp);
    }

    for (int i = 0 ; i < 5 ; i++) {
        int * temp = p + i;
        *temp = foo(*temp);
    }

    free(p);
}

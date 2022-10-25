#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Please, provide number N:\n");
    scanf("%i", &n);
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = i;

    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    free(arr);
}

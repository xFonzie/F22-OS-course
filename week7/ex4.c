#include<stdlib.h>
#include<string.h>

void* my_realloc(void* ptr, unsigned int size) {

    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

int main() {
    // some testing code
    int* arr = my_realloc(NULL, sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n%i\n", sizeof(arr));

    arr = my_realloc(arr, sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n%i\n", sizeof(arr));
}

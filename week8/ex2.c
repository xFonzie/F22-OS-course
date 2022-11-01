#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

//
// Ex 2:
// According to the results I get from vmstat, amount of free memory
// decreases with each allocation and other parts of results are not really affected.
// When the program frees the pointers, the free memory comes to initial values.
//
// si and so fields remains 0 along the execution of the program, since my VM have enough
// RAM to perform allocations with no pages writing to disk.
//
//
// Ex 3:
// Before execution of the programm my VM had 180MB of free memory and every second this number
// decreases by 10MB while program is running. After the freeing pointers, free memory comes
// back to its initial value.
// %CPU did not exceed 1% for ex2 process.
//


int main() {
    int* ptrs[11];
    for (int i = 1; i <= 10; i++) {
        int* ptr = malloc(10 * 1024 * 1024);
        ptrs[i] = ptr;
        memset(ptr, 0, 10 * 1024 * 1024);
        sleep(1);
    }

    for (int i = 1; i <= 10; i++) {
        free(ptrs[i]);
    }
}

#include <stdio.h>

long long T(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    long long t1 = 0, t2 = 1, t3 = 1;
    while (n >= 3) {
        int sum = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = sum;
        n--;
    }
    return t3;
}

int main() {
    printf("4th number in trinbonacci sequence:\n%lli\n", T(4));
    printf("36th number in trinbonacci sequence:\n%lli\n", T(36));
}

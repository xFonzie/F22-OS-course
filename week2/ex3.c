#include <stdio.h>
#include <string.h>

int validate(long long n, int from, int to) {
    if (2 > from || from > 10)
        return 0;
    if (2 > to || to > 10)
        return 0;
    if (n < 0)
        return 0;
    return 1;
}

void convert(long long n, int from, int to) {
    if (!validate(n, from, to)) {
        printf("cannot convert!");
        return;
    }

    long long dec = 0, factor = 1;
    while (n > 0) {
        dec += factor * (n % 10);
        factor *= from;
        n /= 10;
    }

    char result[65] = ""; // maximum length of number is when we convert from decimal to binary
    int i = 0;
    while (dec > 0) {
        result[i++] = dec % to + '0';
        result[i] = '\0';
        dec /= to;
    }

    // reverse result
    int j = 0;
    while (j < i--) {
        char buf = result[j];
        result[j++] = result[i];
        result[i] = buf;
    }
    printf("%s", result);
}



int main() {
    long long n, s, t;
    printf("Please, provide a long long number to convert:\n");
    scanf("%lli", &n);
    printf("Please, provide a numeral system to convert from:\n");
    scanf("%lli", &s);
    printf("Please, provide a numeral system to convert to:\n");
    scanf("%lli", &t);

    printf("\nThe result of convertion:\n");
    convert(n, s, t);
}

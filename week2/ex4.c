#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count(char str[], char ch) {
    int k = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ch)
            k++;
    return k;
}

void countAll(char str[]) {
    int commaNeeded = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (commaNeeded)
            printf(", ");
        printf("%c:%i", str[i], count(str, str[i]));
        commaNeeded = 1;
    }
}

int main() {
    char input[257] = "Innopolis";

    printf("Please, provide the string:\n");
    scanf("%s", input);

    // lowercase the string to make program case-insensetive
    for (int i = 0; i < strlen(input); i++)
        input[i] = tolower(input[i]);

    countAll(input);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isVowel(char c) {
    c = tolower(c); // convert to lowercase
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverseVowels(char str[]) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        while (i < j && !isVowel(str[i])) i++;
        while (i < j && !isVowel(str[j])) j--;

        if (i < j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
}

int main() {
    char str[1001]; // max length 1000

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline if present

    reverseVowels(str);

    printf("String after reversing vowels: %s\n", str);

    return 0;
}


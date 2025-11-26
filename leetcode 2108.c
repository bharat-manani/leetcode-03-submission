#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int n;
    int i,j;
    printf("Enter number of words: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    char **words = malloc(n * sizeof(char *));
    if (!words) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char buffer[1001];

    printf("Enter %d words (one per line):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%1000s", buffer);
        
        words[i] = malloc(strlen(buffer) + 1);
        if (!words[i]) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(words[i], buffer);
    }

    for ( i = 0; i < n; i++) {
        if (isPalindrome(words[i])) {
            printf("First palindromic string: %s\n", words[i]);
            for ( j = 0; j < n; j++) free(words[j]);
            free(words);
            return 0;
        }
    }

    
    printf("No palindromic string found (\"\")\n");

    for ( j = 0; j < n; j++) free(words[j]);
    free(words);

    return 0;
}


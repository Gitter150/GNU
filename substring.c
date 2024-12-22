#include <stdio.h>
#include <string.h>

int main() {
    char s[50], str[25];
    int len1, len2, found = 0;

    printf("Enter the string:\n");
    fgets(s, 50, stdin);
    printf("Enter the substring:\n");
    fgets(str, 25, stdin);

    // Remove trailing newline characters, if present
    s[strcspn(s, "\n")] = '\0';
    str[strcspn(str, "\n")] = '\0';

    len1 = strlen(s);
    len2 = strlen(str);

    // Substring search
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (s[i + j] != str[j]) {
                break;
            }
        }
        if (j == len2) { // Substring found
            found = 1;
            printf("Substring found at index %d\n", i);
            break;
        }
    }

    if (!found) {
        printf("Substring is not found\n");
    }

    return 0;
}

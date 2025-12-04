#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[200];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    char *word_start = str;
    for (int i = 0; ; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(word_start, &str[i - 1]);
            if (str[i] == '\0') break;
            word_start = &str[i + 1];
        }
    }

    printf("Reversed words: %s\n", str);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    int len = strlen(name), last_space = -1;
    for (int i = 0; i < len; i++) {
        if (name[i] == ' ')
            last_space = i;
    }

    for (int i = 0; i < len; i++) {
        if (i == 0 || (name[i - 1] == ' ' && i < last_space))
            printf("%c. ", toupper(name[i]));
        else if (i > last_space) {
            printf("%c", name[i]);
        }
    }
    printf("\n");
    return 0;
}

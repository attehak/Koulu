#include <stdio.h>
#include <string.h>

#define max_len 256

int replace_char(char*str, const char *repl);

int main () {
    char str[max_len];
    char repl[3];
    int count = 0;

    printf("Enter your text\n");
    fgets(str, max_len, stdin);
    printf("Enter two characters, the first one is what to replace and the second is what to replace it to\n");
    fgets(repl, 3, stdin);

    count = replace_char(str, repl);

    printf("%s\n", str);

    if (count == 0) {
        printf("String was not modified\n");
    } else if (count == 1) {
        printf("%d character modified\n", count); // character
    } else if (count > 1) {
        printf("%d characters modified\n", count); // characterS<-
    }

}

int replace_char(char*str, const char *repl) {
    int count = 0;

    if (strlen(repl) < 2) {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == repl[0]) {
            str[i] = repl[1];
            count++;
        }
    }
    return count;
}

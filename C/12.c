#include <stdio.h>
#include <string.h>

#define max_len 256

int count_words(const char* str, const char* word);
void string_cleaner(char* word);

void main() {
    char str[max_len];
    char word[max_len];
    int count = 0;

    do {
        printf("Enter your text: \n");
        fgets(str, max_len, stdin);
        printf("Enter a word: \n");
        fgets(word, max_len, stdin);

        string_cleaner(word);

        count = count_words(str, word);

        printf("\nThe word appears %d times in the text.\n", count);
    } while (strcmp(word, "stop") != 0);

    printf("\nSad to see you go..\n");

}

int count_words(const char* str, const char* word) {
    int count = 0;

    const char *ptr = str;
    int word_len = strlen(word);

    if (word_len == 0) {
        return 0;
    }

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += word_len;
    }

    return count;
}

void string_cleaner(char* word) {
    int size = strlen(word);

    if (size > 0 && word[size - 1] == '\n') {
        word[size - 1] = '\0';
    }
}

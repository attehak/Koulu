#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool generate_password(char *password, int size, const char *word, int goofy);

int main () {
    char word[32];
    char password[128];
    int goofy = 0;

    srand(time(NULL));

    printf("Enter a word to place in the password or enter 'stop' to stop the program:\n");

    do {
        fgets(word, sizeof(word), stdin);

        if (strlen(word) == 1) {
            printf("Please input something\n");
            goofy = 1;
        } else {
            word[strcspn(word, "\n")] = '\0';

            if (strcmp(word, "stop") == 0) {
                exit(1);
            }
            if (generate_password(password, sizeof(password), word, goofy)) {
                printf("Password: %s\n", password);
            } else {
                printf("Password does not fit in the array\n");
            }
            printf("Enter a word to place in the password or enter 'stop' to stop the program:\n");
        }
    } while (strcmp(word, "stop") != 0);
}

bool generate_password(char *password, int size, const char *word, int goofy) {

    int word_lenght = strlen(word);
    int password_lenght = word_lenght * 2 + 1;

    // jos input on something sen jälkeen kun on printattu "... input something"
    if (goofy == 1 && strcmp(word, "something") == 0) {
        printf("ahaha funny guy\n\n");
    }
    if (password_lenght + 1 > size) {
        return false;
    }
    for (int i = 0; i < password_lenght; i++) {
        if (i % 2 == 0) {
            password[i] = (rand() % 95) +33;
        } else {
            password[i] = word[i / 2];
        }
    }
    password[password_lenght] = '\0';
    return true;
}

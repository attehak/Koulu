#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char menu(void);
int roll6(void);
int roll10(void);

int main() {
    srand(time(NULL));
    char input;

    printf("Welcome to the dice program\n");
    while (input != 'C') {
        input = menu();

        if (input == 'A') {
            roll6();
        }
        else if (input == 'B') {
            roll10();
        }
        else if (input == 'C') {
            printf("Sad to see you go..");
        }
    }
}

char menu(void) {
    char input;
    printf("\nA) Roll D6\n");
    printf("B) Roll D10\n");
    printf("C) Quit\n");

    do {
        printf("Please select one of the options (A, B, C): ");
        if (scanf(" %c", &input) != 1) {
            while (getchar() != '\n');
            printf("Invalid input\n");
        }

        while (getchar() != '\n');

        if (input == 'a' || input == 'b' || input == 'c') {
            input -= 32;
        }
        if (input != 'A' && input != 'B' && input != 'C') {
            printf("Invalid input\n");
        }

    } while (input != 'A' && input != 'B' && input != 'C');

    return input;
}

int roll6(void) {
    int roll = rand() % 6 + 1;
    printf("You rolled a %d!\n\n\n", roll);
    return;
}
int roll10(void) {
    int roll = rand() % 10 + 1;
    printf("You rolled a %d!\n\n\n", roll);
    return;
}

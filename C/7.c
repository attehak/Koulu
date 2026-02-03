#include <stdio.h>
#include <stdbool.h>


bool read_positive(int *value);

int main () {
    int i = 0;
    int value = 0;
    do {
        bool answer = read_positive(&value);
        if (answer == true) {
            int money = value * 2 + 20;
            printf("You didn't get it right. I have %d euros.", money);
        }
        else if (answer == false) {
            i++;
        }
    } while (i < 3);

    printf("I give up! See you later!");
}

bool read_positive(int *value) {
    bool anwser;

    printf("Guess how much money i have!\n");
    printf("Enter a positive number:  ");

    if (scanf(" %d", value) != 1) {
        while (getchar() != '\n');
        printf("Incorrect input input\n");
        anwser = false;
    }
    if (*value <= 0) {
        anwser = false;
    } else if (*value > 0) {
        anwser = true;
    }

    return anwser;
}

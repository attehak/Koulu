#include <stdio.h>

int read_range(int low, int high);

int main () {
    int low = 1;
    int high = 6;
    int i = 0;
    printf("Let's play!\n");
    while (i < 3) {
        int roll = 0;
        printf("Roll a die and enter your result.\n");
        int result = read_range(low, high);
        if (result < high) {
            roll = result + 1;
            printf("I got %d. I win!\n", roll);
            i++;
        }
        else if (result == high) {
            printf("I also got %d. Its a tie!\n", result);
            i++;
        }
    }
    printf("Better luck next time!\n");
}

int read_range(int low, int high) {
    int input = 0;
    do {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &input) != 1) {
            while (getchar() != '\n');
            printf("Invalid input\n");
            input = 0;
        }
        else if (input < low) {
            printf("The number given is too low\n");
        }
        else if (input > high) {
            printf("The number given is too high\n");
        }
    } while (input < low || input > high);

    return input;
}

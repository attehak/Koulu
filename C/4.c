#include <stdio.h>

int read_integer(void);

int main() {
    int input = 0;
    int reps = 0;
    double average = 0;
    int sum = 0;
    do {
        input = read_integer();
        if (input >= 0) {
            reps++;
            sum += input;
        }
    } while (input >= 0);

    average = (double)sum / reps;
    printf("You entered %d positive numbers. The average is: %.3f", reps, average);
}

int read_integer(void) {
    int input;
    do {
        printf("Enter positive numbers or negative to stop: ");
        if (scanf("%d", &input) != 1) {
            while (getchar() != '\n');
            printf("Invalid input.\n");
        }
    } while (input == 0);
    return input;
}

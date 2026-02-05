#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define array_max 20
#define number_max 20
#define number_min 1

int find_first(const unsigned int *array, unsigned int what);

int main() {
    srand(time(NULL));
    unsigned int array[array_max];

    for (int i = 0; i < array_max - 1; i++) { // antaa arrayn kaikkiin paitsi viimeisimpään slottiin satunnaisen arvon
        int number = rand() % number_max + number_min;
        array[i] = number;
    }

    array[array_max - 1] = 0;

    for (int i = 0; i < array_max; i++) { // printtaa arrayn
        printf("%2d\n", array[i]);
    }

    int input = 0;
    int output = 0;

    do {
        printf("Enter a number between %d and %d or 0 to stop: ", number_min, number_max);

        if (scanf("%d", &input) != 1) { // input validaatio
            while (getchar() != '\n');
            printf("Invalid input\n");
            input = -1;
        }

        else if (input < 0 || input > number_max) { // antaa error viestin jos syöte ei parametrien sisällä
            printf("Invalid input\n");
        }

        if (input >= number_min && input <= number_max) { // jos on niin yrittää etsiä numeroa
            output = find_first(array, input);
            if (output != -1) { // jos löytyy niin antaa sijainnin
                printf("The location of the number is array[%d].\n", output);
            }
            else { // ja jos ei
                printf("Number not found in array.\n");
            }
        }

    } while (input != 0);

    printf("Bye!\n");
}

int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;
    while (array[i] != 0) { // tekee kunnes vastaan tulee 0
        if (array[i] == what) { // jos löytyy niin palauttaa
            return i;
        }
        i++;
    }
    return -1; // jos ei tullut vastaan
}

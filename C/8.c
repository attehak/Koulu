#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define array_max 15

void print_numbers(const int *array, int count);

int main() {
    srand(time(NULL));
    int array[array_max];
    for (int i = 0; i < array_max; i++) {
        int number = rand();
        array[i] = number;
    }
    print_numbers(array, array_max);
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}

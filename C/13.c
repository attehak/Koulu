#include <stdio.h>
#include <stdlib.h>

#define max 256

int main() {
    FILE *file;
    char filename[256];
    int egers[max]; // int egers integers ghhheeheheh
    int amount_of_numbers = 0;


    printf("Enter filename: ");
    scanf("%255s", filename);

    // avaa tiedosto
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", filename);
        exit(1);
    }

    // lukee
    while (amount_of_numbers < max && fscanf(file, "%d", &egers[amount_of_numbers]) == 1) {
        amount_of_numbers++;
    }

    // jos ei oo numeroit ni sulkee ettei mee jumii ja sillai
    if (amount_of_numbers == 0) {
        printf("No numbers were found\n");
        fclose(file);
        exit(1);
    }

    int biggest = egers[0];
    int smallest = egers[0];

    // löytää isoimma ja pienimmä
    for (int i = 0; i < amount_of_numbers; i++) {
        if (smallest > egers[i]) {
            smallest = egers[i];
        }
        if (biggest < egers[i]) {
            biggest = egers[i];
        }
    }
    
    printf("Number of numbers: %d\n", amount_of_numbers);
    printf("Smallest number: %d\n", smallest);
    printf("Biggest number: %d\n", biggest);

    fclose(file);
}

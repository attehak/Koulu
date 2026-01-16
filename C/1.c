#include <stdio.h>


int main(void) {
    float bussilippu = 0;
    float taxilippu = 0;
    float saldo = 0;
    int valinta = 0;

    printf("Give me the price of a bus ticket: ");
    scanf("%f", &bussilippu);
    printf("Give me the price of a taxi: ");
    scanf("%f", &taxilippu);
    printf("How much money you got? ");
    scanf("%f", &saldo);
    printf("Aight you got %.2f EUR\n", saldo);
    while(saldo > bussilippu || saldo > taxilippu) {
        printf("\nYou wanna take a bus or a cab?\n");
        printf("(1) Bus (%.2f EUR)\n", bussilippu);
        printf("(2) Taxi (%.2f EUR)\n", taxilippu);
        printf("Which one? ");
        scanf("%d", &valinta);
        if (valinta == 1) {
            printf("You chose the bus\n");
            if (saldo > bussilippu) {
                saldo -= bussilippu;
                printf("You now have %.2f EUR left\n", saldo);
            }
            else
                printf("Too bad you can't afford it\n");
        }
        else if (valinta == 2) {
            printf("You chose the taxi\n");
            if (saldo > taxilippu) {
                saldo -= taxilippu;
                printf("You now have %.2f EUR left\n", saldo);
            }
            else
                printf("Too bad you can't afford it\n");
        }


    }
    printf("You can't afford either bum");

}

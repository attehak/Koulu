#include <stdio.h>

int main(void) {
    float brutto[12];
    float vero[12];
    float veroprosentti = 0;
    float tuloraja = 0;
    float lisavero = 0;
    float todveroprosenti = 0;
    float todlisavero = 0;
    float tulot = 0;

    printf("Enter tax rate: ");
    scanf("%f",&veroprosentti);
    printf("Enter income limit: ");
    scanf("%f",&tuloraja);
    printf("enter tax rate for income over the limit:");
    scanf("%f",&lisavero);


    for (int i = 0; i < 12; i++) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &brutto[i]);
    }

    todveroprosenti = veroprosentti / 100.0f;
    todlisavero = lisavero / 100.0f;

    for (int i = 0; i < 12; i++) {
        float normivero = brutto[i];
        float extravero = 0;

        if (tulot < tuloraja && tulot + brutto[i] > tuloraja) {
            normivero = tuloraja - tulot;
            extravero = brutto[i] - normivero;
        } else if (tulot >= tuloraja) {
            normivero = 0;
            extravero = brutto[i];
        }

        vero[i] = normivero * todveroprosenti +
                  extravero * todlisavero;

        tulot += brutto[i];
    }

    printf("%0s %10s %10s\n", "Month", "Income", "Tax");
    for (int i = 0; i < 12; i++) {
        printf("%5.2d %10.2f %10.2f\n", i + 1, brutto[i], vero[i]);
    }

}

#include <stdio.h>

int main(void) {
    int a = 0;
    int vastaus1 = 0;
    int vastaus2 = 0;

    printf("How many students? ");
    scanf("%d", &a);

    int grade[a];
    for (int i = 0; i < a; i++) {
        grade[i] = -1;
    }

    printf("Enter student number (1 - %d) or 0 to stop: ", a);
    scanf("%d", &vastaus1);
    while (vastaus1 != 0) {
        if (vastaus1 > a) {
            printf("Invalid student number!\n");
        }
        else {
            printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", vastaus1 );
            scanf("%d", &vastaus2);
            if (vastaus2 > 5) {
                printf("Invalid grade!");
            }
            else if (vastaus2 != -1) {
                grade[vastaus1 - 1] = vastaus2;
            }
        }
        printf("\nEnter student number (1 - %d) or 0 to stop: ", a);
        scanf("%d", &vastaus1);
    }
    printf("%s %10s\n", "Student", "Grade");
    for (int i = 0; i < a; i++) {
        if (grade[i] == -1) {
            printf("%d %14s\n", i + 1, "N/A");
        } else {
            printf("%d %12d\n", i + 1, grade[i]);
        }
    }

}

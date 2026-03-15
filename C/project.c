#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subject_data {
    char subject[256];
    int score;
    char score_prcnt[6]; // sama ku score mut numeron jälkee tulee %-merkki
    int grade;
};

int main() {
    FILE *file = fopen("grades.txt", "a");
    char name[100];
    int amount = 0;
    char str[256];
    int check = 0;
    int avarage = 0;

    if (file == NULL) {
        printf("\nError reading/creating file.\n");
        return 0;
    }


    printf("\n\nWelcome to the Student Grade Calculator!\n");
    printf("Please enter your name: ");

    // Ottaa nimen ja jos kenttä on tyhjä kysyy nimeä uudestaan
    do {
        fgets(name, sizeof(name), stdin);
        if (strlen(name) == 1) {
            printf("\nYour name cannot be blank. Please enter your name:");
        }
    } while (strcmp(name, "\n") == 0);

    // Ottaa numeron eikä hyväksy tyhjää kenttää, kirjaimia, nollaa tai negatiivisia numeroita
    printf("\nHow many subject do you want to calculate grades for? ");
    do {
        fgets(str, sizeof(str), stdin);
        if (sscanf(str, "%d", &amount) != 1) {
            printf("\nInvalid input. Please enter the number of subjects: ");
        } else if (amount <= 0) {
            printf("\nPlease enter atleast one subject: ");
        } else {
            check = 1;
        }
        } while (check == 0);

    // Tehdään x monta structia
    struct subject_data data[amount];

    // Käydään lisäämässä tiedot jokaiseen structiin
    for (int i = 0; i < amount; i++) {

        printf("\n\nEnter subject %d name: ", i + 1);

        // Lisää aineen nimen
        do {
            fgets(data[i].subject, sizeof(data[i].subject), stdin);
            if (strlen(data[i].subject) == 1) {
                printf("\nSubject name cannot be blank. Please enter a subject name: ");
            }
        } while (strcmp(data[i].subject, "\n") == 0);

        check = 0;
        printf("\nEnter your score for %s (0-100): ", data[i].subject);

        // Lisää scoren (%)
        do {
            fgets(str, sizeof(str), stdin);
            if (sscanf(str, "%d", &data[i].score) != 1) {
                printf("\nInvalid input. Please enter the score for %s: ", data[i].subject);
            } else if (data[i].score < 0) {
                printf("\nThe score must be over 0: ");
            }else if (data[i].score > 100) {
                printf("\nThe score must be less than 100: ");
            } else {
                check = 1;
            }
        } while (check == 0);

        // Jos score on alle 50 niin arvosana on 0 tai jos 100 == 5 tai jos yli 50 niin arvosana on score / 10 - 4
        data[i].grade = data[i].score < 50 ? 0 :
                        data[i].score == 100 ? 5 :
                        data[i].score / 10 - 4;

        // Jos koittaa printtaa suoraa sen data[i].score:n nii se prosentti merkki kusee ja menee tosi pitkälle. Tälle sen näyttää hienolta
        snprintf(data[i].score_prcnt, sizeof(data[i].score_prcnt), "%d%%", data[i].score);
    }
    printf("\n------------------------------------------\n");
    fprintf(file, "\n------------------------------------------\n");

    printf("Student: %s", name);
    fprintf(file, "Student: %s", name);

    printf("------------------------------------------\n");
    fprintf(file, "------------------------------------------\n");

    printf("%-26s %-8s %-10s\n", "Subject", "Score", "Grade");
    fprintf(file, "%-26s %-8s %-10s\n", "Subject", "Score", "Grade");

    printf("------------------------------------------\n");
    fprintf(file, "------------------------------------------\n");

    for (int i = 0; i < amount; i++) {
        data[i].subject[strcspn(data[i].subject, "\n")] = '\0';

        printf("%-26s %-8s %-10d\n", data[i].subject, data[i].score_prcnt, data[i].grade);
        fprintf(file, "%-26s %-8s %-10d\n", data[i].subject, data[i].score_prcnt, data[i].grade);

        avarage += data[i].grade;
    }
    printf("\nAverage grade: %.2f\n", (double)avarage / amount);
    fprintf(file, "\nAverage grade: %.2f\n", (double)avarage / amount);

    printf("------------------------------------------\n");
    fprintf(file, "------------------------------------------\n");
    getchar(); // jos ajaa .exe:n niin ohjelma sulkeutuu vasta kun painaa jotain. Muuten ei ehtisi lukea taulukkoa
}

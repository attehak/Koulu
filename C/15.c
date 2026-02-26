#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 40
#define MAX_NAME 256
#define LINE_LEN 256

typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;

// trimmaa välit
void trim_fat(char *s);

int main(void) {
    menu_item items[MAX_ITEMS];
    char filename[100];
    char line[LINE_LEN];
    int count = 0;
    FILE *file;

    printf("Enter filename: ");
    scanf("%255s", filename);

    // avaa tiedosto
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", filename);
    }

    // jakaa tekstin kahtee osaa ja trimmaa ja kopioi yms
    while (count < MAX_ITEMS && fgets(line, sizeof(line), file) != NULL) {
        char *name_part = strtok(line, ";");
        char *price_part = strtok(NULL, ";");

        trim_fat(name_part);
        trim_fat(price_part);

        strncpy(items[count].name, name_part, MAX_NAME - 1);
        items[count].name[MAX_NAME - 1] = '\0';
        items[count].price = atof(price_part);

        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("%8.2f  %s\n", items[i].price, items[i].name);
    }
}

void trim_fat(char *s){
    char *end;

    while (isspace((unsigned char)*s)) {
        s++;
    }

    if (*s == 0) {
        *s = '\0';
        return;
    }

    end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define LINE_SIZE 80

int main() {
    FILE *file;
    char filename[256];
    char lines[MAX_LINES][LINE_SIZE + 1];
    int line_count = 0;
    int i, j;

    printf("Enter filename: ");
    scanf("%255s", filename);

    // avaa tiedosto
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", filename);
    }

    // lukee tekstin arrayhin
    while (line_count < MAX_LINES && fgets(lines[line_count], LINE_SIZE + 1, file) != NULL) {
        line_count++;
           }

    fclose(file);

    // muuntaa isoiks kirjaimiks
    for (i = 0; i < line_count; i++) {
        for (j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = (char)toupper((unsigned char)lines[i][j]);
        }
    }

    // avaa tiedoston
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s' for writing\n", filename);
    }

    // kirjottaa tekstin
    for (i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

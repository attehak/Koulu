#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

int main() {
    nnode *head = NULL;
    nnode *tail = NULL;

    char input[256];
    int value;

    printf("Enter numbers or 'end' to stop\n");

    do {
        fgets(input, sizeof(input), stdin);

        // poista newline
        input[strcspn(input, "\n")] = '\0';

        // jos end riko
        if (strcmp(input, "end") == 0) {
            break;
        }

        // onko numero
        if (sscanf(input, "%d", &value) == 1) {

            // tekee uude node
            nnode *newnode = (nnode *)malloc(sizeof(nnode));

            // epic fail
            if (newnode == NULL) {
                printf("Memory allocation error\n");
                exit(1);
            }

            newnode->number = value;
            newnode->next = NULL;

            // lisää listaa
            if (head == NULL) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        } else {
            printf("Invalid input\n");
        }
    } while (input != "end");

    // printtaa yms
    printf("\nNumbers entered: \n");
    nnode *current = head;

    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }

    current = head;

    while (current != NULL) {
        nnode *temp = current;
        current = current->next;
        free(temp);
    }
}

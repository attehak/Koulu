#include <stdio.h>
#include <string.h>

#define max_len 256 // en ole varma kuinka pitkä teksti pitäis olla

int main(){
    char str[max_len];
    int is_it_stop_question_mark = 0;

    do {
        printf("Enter your text\n");
        fgets(str, max_len, stdin);
        int size = strlen(str);

        if (size > 0 && str[size - 1] == '\n') {
            str[size - 1] = '\0';
            size--;
        }
        printf("Length of the string is %d\n", size);

        if (strcmp(str, "stop") == 0) { // tehtävässä ei mainittu mitään kirjainten koosta, pelkästään 'stop'
            is_it_stop_question_mark = 1;
        }

    } while (is_it_stop_question_mark != 1);

    printf("\nThanks for using me\n");

}

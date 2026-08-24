#include <iomanip>
#include <iostream>
using namespace std;

bool replace_char(string &text, char letter_one, char letter_two);

int main() {
    while (true) {
        string text;
        cout << "\nEnter a string or 'stop': ";
        cin >> text;
        if (text == "stop") {
            exit(0);
        }
        char letter_1;
        char letter_2;
        bool changed = false;
        cout << "\nEnter character to find: ";
        cin >> letter_1;
        cout << "\nEnter replacement character: ";
        cin >> letter_2;
        changed = replace_char(text, letter_1, letter_2);
        if (changed) {
            cout << "\nResult: " << text;
        }
    }
}

bool replace_char(string &text, char letter_one, char letter_two) {
    int count = 0;
    if (letter_one == letter_two) {
        return false;
    }
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == letter_one) {
            text[i] = letter_two;
            count++;
        }
    }
    if (count > 0) {
        return true;
    }
    return false;
}

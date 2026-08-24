#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int count = 0;
    cout << "\nHow many numbers do you want to enter? ";
    cin >> count;
    vector<double> numbers(count, 0.0);

    for (int i = 0; i < count; i++) {
        cout << "\nEnter nr[" << i+1 << "]: ";
        cin >> numbers[i];
    }
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    cout << "\nYou entered: ";
    for (int i = 0; i < count; i++) {
        cout << fixed << setprecision(4) << numbers[i] << ", ";
    }
    cout << "sum = " << sum << endl;
}

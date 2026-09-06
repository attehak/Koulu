#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <compare>

using namespace std;

class Item {
public:
    Item();
    Item(string n, int w, double p, int d);

    int getDiscount() const;
    void setDiscount(int d); //0-100
    double getPrice() const; // with potential discount applied
    void setPrice(double p);

    auto operator<=>(const Item& other) const;
    bool operator==(const Item& other) const;


    friend ostream& operator<<(ostream& os, const Item& item); // output
    friend istream& operator>>(istream& is, Item& item); // input

private:
    string name;
    int weight; // in grams
    double price; // in euros
    int discount; // percentage %

    double pricePerKg() const;
};

int Item::getDiscount() const {
    return discount;
}

void Item::setDiscount(int d) {
    if (d >= 0 && d <= 100) {
        discount = d;
    }
}

double Item::getPrice() const {
    return price * (1.0 - discount / 100.0);
}

void Item::setPrice(double p) {
    price = p;
}

double Item::pricePerKg() const {
    return getPrice() / weight * 1000.0;
}

auto Item::operator<=>(const Item& other) const {
    return pricePerKg() <=> other.pricePerKg();
}

bool Item::operator==(const Item& other) const {
    return pricePerKg() == other.pricePerKg();
}

ostream& operator<<(ostream& os, const Item& item) {
    os << fixed << setprecision(2)
    << "{ \"Name\":\"" << item.name
    << "\", \"Weight\":" << item.weight
    << ", \"Price\":" << item.price
    << ", \"Discount\":" << item.discount << " }";
    return os;
}

istream& operator>>(istream& is, Item& item) {

}

int main() {
    vector<Item> items;

    while (true) {
        string input;

        cout << "Enter item name or json or stop";
        getline(cin, input);

        if (input == "stop") {
            break;
        }
        if (input == "json") {
        }
        else {
            string name = input;
            int weight;
            double price;
            int discount;

            cout << "Enter item weight in grams: ";
            cin >> weight;

            cout << "Enter item price: ";
            cin >> price;

            cout << "Enter discount percentage: ";
            cin >> discount;

            cin.ignore(10000, '\n');

            items.emplace_back(name, weight, price, discount);
        }
    }
    while (true) {
        sort(items.begin(), items.end());

        // print items
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << " : " << items[i] << '\n';
        }

        // print net worth
        double netWorth = 0;

        for (const Item& item : items) {
            netWorth += item.getPrice();
        }
        cout << "Net worth: " << fixed << setprecision(2) << netWorth << "€\n";

        string input;

        cout << "Enter item id to change discount or stop: ";
        getline(cin, input);

        if (input == "stop") {
            break;
        }

        int index = stoi(input);

        if (index >= 0 && index < static_cast<int>(items.size())) {
            int discount;

            cout << "Enter new discount percentage: ";
            cin >> discount;
            cin.ignore(10000, '\n');
            items[index].setDiscount(discount);
        }
    }

    return 0;
}

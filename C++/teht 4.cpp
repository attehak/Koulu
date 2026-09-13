#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Passenger;

class Flight {
public:
    Flight(string flightID, string airline, int capacity);

    friend ostream& operator<<(ostream& os, const Flight& flight); // print flight information

    void printPassengers() const;

    bool addPassenger(const shared_ptr<Passenger>& passenger);
    bool removePassenger(const string& firstName, const string& lastName);

    int availableSeats() const;

    bool operator<(const Flight& other) const;
    bool operator>(const Flight& other) const;
    bool operator==(const Flight& other) const;

    string getFlightNumber() const;

private:
    string flightID;
    string airline;
    int passengerCapacity;

    vector<shared_ptr<Passenger>> passengers;
};



class Passenger {
public:
    Passenger(string first, string last, int bags);

    friend ostream& operator<<(ostream& os, const Passenger& passenger);

    bool operator<(const Passenger& other) const;
    bool operator>(const Passenger& other) const;
    bool operator==(const Passenger& other) const;

    string getFirstName() const;
    string getLastName() const;

    void addFlight(const shared_ptr<Flight>& flight);
    void printPassenger() const;

private:
    string firstName;
    string lastName;
    int numberOfBags;

    vector<weak_ptr<Flight>> flights;
};


    // Flight functions -----------------------------------------------------


Flight::Flight(string flightID, string airline, int capacity)
    : flightID(flightID), airline(airline), passengerCapacity(capacity)
{
}

    // To prevent overbooking
int Flight::availableSeats() const
{
    return passengerCapacity - static_cast<int>(passengers.size());
}


bool Flight::addPassenger(const shared_ptr<Passenger>& passenger)
{
    if (availableSeats() <= 0) {
        return false;
    }

    passengers.push_back(passenger);
    return true;
}


bool Flight::removePassenger(const string& firstName, const string& lastName)
{
    for (auto it = passengers.begin(); it != passengers.end(); ++it) {

        if ((*it)->getFirstName() == firstName &&
            (*it)->getLastName() == lastName) {

            passengers.erase(it);
            return true;
            }
    }

    return false;
}


void Flight::printPassengers() const
{
    cout << "Passengers:\n";

    if (passengers.empty()) {
        cout << "  No passengers\n";
        return;
    }

    for (const auto& passenger : passengers) {
        cout << "  " << *passenger << '\n';
    }
}


string Flight::getFlightNumber() const
{
    return flightID;
}


ostream& operator<<(ostream& os, const Flight& flight)
{
    os << "Flight: " << flight.flightID
       << " | Airline: " << flight.airline
       << " | Capacity: " << flight.passengerCapacity
       << " | Available seats: " << flight.availableSeats();

    return os;
}


bool Flight::operator<(const Flight& other) const
{
    return availableSeats() < other.availableSeats();
}


bool Flight::operator>(const Flight& other) const
{
    return availableSeats() > other.availableSeats();
}


bool Flight::operator==(const Flight& other) const
{
    return availableSeats() == other.availableSeats();
}


    // Passenger functions -----------------------------------------------


Passenger::Passenger(string first, string last, int bags)
    : firstName(first), lastName(last), numberOfBags(bags) {
}


string Passenger::getFirstName() const
{
    return firstName;
}


string Passenger::getLastName() const
{
    return lastName;
}


void Passenger::addFlight(const shared_ptr<Flight>& flight)
{
    flights.push_back(flight);
}


ostream& operator<<(ostream& os, const Passenger& passenger)
{
    os << passenger.firstName << " "
       << passenger.lastName
       << " | Bags: " << passenger.numberOfBags;

    return os;
}


void Passenger::printPassenger() const
{
    cout << "Passenger: "
         << firstName << " " << lastName
         << " | Bags: " << numberOfBags << '\n';

    cout << "Flights:\n";

    for (const auto& weakFlight : flights) {

        if (auto flight = weakFlight.lock()) {
            cout << "  " << flight->getFlightNumber() << '\n';
        }
    }
}


bool Passenger::operator<(const Passenger& other) const
{
    if (lastName != other.lastName) {
        return lastName < other.lastName;
    }

    return firstName < other.firstName;
}


bool Passenger::operator>(const Passenger& other) const
{
    if (lastName != other.lastName) {
        return lastName > other.lastName;
    }

    return firstName > other.firstName;
}


bool Passenger::operator==(const Passenger& other) const
{
    return lastName == other.lastName &&
           firstName == other.firstName;
}


int main() {

    vector<shared_ptr<Flight>> flights;
    vector<shared_ptr<Passenger>> passengers;

    int numberOfFlights;

    cout << "Enter number of flights: ";
    cin >> numberOfFlights;
    cin.ignore();

    // Entering flights

    for (int i = 0; i < numberOfFlights; ++i) {

        string flightID;
        string airline;
        int capacity;

        cout << "\nFlight " << i + 1 << '\n';

        cout << "Flight ID: ";
        getline(cin, flightID);

        cout << "Airline: ";
        getline(cin, airline);

        cout << "Passenger capacity: ";
        cin >> capacity;
        cin.ignore();

        flights.push_back(
            make_shared<Flight>(flightID, airline, capacity)
        );
    }

    int numberOfPassengers;

    cout << "\nEnter number of passengers: ";
    cin >> numberOfPassengers;
    cin.ignore();

    // Entering passengers

    for (int i = 0; i < numberOfPassengers; ++i) {

        string firstName;
        string lastName;
        int bags;

        cout << "\nPassenger " << i + 1 << '\n';

        cout << "First name: ";
        getline(cin, firstName);

        cout << "Last name: ";
        getline(cin, lastName);

        cout << "Number of bags: ";
        cin >> bags;
        cin.ignore();

        auto passenger = make_shared<Passenger>(firstName, lastName, bags);

        passengers.push_back(passenger);

        // Selecting flights

        cout << "\nAvailable flights:\n";

        for (size_t j = 0; j < flights.size(); ++j) {
            cout << j + 1 << ". "
                 << *flights[j] << '\n';
        }

        cout << "Please select which flights to book passenger into.\n";
        cout << "Enter 0 when finished.\n";

        while (true) {

            int choice;
            cout << "Flight: ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            if (choice < 1 ||
                choice > static_cast<int>(flights.size())) {

                cout << "Invalid flight.\n";
                continue;
                }

            auto flight = flights[choice - 1];

            if (flight->addPassenger(passenger)) {

                passenger->addFlight(flight);

                cout << "Passenger added to flight.\n";
            }
            else {
                cout << "Flight is full.\n";
            }
        }

        cin.ignore();
    }

    // Sort

    sort(flights.begin(), flights.end(),
        [](const shared_ptr<Flight>& a,
           const shared_ptr<Flight>& b) {

            return *a < *b;
        });

    // Printing


    cout << "\n\n========== FLIGHTS ==========\n\n";

    for (const auto& flight : flights) {

        cout << *flight << '\n';
        flight->printPassengers();
        cout << '\n';
    }


    return 0;
}

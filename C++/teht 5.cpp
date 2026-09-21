#include <gpio.h>
#include <iostream>

#define SW0 9
#define SW1 8
#define SW2 7
#define LED1 22
#define LED2 21
#define LED3 20

using namespace std;

class GPIOPin {
public:
    GPIOPin(int pin, bool input = true, bool pullup = true, bool invert = false);
    GPIOPin(const GPIOPin &) = delete;
    ~GPIOPin();
    bool read();
    void write(bool value);
    explicit operator bool();
private:
    static uint32_t pins_in_use;
    int pin;
    bool in_use;
};

class ButtonLedPair {
public:
    ButtonLedPair();
private:

};

    // GPIOPin functions ------------------------------

int GPIOPin::GPIOPin(int pin, bool input = true, bool pullup = true, bool invert = false) {

}

int main() {

}

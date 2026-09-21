#include <stdio.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SW0 9
#define SW1 8
#define SW2 7
#define LED1 22
#define LED2 21
#define LED3 20

class GPIOPin
{
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
    bool dormant;
};


// one shared variable for all GPIOPin objects
uint32_t GPIOPin::pins_in_use = 0;


GPIOPin::GPIOPin(int pin, bool input, bool pullup, bool invert)
    : pin(pin), dormant(false)
{
    // check if pin already in use
    if (pins_in_use & (1u << pin))
    {
        // if in use don't
        dormant = true;
        return;
    }

    // mark pin as being used
    pins_in_use |= (1u << pin);

    // initialize the GPIO
    gpio_init(pin);

    if (input)
    {
        gpio_set_dir(pin, GPIO_IN);

        if (pullup)
        {
            gpio_pull_up(pin);
        }
        else
        {
            gpio_disable_pulls(pin);
        }

        // input inversion
        if (invert)
        {
            gpio_set_inover(pin, GPIO_OVERRIDE_INVERT);
        }
        else
        {
            gpio_set_inover(pin, GPIO_OVERRIDE_NORMAL);
        }
    }
    else
    {
        gpio_set_dir(pin, GPIO_OUT);

        // output inversion
        if (invert)
        {
            gpio_set_outover(pin, GPIO_OVERRIDE_INVERT);
        }
        else
        {
            gpio_set_outover(pin, GPIO_OVERRIDE_NORMAL);
        }
    }
}


GPIOPin::~GPIOPin()
{
    // destruction!
    if (!dormant)
    {
        pins_in_use &= ~(1u << pin);
    }
}


bool GPIOPin::read()
{
    if (dormant)
    {
        return false;
    }

    return gpio_get(pin);
}


void GPIOPin::write(bool value)
{
    if (dormant)
    {
        return;
    }

    gpio_put(pin, value);
}


GPIOPin::operator bool()
{
    return read();
}


class ButtonLedPair
{
public:
    ButtonLedPair(int buttonPin, int ledPin);
    void update();

private:
    GPIOPin button;
    GPIOPin led;

    bool release_timer_running;
    absolute_time_t release_start;
};


ButtonLedPair::ButtonLedPair(int buttonPin, int ledPin)

    : button(buttonPin, true, true, true),

      led(ledPin, false, false, false),

      release_timer_running(false)
{
}


void ButtonLedPair::update()
{
    if (button)
    {
        // if button is pressed
        led.write(true);

        // dont wait
        release_timer_running = false;
    }
    else
    {
        // when not pressed

        if (!release_timer_running)
        {
            // wait a second
            release_start = get_absolute_time();
            release_timer_running = true;
        }
        else
        {
            // check if a second is waited
            int64_t elapsed_us =
                absolute_time_diff_us(release_start, get_absolute_time());

            if (elapsed_us >= 1000000)
            {
                led.write(false);
                release_timer_running = false;
            }
        }
    }
}

int main()
{
    // Initialize
    stdio_init_all();

    // create three button/LED pairs
    ButtonLedPair sw0_led3(SW0, LED3);
    ButtonLedPair sw1_led2(SW1, LED2);
    ButtonLedPair sw2_led1(SW2, LED1);

    while (true)
    {
        // update all three pairs independently
        sw0_led3.update();
        sw1_led2.update();
        sw2_led1.update();

        // check every 10 ms
        sleep_ms(10);
    }
}

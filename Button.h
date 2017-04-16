#pragma once

#include <Arduino.h>

class Button {
public:
    Button(char p)
        : state(0)
        , pin(p)
    {
        pinMode(pin, INPUT_PULLUP);
    }

    bool wasPressed()
    {
        state = (state << 1) | !digitalRead(pin) | 0xe000;
        return (state == 0xf000);
    }

private:
    unsigned short state;
    char pin;
    Button(const Button& c);
    Button& operator=(const Button& c);
};

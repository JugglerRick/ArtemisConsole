#pragma once
#include <list>
#include <ButtonHandler.h>

class Button
{
public:
    Button(uint8_t pinNumber, ButtonHandler* handler);
    Button(uint8_t pinNumber, uint8_t mode, ButtonHandler* handler);

    void initialize();
    void update();

    uint8_t getPin() {return pin;} 

    void addHandler(ButtonHandler* handler);
    void removeHandler(ButtonHandler* handler);
private:
    uint8_t pin;
    uint8_t mode;
    uint8_t state;
    std::list<ButtonHandler*> handlers;
};
#include <Arduino.h>
#include "Button.h"



Button::Button(uint8_t pinNumber, uint8_t mode, ButtonHandler* handler) 
:   pin(pinNumber)
,   mode(mode)
,   state(LOW)
{
    handlers.push_back(handler);
} 


void Button::initialize(){
    pinMode(pin, mode);
    state = digitalRead(pin);
}


void Button::update(){
    uint8_t curState = digitalRead(pin);

    if(curState != state){
            if(curState == LOW && state == HIGH){
                Serial.write("Button::update; Button Pressed");
                for(auto* handler : handlers){
                    handler->pressed();
                }
            }
            else{
                Serial.write("Button::update; Button Released");
                for(auto* handler : handlers){
                    handler->released();
                }
            }
            state = curState;
    }
}


void Button::addHandler(ButtonHandler* handler){
    handlers.push_back(handler);
}

void Button::removeHandler(ButtonHandler* handler){
    handlers.remove(handler);
}

// void Button::pressed(){}
// void Button::released(){}

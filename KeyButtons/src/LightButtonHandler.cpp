#include <Arduino.h>
#include "LightButtonHandler.h"

LightButtonHandler::LightButtonHandler(uint8_t pinNumber)
: 	pin(pinNumber)
{
}

void LightButtonHandler::pressed() 
{
	digitalWrite(pin, HIGH);
}

void LightButtonHandler::released()
{
	digitalWrite(pin, LOW);
}

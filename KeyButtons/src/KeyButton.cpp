#include <Arduino.h>
//#include <Keyboard.h>
#include <usb_keyboard.h>
#include "Button.h"
#include "KeyButton.h"

KeyButton::KeyButton(uint16_t code)
:   keyCode(code)
,	mod(0)
{}

KeyButton::KeyButton(uint16_t code, uint16_t modifier)
:   keyCode(code)
,	mod(modifier)
{}

void KeyButton::pressed() 
{
	if(0 != mod)
	{
		Keyboard.press(mod);
	}
    Keyboard.press(keyCode);

}

void KeyButton::released() 
{
	if(0 != mod)
	{
		Keyboard.release(mod);
	}
    Keyboard.release(keyCode);
}

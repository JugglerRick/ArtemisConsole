#include <Arduino.h>
//#include <Keyboard.h>
#include <usb_keyboard.h>
#include "Button.h"
#include "KeyButton.h"

KeyButton::KeyButton(uint16_t code)
:   keyCode(code)
{}


void KeyButton::pressed() 
{
    //usb_keyboard_press_keycode(keyCode);
    Keyboard.press(keyCode);

}

void KeyButton::released() 
{
    //usb_keyboard_release_keycode(keyCode);
    Keyboard.release(keyCode);
}

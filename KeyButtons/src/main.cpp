#include <Arduino.h>
//#include <usb_serial.h>
#include <usb_keyboard.h>
#include <memory>
#include "Button.h"
#include "KeyButton.h"
#include "LightButtonHandler.h"


LightButtonHandler a_KeyLight(21);
KeyButton a_Key(KEY_A);
KeyButton b_Key(KEY_B);

std::array<Button, 2> buttons {
  Button(3, INPUT, &a_Key),
  Button(4, INPUT, &b_Key) 
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  (buttons.begin())->addHandler(&a_KeyLight);
  for(auto& button : buttons){
    button.initialize();
  }
}

void loop() {
  for(auto& button : buttons){
    button.update();
  }
}
#include <Arduino.h>
//#include <usb_serial.h>
#include <usb_keyboard.h>
#include <memory>
#include "Button.h"
#include "KeyButton.h"
#include "LightButtonHandler.h"


KeyButton raiseShields_Key(KEY_K);
KeyButton lowerShields_Key(KEY_L);
KeyButton toggleShields_Key(KEY_Q);
KeyButton toggleAutoBeams_Key(KEY_B);
KeyButton raiseBeamFreq_Key(KEY_LEFT);
KeyButton lowerBeamFreq_Key(KEY_RIGHT);
KeyButton zoomIn_Key(KEY_T);
KeyButton zoomOut_Key(KEY_Y);
KeyButton torpedoes_Key(KEY_1);
KeyButton nukes_Key(KEY_2);
KeyButton mines_Key(KEY_3);
KeyButton emps_Key(KEY_4);
KeyButton tube1_Key( KEY_1, MODIFIERKEY_SHIFT);
KeyButton tube2_Key( KEY_2, MODIFIERKEY_SHIFT);
KeyButton tube3_Key( KEY_3, MODIFIERKEY_SHIFT);
KeyButton tube4_Key( KEY_4, MODIFIERKEY_SHIFT);
KeyButton tube5_Key( KEY_5, MODIFIERKEY_SHIFT);
KeyButton tube6_Key( KEY_6, MODIFIERKEY_SHIFT);
KeyButton torpToEng_Key( KEY_U, MODIFIERKEY_SHIFT);
KeyButton engToTorp_Key( KEY_I, MODIFIERKEY_SHIFT);

std::array<Button, 20> buttons {
	Button( 3, &raiseShields_Key),
	Button( 4, &lowerShields_Key),
	Button( 5, &toggleShields_Key),
	Button( 6, &toggleAutoBeams_Key),
	Button( 7, &raiseBeamFreq_Key),
	Button( 8, &lowerBeamFreq_Key),
	Button( 9, &zoomIn_Key),
	Button(10, &zoomOut_Key),
	Button(11, &torpedoes_Key),
	Button(12, &nukes_Key),
	Button(13, &mines_Key),
	Button(14, &emps_Key),
	Button(15, &tube1_Key),
	Button(16, &tube2_Key),
	Button(17, &tube3_Key),
	Button(18, &tube4_Key),
	Button(19, &tube5_Key),
	Button(20, &tube6_Key),
	Button(21, &torpToEng_Key),
	Button(22, &engToTorp_Key)
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  for(auto& button : buttons){
    button.initialize();
  }
}

void loop() {
  for(auto& button : buttons){
    button.update();
  }
}
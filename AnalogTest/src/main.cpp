#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
}

int x;
int y;
uint8_t button;

void loop() {
  x = analogRead(0);
  y = analogRead(1);
  button = digitalRead(0);

  Serial.printf("JoyStick x = %4d y = %4d button is: %s\n", x, y, (0 == button) ? "up" : "down" );
  delay(100);
}


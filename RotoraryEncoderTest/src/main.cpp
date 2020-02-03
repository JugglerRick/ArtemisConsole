#include <Arduino.h>
#define encoder0PinA 9
#define encoder0PinB 10
#define encoder0Btn 11

int encoder0Pos = 0;
int valRotary, lastValRotary;

void doEncoder()
{
	if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB))
	{
		encoder0Pos++;
	}
	else
	{
		encoder0Pos--;
	}
	valRotary = encoder0Pos ;
} 

void setup()
{
	Serial.begin(9600);
	pinMode(encoder0PinA, INPUT_PULLUP);
	pinMode(encoder0PinB, INPUT_PULLUP);
	pinMode(encoder0Btn, INPUT_PULLUP);
	attachInterrupt(encoder0PinA, doEncoder, CHANGE);
}

void loop()
{
	int btn = digitalRead(encoder0Btn);
	Serial.print(btn);
	Serial.print(" ");
	Serial.print(valRotary);
	if (valRotary > lastValRotary)
	{
		Serial.print("  CW  ");
	}
	if(valRotary  < lastValRotary)
	{
		Serial.print("  CCW ");
	}
	lastValRotary = valRotary;
	Serial.print("\r");
	delay(250);
}


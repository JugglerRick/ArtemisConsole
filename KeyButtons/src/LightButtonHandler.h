#pragma once
#include "ButtonHandler.h"

class LightButtonHandler : public ButtonHandler
{
public:
	LightButtonHandler(uint8_t pinNumber);
  	void pressed() override;
  	void released() override;
private:
	uint8_t pin;
 };

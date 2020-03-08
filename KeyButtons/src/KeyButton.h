#pragma once

class Button;

class KeyButton : public ButtonHandler
{
public:
    KeyButton(uint16_t code);
	KeyButton(uint16_t code, uint16_t modifier);
    void pressed() override;
    void released() override;

    static void releaseAll();
private:
    uint16_t keyCode;
	uint16_t mod;
};
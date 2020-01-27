#pragma once

class Button;

class KeyButton : public ButtonHandler
{
public:
    KeyButton(uint16_t code);
    void pressed() override;
    void released() override;

    static void releaseAll();
private:
    uint16_t keyCode;
};
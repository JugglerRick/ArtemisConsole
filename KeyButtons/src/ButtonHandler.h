#pragma once

class ButtonHandler
{
public:
    virtual void pressed() = 0;
    virtual void released() = 0;
};


#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "SystemState.h"

class DisplayHandler
{
private:
    // private objects and variables
    LiquidCrystal_I2C lcd;

public:
    // Constructur to initialize the class
    DisplayHandler(uint8_t address, uint8_t cols, uint8_t rows);
    // Function prototypes
    void begin();
    void updateScreen(); // Refresh LCD
};

#endif

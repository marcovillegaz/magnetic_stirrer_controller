#include "DisplayHandler.h"
#include <Arduino.h>

// Constructor: Initializes LCD with I2C address, columns, and rows
DisplayHandler::DisplayHandler(uint8_t address, uint8_t cols, uint8_t rows)
    : lcd(address, cols, rows) {}

void DisplayHandler::begin()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("RPM Control");
    lcd.setCursor(0, 1);
    lcd.print("version 2.1.0");
    delay(2000);
    updateScreen();
}

// Update LCD Display
void DisplayHandler::updateScreen()
{
    SystemState &state = SystemState::getInstance();

    lcd.clear();

    if (state.mode == SHOW_RPM)
    {
        lcd.setCursor(0, 0);
        lcd.print(state.currentOption == MOTOR1 ? ">M1:" : " M1:");
        lcd.setCursor(6, 0);
        lcd.print(state.rpm[MOTOR1], 1);
        lcd.print(" RPM");

        lcd.setCursor(0, 1);
        lcd.print(state.currentOption == MOTOR2 ? ">M2:" : " M2:");
        lcd.setCursor(6, 1);
        lcd.print(state.rpm[MOTOR2], 1);
        lcd.print(" RPM");
    }
    else if (state.mode == SET_RPM)
    {
        lcd.setCursor(0, 0);
        lcd.print("Set RPM:");

        lcd.setCursor(0, 1);
        lcd.print(state.rpm[state.currentOption]);
    }
}

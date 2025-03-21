#include "EncoderHandler.h"
#include <Arduino.h>

// Constructor: Initializes encoder and button
EncoderHandler::EncoderHandler(uint8_t clk, uint8_t dt, uint8_t sw, DisplayHandler *disp)
    : encoder(clk, dt), buttonPin(sw), display(disp), lastPosition(0) {}

void EncoderHandler::begin()
{
    pinMode(buttonPin, INPUT_PULLUP);
}

// Read encoder and update display
void EncoderHandler::update()
{
    // The display will be updated only if the encoder is rotated or pressed

    SystemState &state = SystemState::getInstance();

    int newPosition = encoder.read() / 4; // Encoder reading

    if (newPosition < lastPosition)
    {
        // If in SHOW_RPM mode, switch between motors
        if (state.mode == SHOW_RPM)
            state.currentOption = (state.currentOption == MOTOR1) ? MOTOR2 : MOTOR1;
        // If in SET_RPM mode, increase RPM value
        else if (state.mode == SET_RPM)
        {
            state.rpm[state.currentOption] += 10;
        }
        display->updateScreen();
    }
    // If encoder rotated in the opposite direction
    else if (newPosition > lastPosition)
    {
        // If in SHOW_RPM mode, switch between motors
        if (state.mode == SHOW_RPM)
            state.currentOption = (state.currentOption == MOTOR1) ? MOTOR2 : MOTOR1;
        // If in SET_RPM mode, decrease RPM value
        else if (state.rpm[state.currentOption] > 0) // Condition to avoid negative values
        {
            state.rpm[state.currentOption] -= 10;
        }
        display->updateScreen();
    }

    lastPosition = newPosition;
    // display->updateScreen();

    if (digitalRead(buttonPin) == LOW)
    {
        delay(200);
        state.mode = (state.mode == SHOW_RPM) ? SET_RPM : SHOW_RPM;
        display->updateScreen();
    }
}
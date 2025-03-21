#ifndef ENCODERHANDLER_H
#define ENCODERHANDLER_H

#include <Encoder.h>
#include "SystemState.h"
#include "DisplayHandler.h"

// Class to handle the rotary encoder
class EncoderHandler {
private:
    Encoder encoder;
    uint8_t buttonPin;
    DisplayHandler *display;
    int lastPosition;

public:
    // Constructor: Initializes encoder and button
    EncoderHandler(uint8_t clk, uint8_t dt, uint8_t sw, DisplayHandler* disp);
    // Function prototypes
    void begin(); // Initializes the encoder and button
    void update(); // Reads encoder input and updates display
};

#endif

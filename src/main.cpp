#include "DisplayHandler.h"
#include "EncoderHandler.h"

#define ENCODER_CLK 2
#define ENCODER_DT 3
#define ENCODER_SW 4

DisplayHandler display(0x27, 16, 2);
EncoderHandler encoder(ENCODER_CLK, ENCODER_DT, ENCODER_SW, &display);

void setup()
{
  // Initialize the display and encoder
  display.begin();
  encoder.begin();
}

void loop()
{
  // Update the encoder
  encoder.update();
  delay(100); // Adds a short delay to allow the display to update
}

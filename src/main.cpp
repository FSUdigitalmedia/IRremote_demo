#include <Arduino.h>

#define IR_RECEIVE_PIN 2

// #define ENABLE_NEC2_REPEATS   // Instead of sending / receiving the NEC special repeat code, send / receive the original frame for repeat.
#include "TinyIRReceiver.hpp"

volatile uint8_t receivedCommand;
volatile uint8_t receivedFlags;
volatile bool justReceived;

void setup()
{
  Serial.begin(115200);

  // Enables the interrupt generation on change of IR input signal
  if (!initPCIInterruptForTinyReceiver())
  {
    Serial.println(F("No interrupt available for selected pin")); // optimized out by the compiler, if not required :-)
  }
  Serial.println(F("Ready to receive NEC IR signals"));
}

void loop()
{
  if (justReceived)
  {
    justReceived = false;
    Serial.print(F(" Command="));
    Serial.print(receivedCommand);
    if (receivedFlags == IRDATA_FLAGS_IS_REPEAT)
    {
      Serial.print(F(" (Repeat)"));
    }
    Serial.println();
  }
}

/*
 * This is the function that is called if a complete command was received
 * It runs in an ISR context with interrupts enabled, so functions like delay() etc. should work here
 */
void handleReceivedTinyIRData(uint8_t aAddress, uint8_t aCommand, uint8_t aFlags)
{
  // it's best not to do anything time consuming in this function
  // just copy the data to a global variable and handle it in the main loop
  receivedCommand = aCommand;
  receivedFlags = aFlags;
  justReceived = true;
}
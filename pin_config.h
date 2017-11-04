#ifndef pin_config_h
#define pin_config_h

// Motor pins
const uint8_t rightMotorPinA = 9;
const uint8_t rightMotorPinB = 10;

const uint8_t leftMotorPinA = 3;
const uint8_t leftMotorPinB = 11;

// Button pin (configured so that on is LOW)
const uint8_t buttonPin = 12;

// Transmit and receive pins for distance sensor
// modified for use with Adafruit Feather
const uint8_t tPin = 5;
const uint8_t rPin = 6;

// Pin for status LED (turns on when nose touch neurons stimulated)
const uint8_t statusPin = 13;

#endif

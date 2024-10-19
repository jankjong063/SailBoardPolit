#include "WindMeter.h"

WindMeter::WindMeter(int windDirPin, int windSpeedPin) {
    _windDirPin = windDirPin;
    _windSpeedPin = windSpeedPin;
}

void WindMeter::begin() {
    pinMode(_windSpeedPin, INPUT);
}

float WindMeter::getWindDirection() {
    return analogRead(_windDirPin) * (360.0 / 1023.0); // Convert analog input to degrees
}

float WindMeter::getWindSpeed() {
    // Simulating wind speed calculation; use interrupts for real-time anemometer readings
    return random(1, 20); // Random value between 1 and 20 m/s for now
}


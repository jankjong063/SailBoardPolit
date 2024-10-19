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

// Added weather condition integration logic
void WindMeter::adjustFinBasedOnWeather() {
    // Example logic to adjust fin behavior based on wind speed and direction
    int windSpeed = getWindSpeed();
    int windDirection = getWindDirection();
    if (windSpeed > 20) {
        adjustFinForHighWind();
    } else {
        adjustFinForLowWind();
    }
}

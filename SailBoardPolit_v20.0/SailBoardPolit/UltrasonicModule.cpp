
#include "UltrasonicModule.h"
#include <Arduino.h>

UltrasonicModule::UltrasonicModule(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

long UltrasonicModule::getDistance() {
    // Send a 10us HIGH pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the pulse duration in microseconds
    long duration = pulseIn(echoPin, HIGH);

    // Convert the duration to distance (in centimeters)
    long distance = duration * 0.034 / 2;
    return distance;
}



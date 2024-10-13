#include "MotorControl.h"
#include <Servo.h>

Servo finServo;

MotorControl::MotorControl(int motorPin) {
    _motorPin = motorPin;
}

void MotorControl::begin() {
    finServo.attach(_motorPin);
}

int MotorControl::calculateFinAngle(float windDirection, float gpsBearing) {
    int angle = (int)(gpsBearing - windDirection); 
    if (angle < 0) angle += 360;  // Normalize angle to 0-360
    return angle;
}

void MotorControl::setFinAngle(int angle) {
    finServo.write(angle);
}

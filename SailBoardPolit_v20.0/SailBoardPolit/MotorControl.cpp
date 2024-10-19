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
int finMotorEfficiency, motorPerformance;
int triggerCalibrationRoutine(){}
int triggerMaintenanceAlert(){}
// Added Fin Health Monitoring and Calibration
void monitorFinHealth() {
    // Logic to monitor fin health and efficiency
    if (finMotorEfficiency < 70) {
        triggerCalibrationRoutine();
    }
}
int adjustFinForHighWind(){}
int adjustFinForLowWind(){}
int adjustFinForMediumWind(){}
// Added Adaptive Sail Control Based on Wind Speed
void adjustSailBasedOnWindSpeed(int windSpeed) {
    if (windSpeed > 20) {
        adjustFinForHighWind();
    } else if (windSpeed > 10) {
        adjustFinForMediumWind();
    } else {
        adjustFinForLowWind();
    }
}

// Added Predictive Maintenance Alerts
void checkMotorForMaintenance() {
    // Logic to analyze motor performance data and predict maintenance needs
    if (motorPerformance < 50) {
        triggerMaintenanceAlert();
    }
}

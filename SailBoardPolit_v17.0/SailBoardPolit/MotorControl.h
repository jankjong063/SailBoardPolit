#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl {
    private:
        int _motorPin, finMotorEfficiency, motorPerformance;
    
    public:
        MotorControl(int motorPin);
        void begin();
        int calculateFinAngle(float windDirection, float gpsBearing);
        void setFinAngle(int angle), triggerCalibrationRoutine();
        // Added Fin Health Monitoring and Calibration
        void monitorFinHealth() {
            // Logic to monitor fin health and efficiency
            if (finMotorEfficiency < 70) {
                triggerCalibrationRoutine();
            }
        }
        void adjustFinForHighWind(), adjustFinForMediumWind(), adjustFinForLowWind(), triggerMaintenanceAlert();
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
};

#endif

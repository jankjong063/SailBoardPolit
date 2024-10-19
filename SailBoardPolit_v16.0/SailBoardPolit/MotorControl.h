#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl {
    private:
        int _motorPin, finMotorEfficiency;
    
    public:
        MotorControl(int motorPin);
        void begin();
        int calculateFinAngle(float windDirection, float gpsBearing);
        void setFinAngle(int angle);
        void triggerCalibrationRoutine();
        void adjustFinForHighWind();
        void adjustFinForMediumWind();
        void adjustFinForLowWind();

        // Added Fin Health Monitoring and Calibration
        void monitorFinHealth() {
            // Logic to monitor fin health and efficiency
            if (finMotorEfficiency < 70) {
                triggerCalibrationRoutine();
            }
        }

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
};

#endif

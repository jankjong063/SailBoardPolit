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
        int triggerCalibrationRoutine();

// Added Fin Health Monitoring and Calibration
void monitorFinHealth() {
    // Logic to monitor fin health and efficiency
    if (finMotorEfficiency < 70) {
        triggerCalibrationRoutine();
    }
}        
};

#endif

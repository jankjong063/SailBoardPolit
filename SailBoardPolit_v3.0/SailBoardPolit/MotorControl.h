#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl {
    private:
        int _motorPin;
    
    public:
        MotorControl(int motorPin);
        void begin();
        int calculateFinAngle(float windDirection, float gpsBearing);
        void setFinAngle(int angle);
};

#endif

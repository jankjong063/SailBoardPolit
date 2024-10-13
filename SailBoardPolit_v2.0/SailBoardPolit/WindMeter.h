#ifndef WINDMETER_H
#define WINDMETER_H

#include <Arduino.h>

class WindMeter {
    private:
        int _windDirPin;
        int _windSpeedPin;
    
    public:
        WindMeter(int windDirPin, int windSpeedPin);
        void begin();
        float getWindDirection();
        float getWindSpeed();
};

#endif

#ifndef WINDMETER_H
#define WINDMETER_H

#include <Arduino.h>

class WindMeter {
    typedef int GPSLocation;
    private:
        int _windDirPin;
        int _windSpeedPin;
    
    public:
        WindMeter(int windDirPin, int windSpeedPin);
        void begin();
        float getWindDirection();
        float getWindSpeed();
        // Added weather condition integration logic
        void adjustFinBasedOnWeather();
        int adjustFinForHighWind(){}
        int adjustFinForLowWind(){}
        GPSLocation getHomeLocation();
        GPSLocation getCurrentLocation();        
};

#endif

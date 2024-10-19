#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>

class GPSModule {
    public:
        GPSModule();
        void begin();
        float getLatitude();
        float getLongitude();
        float getBearingToTarget(float targetLat, float targetLon);
};

#endif

#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>

class GPSModule {
  typedef int     GPSLocation;
    public:
        GPSModule();
        void begin();
        float getLatitude();
        float getLongitude();
        float getBearingToTarget(float targetLat, float targetLon);
        void returnToHome();
        GPSLocation getHomeLocation(){}
        GPSLocation getCurrentLocation(){}
        int navigateTo(GPSLocation home);        
};
#endif

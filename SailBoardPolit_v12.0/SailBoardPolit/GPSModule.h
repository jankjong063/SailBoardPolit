#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>

class GPSModule {
    public:
        typedef int GPSLocation;
        GPSModule();
        void begin();
        float getLatitude();
        float getLongitude();
        float getBearingToTarget(float targetLat, float targetLon);
        GPSLocation getCurrentLocation();
        int isWithinSafetyZone(GPSLocation);
        int triggerAlert(const char*);
        int initiateReturnToHome();        
        // Added Safety Zones and Geofencing functionality
        void monitorGeofencing() {
            GPSLocation currentLocation = getCurrentLocation();
            if (!isWithinSafetyZone(currentLocation)) {
                triggerAlert("Out of safety zone!");
                initiateReturnToHome();
            }
        }        
};

#endif

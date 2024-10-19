#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>
// Structure to define GPS waypoints
struct GPSWaypoint {
    float latitude;
    float longitude;
};

struct GPSLocation {
    float latitude;
    float longitude;
};


class GPSModule {
    public:
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
        GPSWaypoint* getRouteWaypoints();
        void navigateTo(GPSWaypoint&);
        // Added Autonomous Route Following using GPS waypoints
        void followRoute() {
            GPSWaypoint* waypoints = getRouteWaypoints();
            for (int i = 0; i < sizeof(waypoints) / sizeof(GPSWaypoint); i++) {
                navigateTo(waypoints[i]);
            }
        }
};

#endif

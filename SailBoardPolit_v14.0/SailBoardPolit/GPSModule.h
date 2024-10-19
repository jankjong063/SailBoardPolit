#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <Arduino.h>

class GPSModule {
    public:
        typedef int GPSLocation;
        // Structure to define GPS waypoints
        struct GPSWaypoint {
            float latitude;
            float longitude;
        };

        // Function to navigate to a specific GPS waypoint
        void navigateTo(GPSWaypoint waypoint) {
            // Example logic to navigate to the given waypoint
            Serial.print("Navigating to: ");
            Serial.print("Lat: "); Serial.print(waypoint.latitude);
            Serial.print(", Lon: "); Serial.println(waypoint.longitude);
        }
        // Function to retrieve an array of route waypoints
        GPSWaypoint* getRouteWaypoints() {
            static GPSWaypoint waypoints[3];
            waypoints[0] = {0.0, 0.0};  // Placeholder waypoints
            waypoints[1] = {1.0, 1.0};
            waypoints[2] = {2.0, 2.0};
            return waypoints;
        }

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
        // Added Autonomous Route Following using GPS waypoints
        void followRoute() {
            GPSWaypoint* waypoints = getRouteWaypoints();
            for (int i = 0; i < sizeof(waypoints) / sizeof(GPSWaypoint); i++) {
                navigateTo(waypoints[i]);
            }
        }
};

#endif

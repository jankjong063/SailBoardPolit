#include "GPSModule.h"
#include <TinyGPS++.h>

TinyGPSPlus gps;

GPSModule::GPSModule() {}

void GPSModule::begin() {
    Serial1.begin(9600); // Assuming GPS is connected to Serial1
}

float GPSModule::getLatitude() {
    return gps.location.isValid() ? gps.location.lat() : 0.0;
}

float GPSModule::getLongitude() {
    return gps.location.isValid() ? gps.location.lng() : 0.0;
}

float GPSModule::getBearingToTarget(float targetLat, float targetLon) {
    float lat = getLatitude();
    float lon = getLongitude();
    return gps.courseTo(lat, lon, targetLat, targetLon); // Bearing to target
}

#include "WindMeter.h"
#include "GPSModule.h"
#include "MotorControl.h"
#include "RadioModule.h"

WindMeter windMeter(A0, 2);     // Wind direction on A0, wind speed on pin 2
GPSModule gpsModule;            // GPS module
MotorControl motorControl(9);    // Servo motor control on pin 9
RadioModule radioModule(433E6); // LoRa radio module at 433 MHz

void setup() {
    Serial.begin(9600);
    
    // Initialize all modules
    windMeter.begin();
    gpsModule.begin();
    motorControl.begin();
    radioModule.begin();
}

void loop() {
    // Get wind speed and direction
    float windDirection = windMeter.getWindDirection();
    float windSpeed = windMeter.getWindSpeed();
    Serial.print("Wind Speed: ");
    Serial.println(windSpeed);   
    // Get GPS data (latitude, longitude, bearing)
    float latitude = gpsModule.getLatitude();
    float longitude = gpsModule.getLongitude();
    float gpsBearing = gpsModule.getBearingToTarget(40.7128, -74.0060); // Example: target GPS for New York
    
    // Calculate fin angle based on wind and GPS data
    int finAngle = motorControl.calculateFinAngle(windDirection, gpsBearing);
    
    // Adjust the motor's angle
    motorControl.setFinAngle(finAngle);
    
    // Send GPS position via radio
    radioModule.sendPosition(latitude, longitude, gpsBearing);
    
    delay(1000);  // Wait for a second before next loop
}

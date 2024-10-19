#include "WindMeter.h"
#include "GPSModule.h"
#include "MotorControl.h"
#include "RadioModule.h"

WindMeter windMeter(A0, 2);     // Wind direction on A0, wind speed on pin 2
GPSModule gpsModule;            // GPS module
MotorControl motorControl(9);    // Servo motor control on pin 9
RadioModule radioModule(433E6); // LoRa radio module at 433 MHz

// Feature 2: Bluetooth Connectivity
#include "BluetoothModule.h"

BluetoothModule btModule;

void setup() {
    Serial.begin(9600);
    
    // Initialize all modules
    windMeter.begin();
    gpsModule.begin();
    motorControl.begin();
    radioModule.begin();

    // Existing setup code
    // Initialize Bluetooth module
    btModule = BluetoothModule();
}

// Feature 1: Obstacle Detection and Avoidance
#include "UltrasonicModule.h"

UltrasonicModule obstacleSensor(7, 8); // Example pins

void checkObstacles() {
    long distance = obstacleSensor.getDistance();
    if (distance > 0 && distance < 30) {  // Example threshold of 30 cm
        // Take action, e.g., stop or adjust motor control
        Serial.println("Obstacle detected! Adjusting course.");
        // Add code to adjust motor control
    }
}

void loop() {
    checkObstacles(); // Call the obstacle detection function regularly
    // Existing code here...    
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

    // Check for Bluetooth data
    String btData = btModule.receive();
    if (btData != "") {
        Serial.println("Received via Bluetooth: " + btData);
        btModule.send("Acknowledged: " + btData);
    }    
}
#define MANUAL 0
#define AUTO 1
int currentMode = MANUAL;
int switchToAutoMode();
int switchToManualMode();
// Added Multi-Mode Sailing (Manual/Auto) functionality
void toggleSailingMode() {
    if (currentMode == MANUAL) {
        switchToAutoMode();
    } else {
        switchToManualMode();
    }
}

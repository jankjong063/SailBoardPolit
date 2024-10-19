
#ifndef BluetoothModule_h
#define BluetoothModule_h

#include <Arduino.h>

class BluetoothModule {
  public:
    BluetoothModule();
    void send(String data);
    String receive();
int initializeBluetooth() {}
int enableRemoteFinControl() {}
// Added Remote Control via Mobile App
void setupMobileControl() {
    // Establish Bluetooth connection to mobile app
    initializeBluetooth();
    // Allow control of fin movement via app
    enableRemoteFinControl();
}    
};

#endif

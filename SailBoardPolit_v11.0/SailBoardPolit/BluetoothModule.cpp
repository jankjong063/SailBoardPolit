
#include "BluetoothModule.h"
#include <SoftwareSerial.h>

// Define pins for SoftwareSerial (TX, RX)
SoftwareSerial bluetoothSerial(10, 11);

BluetoothModule::BluetoothModule() {
    // Begin communication at 9600 baud rate
    bluetoothSerial.begin(9600);
}

void BluetoothModule::send(String data) {
    bluetoothSerial.println(data);
}

String BluetoothModule::receive() {
    if (bluetoothSerial.available()) {
        return bluetoothSerial.readString();
    }
    return "";
}


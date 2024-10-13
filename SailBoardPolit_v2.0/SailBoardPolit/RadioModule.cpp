#include "RadioModule.h"
#include <LoRa.h>

RadioModule::RadioModule(long frequency) {
    _frequency = frequency;
}

void RadioModule::begin() {
    LoRa.begin(_frequency);
}

void RadioModule::sendPosition(float latitude, float longitude, float gpsBearing) {
    LoRa.beginPacket();
    LoRa.print("Latitude: ");
    LoRa.print(latitude, 6);
    LoRa.print(" Longitude: ");
    LoRa.print(longitude, 6);
    LoRa.print(" Bearing: ");
    LoRa.print(gpsBearing, 2);
    LoRa.endPacket();    
}

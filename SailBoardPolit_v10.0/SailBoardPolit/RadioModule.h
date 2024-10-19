#ifndef RADIOMODULE_H
#define RADIOMODULE_H

#include <Arduino.h>

class RadioModule {
    private:
        long _frequency;
    
    public:
        RadioModule(long frequency);
        void begin();
        void sendPosition(float latitude, float longitude, float gpsBearing);
};

#endif

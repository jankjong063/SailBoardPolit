
#ifndef UltrasonicModule_h
#define UltrasonicModule_h

class UltrasonicModule {
  public:
    UltrasonicModule(int trigPin, int echoPin);
    long getDistance();
  
  private:
    int trigPin;
    int echoPin;
};

#endif

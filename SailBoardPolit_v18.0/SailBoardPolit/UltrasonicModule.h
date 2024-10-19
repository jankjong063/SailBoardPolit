
#ifndef UltrasonicModule_h
#define UltrasonicModule_h

class UltrasonicModule {
  public:
    UltrasonicModule(int trigPin, int echoPin);
    long getDistance(), getUltrasonicDistance();
    // Added Obstacle Avoidance System
    void detectAndAvoidObstacle() {
        int distance = getUltrasonicDistance();
        if (distance < 5) {
            stopSailboard();
            adjustDirectionToAvoidObstacle();
        }
    }
    void stopSailboard(), adjustDirectionToAvoidObstacle();
  private:
    int trigPin;
    int echoPin;
};

#endif

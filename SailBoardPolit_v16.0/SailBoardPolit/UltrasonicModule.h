
#ifndef UltrasonicModule_h
#define UltrasonicModule_h

class UltrasonicModule {
  public:
    UltrasonicModule(int trigPin, int echoPin);
    long getDistance();
    int getUltrasonicDistance(), stopSailboard(), adjustDirectionToAvoidObstacle();
    // Added Obstacle Avoidance System
    void detectAndAvoidObstacle() {
        int distance = getUltrasonicDistance();
        if (distance < 5) {
            stopSailboard();
            adjustDirectionToAvoidObstacle();
        }
    }
  private:
    int trigPin;
    int echoPin;
};

#endif

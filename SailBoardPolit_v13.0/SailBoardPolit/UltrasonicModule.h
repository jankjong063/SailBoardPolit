
#ifndef UltrasonicModule_h
#define UltrasonicModule_h

class UltrasonicModule {
  public:
    UltrasonicModule(int trigPin, int echoPin);
    long getDistance();
  int getUltrasonicDistance();
  void adjustDirectionToAvoidObstacle() {
      // Add logic to change sailboard direction
  }
  stopSailboard();
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

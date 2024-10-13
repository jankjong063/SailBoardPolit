
# SailBoardPolit Project - Feature 1: Obstacle Detection and Avoidance

## Overview

This version of the SailBoardPolit project introduces an **Obstacle Detection and Avoidance** system. Using an ultrasonic sensor, the sailboard can now detect obstacles in its path and automatically adjust the fin to avoid collisions.

### New Feature:
1. **Obstacle Detection and Avoidance**: 
   - Integrated ultrasonic sensors for obstacle detection.
   - Adjusts the sailboard’s motor control when an obstacle is detected within a certain range (30 cm by default).
   - Helps avoid potential collisions and ensures safer navigation.

### Files Added:
- `UltrasonicModule.cpp` and `UltrasonicModule.h`: New files to handle the ultrasonic sensor.

### How to Use:
- The obstacle detection system is already integrated into the `SailBoardPolit.ino` file. Make sure to connect the ultrasonic sensor to the appropriate pins (7 and 8 by default) and upload the code to your Arduino.

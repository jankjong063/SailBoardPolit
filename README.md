# Sailboard Fin Control System

## Project Description

The **Sailboard Fin Control System** is an Arduino-based project designed to automatically control the sailboard's fin based on wind direction, speed, and GPS target location. The system integrates several components like wind meters, GPS sensors, motor control, and LoRa radio communication to adjust the fin and broadcast real-time position data.

### Features
- Real-time wind speed and direction monitoring via wind meter.
- GPS integration to track and adjust the sailboard's direction towards a predefined target.
- Motorized control of the sailboard's fin based on the wind and GPS data.
- Radio communication (LoRa) to broadcast position updates.
- Modular design with clean code architecture.

## Source Code Structure

SailBoardPolit/ ├── SailBoardPolit.ino # Main Arduino sketch
                ├── WindMeter.h # Header file for WindMeter functionality
                ├── WindMeter.cpp # Implementation file for WindMeter
                ├── GPSModule.h # Header file for GPS module
                ├── GPSModule.cpp # Implementation file for GPS module
                ├── MotorControl.h # Header file for Motor control
                ├── MotorControl.cpp # Implementation file for Motor control
                ├── RadioModule.h # Header file for LoRa communication
                ├── RadioModule.cpp # Implementation file for LoRa communication
                └── postbuild.bat # Script to copy the .elf file post build

### Individual Source Code Explanation

- **SailBoardPolit.ino**: The main sketch file that ties all modules together. It initializes the sensors, reads data from wind meters and GPS, and controls the motor based on the logic defined in the other files.

- **WindMeter.h / WindMeter.cpp**: 
  - Manages the wind speed and direction using analog sensors (anemometer and wind vane).
  - Functions:
    - `getWindDirection()`: Reads the current wind direction from the wind vane.
    - `getWindSpeed()`: Reads the wind speed from the anemometer.

- **GPSModule.h / GPSModule.cpp**:
  - Interacts with the GPS module to provide real-time coordinates and bearing.
  - Functions:
    - `getLatitude()`: Returns the current latitude from the GPS module.
    - `getLongitude()`: Returns the current longitude.
    - `getBearingToTarget()`: Calculates the bearing to a predefined GPS target.

- **MotorControl.h / MotorControl.cpp**:
  - Controls a servo motor to adjust the sailboard's fin angle based on wind and GPS data.
  - Functions:
    - `calculateFinAngle()`: Determines the optimal fin angle.
    - `setFinAngle()`: Adjusts the motor to the calculated fin angle.

- **RadioModule.h / RadioModule.cpp**:
  - Uses a LoRa module for wireless communication. Sends position data to a remote server or other boards.
  - Functions:
    - `sendPosition()`: Broadcasts GPS coordinates and heading.

- **postbuild.bat**:
  - A batch script that runs after the Arduino build process to copy the `.elf` file to the source folder.

## How to Build

### Hardware Requirements:
- **Arduino Mega 2560** (or any Arduino-compatible microcontroller)
- **Wind Meter (Anemometer & Wind Vane)**
- **NEO-6M GPS Module**
- **Servo Motor**
- **LoRa Module (e.g., SX1278)**
- **Power Supply** suitable for Arduino and peripherals

### Software Requirements:
- **Arduino IDE**
- **TinyGPS++** Library:
  - Install via the Arduino Library Manager: **Sketch** > **Include Library** > **Manage Libraries...**, and search for **TinyGPS++** by Mikal Hart.
- **LoRa** Library:
  - Install via the Arduino Library Manager: **Sketch** > **Include Library** > **Manage Libraries...**, and search for **LoRa** by Sandeep Mistry.
- **Servo** Library:
  - The Servo library is typically pre-installed in the Arduino IDE.

### Steps to Build:
1. Clone the repository to your local machine.
    ```bash
    git clone https://github.com/yourusername/SailboardControlSystem.git
    ```
2. Open the `SailBoardPolit.ino` sketch in the Arduino IDE.
3. Install the required libraries:
    - TinyGPS++
    - LoRa
    - Servo
4. Connect your hardware as per the component connections (explained in the usage section).
5. Compile the code and upload it to your Arduino Mega 2560.
6. After the build, run the `postbuild.bat` file to copy the generated `.elf` file into your `.ino` folder.

## Hardware and Library Dependencies

### Hardware:
- **Arduino Mega 2560**: Microcontroller to control all the modules.
- **Wind Meter**: Anemometer and wind vane to measure wind speed and direction.
- **NEO-6M GPS Module**: GPS for tracking the sailboard's location and heading.
- **Servo Motor**: To adjust the fin angle.
- **LoRa Module (SX1278)**: For long-range wireless communication.

### Libraries:
- **TinyGPS++** (v1.0.3): For GPS parsing.
- **LoRa** (v0.8.0): For radio communication using the LoRa module.
- **Servo** (built-in): To control the motor for fin adjustment.

## Usage

1. **Connect Hardware**: Ensure all components are correctly wired:
   - **Wind Meter** connected to the appropriate analog and digital pins.
   - **GPS Module** connected to the correct UART (Serial1 on Mega).
   - **Servo Motor** connected to a PWM pin (e.g., pin 9).
   - **LoRa Module** connected via SPI pins.

2. **Run the System**: Power the Arduino Mega 2560.
   - The system will start reading wind and GPS data, adjust the fin automatically, and broadcast the position via LoRa.

3. **Monitor Serial Output**:
   - Open the Serial Monitor in the Arduino IDE to see real-time data like wind speed, direction, GPS coordinates, and fin angle.

## Post-build Script

After compiling and uploading the code to your Arduino, run `postbuild.bat` to copy the compiled `.elf` file to the project directory. This file is useful for debugging and testing with simulation tools like GDB or for further analysis.

## Contribution

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

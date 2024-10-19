
# SailBoardPolit Project - Feature 2: Bluetooth Connectivity

## Overview

This version of the SailBoardPolit project adds **Bluetooth Connectivity**. The sailboard can now be controlled or monitored remotely via Bluetooth communication.

### New Feature:
1. **Bluetooth Connectivity**:
   - Added support for Bluetooth communication using SoftwareSerial.
   - Bluetooth module listens for data and sends acknowledgments via Bluetooth.

### Files Added:
- `BluetoothModule.cpp` and `BluetoothModule.h`: New files to handle Bluetooth communication.

### How to Use:
- The Bluetooth module is set up on pins 10 (TX) and 11 (RX).
- It is configured to communicate at 9600 baud rate.
- You can send data to the sailboard via Bluetooth, and the board will acknowledge the command.

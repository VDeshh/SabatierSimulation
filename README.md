# SabatierSimulation
This is a repository to write reactor firmware, as well as a software simulated reactor system (no access to hardware).

## Equipment
 - x2 Arduino Mega 
 - wires to connect
 - (optional) multimeter

## Navigating Folder
- ReactorSim.ino simulates the reactor hardware (Mass flow controllers, Heat tape)
- Mfc.h and Heattape.h are libraries to control hardware

         Mfc.h    Heattape.h                  ReactorSim.ino 
               \ /                                 |
                |                                  |
         Firmware Mega --------------> Reactor Simulator Mega
                ^                                  
                |                                  
               GUI                              


### Steps to Run
After cloning repo locally, please follow the steps:
1. Install VS Code with Arduino Extension
2. Initialize baud rate to 115200, select COM port for Reactor Simulator mega.
3. Upload ReactorSim.ino 
4. Open Serial monitor in VS Code
5. Give some test setpoints (3.3V, 0V, 5V) into pin A0. In serial monitor flow rate should approach setpoint and lock on.



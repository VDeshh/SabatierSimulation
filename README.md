# SabatierSimulation
This is a repository to write reactor firmware, as well as a software simulated reactor system (no access to hardware).

## Equipment
 - x2 Arduino Mega 
 - wires to connect
 - (optional) multimeter

## Navigating Folder
- ReactorSim.ino runs on one Arduino Mega to simulate the reactor hardware (Mass flow controllers, Heat tape)
- Mfc.h and Heattape.h are libraries to run firmware code on second Ardunio Mega, which controls hardware

                                  Mfc.h    Heattape.h                  ReactorSim.ino 
                                       \ /                                 |
                                        |                                  |
                                 Firmware Mega -------------------> Reactor Simulator Mega 


### Steps to Run
After cloning repo locally, please follow the steps:
1. Install VS Code with Arduino Extension
2. Initialize baud rate to 115200, select COM port.
3. Upload ReactorSim.ino to one Ardunio Mega (Simulating hardware)
4. 


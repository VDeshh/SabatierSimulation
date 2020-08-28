/*
  Mass Flow Controller firmware.
  This is a code meant to control MFC operations. 

  Made 25-07-2020
  by Noah Caleanu

*/

#include "Mfc.h"
#include "Arduino.h"

// declare the pins
#define SETPOINT_H2 9 // H2
#define FLOWRATE_H2 A0 

#define SETPOINT_CO2 11 // CO2
#define FLOWRATE_CO2 A1

#define SETPOINT_Ar 13 // Ar
#define FLOWRATE_Ar A2


#define PURGE_PERIOD 10 // period to delay to purge in milliseconds
#define DISCONNECT 0    // duty cycle to send 0V
#define CONNECT 255     // duty cycle to send 5V


MassFlowController::MassFlowController(/*int unique_id*/) {
    int rate = 0; // set to 0 so it isnt garbage value, but it should be read from analog pin in method below
    
    // Set input and output pins for each of the MFCs here
    pinMode(FLOWRATE_H2, INPUT); 
    pinMode(SETPOINT_H2, OUTPUT);

    pinMode(FLOWRATE_CO2, INPUT); 
    pinMode(SETPOINT_CO2, OUTPUT);

    pinMode(FLOWRATE_Ar, INPUT); 
    pinMode(SETPOINT_Ar, OUTPUT);
    
}


/* ----------------------- PUBLIC METHODS --------------------------------------------------------------------*/

// setflow is function to take in a desired flowrate in L/min, convert to analog value, and apply it if above 0 and below 1023 
int MassFlowController::set_flow(float desired_flowrate, int MFC_ID){
   
}

// Read flowrate of certain MFC.
// Returns an analog value corresponding to flowrate
int MassFlowController::read_flow(int MFC_ID){
    // analog read flow rate from MFC with ID 
    
    
}


// Purge is fancy terms for opening valve 100%
void MassFlowController::purge(void) {
  // Only ever purge using the Argon MFC
}




/*
  Mass Flow Controller Simulation Module.
  This is meant to emulate the operations of MFC hardware we do not have access to right now

  Made 25-07-2020
  by Noah Caleanu

*/

#include "Mfc.h"
#include "Arduino.h"

// declare the pins
#define OUTPUT_H2 9 // H2
#define READING_H2 A0 

#define OUTPUT_TO_MFC_CO2 11 // CO2
#define MASSFLOW_READING_CO2 A1

#define OUTPUT_TO_MFC_Ar 13 // Ar
#define MASSFLOW_READING_Ar A2

#define PURGE_PIN 3 // purge pin
#define ARGON_SETPOINT_SW 5

#define H2_ID 1
#define CO2_ID 2
#define Ar_ID 3

#define PURGE_PERIOD 10 // period to delay to purge in milliseconds
#define DISCONNECT 0 // duty cycle to send 0V
#define CONNECT 255 // duty cycle to send 5V


Mfc::Mfc(int dummy_num) {
    int id = dummy_num;
    int rate = 0;
    int* rate_p = &rate;

    // pins for a single for a single MFC
    pinMode(OUTPUT_H2, OUTPUT); // Declare the output to the MFC
    pinMode(READING_H2, INPUT); // pin for flowrate read by MFC
    // pinMode(PURGE_PIN, OUTPUT);
    // pinMode(ARGON_SETPOINT_SW, OUTPUT);
}


/* ----------------------- PUBLIC METHODS --------------------------------------------------------------------*/

// init function sets valves closed bc the MFCs are nominally closed
void Mfc::init(int dummy_num){
    analogWrite(OUTPUT_H2, DISCONNECT); // NC valves  
}

// setflow is function to take in a desired flowrate and apply it if valid
int Mfc::set_flow(float desired_flowrate){
    int rate;

    // flow rate below 0 L/min is nonsensical 
    if (desired_flowrate < 0){
        rate = 0;
    }
    // MFC doesnt operate above 2 L/min
    else if (desired_flowrate > 2) {
        rate = 1023;
    }
    // Valid input in range [0, 2] L/min
    else {
        rate = ((desired_flowrate/2)*1023); // Linearly map the input to an int in range 0-1023
    }
    // Apply setpoint to the corresponding MFC
    analogWrite(OUTPUT_H2, rate);

    return rate;
}

// Read flow returns the value from a specified MFC
//  outputs: reading: measured from mfc sensor. 
int Mfc::read_flow(void){
    // read flow rate from MFC
    int reading = 0;
    reading = analogRead(READING_H2);  

    return reading;
}


// Purge is fancy terms for opening valve 100%
void Mfc::purge(void) {
   analogWrite(OUTPUT_H2, CONNECT); // open valve all the way
}




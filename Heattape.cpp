/*
  Heat tape firmware .
  This is meant to control the heat tape pcb 

  Made 11-08-2020
  by Noah Caleanu (noahcaleanu152@gmail.com)

*/
#include "Heattape.h"
#include "Arduino.h"

#define HEAT_PULSE 3

Heattape::Heattape(){
    int temp;
    this->temp = 0; // start at 0 for ease of testing. Realistically we will start at what ever the read temp is

    // set pins here
    pinMode(HEAT_PULSE, OUTPUT);
}


/* ----------------------- PUBLIC METHODS --------------------------------------------------------------------*/

void Heattape::inc_temp(int signal){
    
    // If we receive pulse we will increase temperature.
    if(signal){
        digitalWrite(HEAT_PULSE, HIGH);
        delay(100);
        digitalWrite(HEAT_PULSE, LOW);
    }
     
}
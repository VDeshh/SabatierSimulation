/*
  Heattape Simulation Module.
  This is meant to emulate the operations of heattape hardware we do not have access to right now

  Made 11-08-2020
  by Noah Caleanu (noahcaleanu152@gmail.com)

*/
#include "Heattape.h"
#include "Arduino.h"

Heattape::Heattape(){
    int temp;
    this->temp = 0;
    // set pins here

}


/* ----------------------- PUBLIC METHODS --------------------------------------------------------------------*/

void Heattape::inc_temp(int signal){
    // Read analog temperature from the the Heattape
    // for now just use one datapoint but in reactor there will be like 12

    // start at 0 for ease of testing. Realistically we will start at what ever the read temp is
    //int temperature = 0;

    if(signal == 1){
        this->temp += 1;          // increment while pulse signal high
        delay(100);
    }

    Serial.print("Temperature: ");    
    Serial.println(this->temp);
}
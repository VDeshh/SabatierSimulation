/*
  Reactor Simulation.

  Made by Noah Caleanu on 25-07-2020
  Authors: Noah Caleanu,

*/
#include <stdio.h>
#include <stdlib.h>

#include "Mfc.h"
#include "Heattape.h"


#define MFC_OUT 9
#define MFC_IN A0 

// Note this should NOT be here normally and is only here for testing. this should be on firmware arduino
MassFlowController MFC_Controller; // Controls all MFCs
Heattape heat_tape;               // Controls heat tape

// Setup runs once
void setup() {
  Serial.begin(115200);
  Serial.println("MFC Simulation Beginning... ");

  // Pin to output a flowrate with mock data
  pinMode(MFC_OUT, OUTPUT);
  digitalWrite(MFC_OUT, LOW);
  // Pin to read flowrate
  pinMode(MFC_IN, INPUT);

  
  // Print ID and rate of the reactor firmware object
  delay(500); // leave this delay in to see initial values printed below
  Serial.print("MFC rate: ");
  Serial.println(MFC_Controller.rate);
  Serial.println();
  
}


enum RSIPacketClass {
  Status = 'S',
  Data = 'D'
};

enum RSIPacketDescriptor
{
  Temperature = 1,
  FlowRate = 2,
  Pressure = 3,
  Scale = 4
};

typedef struct RSIPacket {
  uint8_t p_class;
  uint8_t p_descriptor;
  uint8_t ndata;
  uint8_t ldata;
  uint8_t data[40];
};

struct FlowPacket {
  uint16_t flow_id;
  uint32_t timestamp;
  float datapoint;
};

// random initial value mock data
float virt_flow = 500;

int setpoint = 0;

// Loop runs over and over
void loop() {
  RSIPacket packet = RSIPacket();
  packet.p_class = Data;
  packet.p_descriptor = FlowRate;

  packet.ndata = 4;
  packet.ldata = sizeof(struct FlowPacket);
  
  for (int i = 0; i < packet.ndata; i++)
  {
    struct FlowPacket fp = FlowPacket();
    fp.flow_id = i + 1;
    fp.timestamp = millis();
    fp.datapoint = virt_flow + (random(0, 10) - 5) / 20.0;
    //Serial.println(fp.datapoint);
    
    memcpy(
      packet.data + i * sizeof(struct FlowPacket),
      &fp, sizeof(struct FlowPacket));
      delay(random(0, 50));

    }

    /* Flow control operation */

    setpoint = analogRead(MFC_IN);
    Serial.print("Set point received: ");
    Serial.println(setpoint);

    if (isValid(setpoint)){
      Serial.println("Valid");
      
      // Increase flow if setpoint is larger
      if (virt_flow < setpoint) {
        virt_flow += ((float)random(0, 30)) ; 
      }
      // decrease flow is setpoint smaller than flow
      else {
        virt_flow += ((float)random(-30, 0)) ;
      }

    // Received setpoint not physically possible. Ignore
    }
    else {
      Serial.println("Not valid.");
    }

    
    /* Flow meter operation */

    // Flow meter outputs analog value rate 0 - 1023 
    if ( virt_flow < 0) {
      virt_flow = 0;
      analogWrite(MFC_OUT, 0);
    }
    else if( virt_flow > 1023) {
      virt_flow = 1023;
      analogWrite(MFC_OUT, 255);
    }
    else {
        analogWrite(MFC_OUT, virt_flow/4);
    }

    // Print mock reactor data
   
    Serial.print("Mock flowrate is: "); 
    Serial.println(virt_flow);
    delay(random(100, 250));
    Serial.print("Voltage equivalent rate: ");
    Serial.print(5*((float)virt_flow/1024));
    Serial.println(" V");
    Serial.println();
    delay(100);
    
    delay(1000);

}

// function to ensure setpoint not too high or too low
bool isValid (int val) {
    if (val < 1) {
      return 0;
    }
    else if(val > 1022) {
      return 0;
    }
    else {
        return 1;
    }

}
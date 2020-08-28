/*
  Heattape Firmware
  This is meant to emulate the operations of heattape hardware we do not have access to right now

  Made 11-08-2020
  by Noah Caleanu (noahcaleanu152@gmail.com)

*/
#ifndef HEATTAPE_H
#define HEATTAPE_H

class Heattape {
    public:
        Heattape();
        int temp;           // current heat tape temperature
        void inc_temp(int); // Heattape PCB takes in digital pulse and increases temp for a set time based on that.
};


#endif
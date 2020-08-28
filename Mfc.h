/*
  Mass Flow Controller Simulation Module. 
  This is meant to emulate the operations of MFC hardware we do not have access to right now

  Made 25-07-2020
  by Noah Caleanu

*/

#ifndef MFC_H
#define MFC_H

class Mfc {
    public: 
        Mfc(int);
        int ID;
        int rate;
        void init(int);
        int set_flow(float);
        int read_flow(void);
        void purge(void);
};

#endif
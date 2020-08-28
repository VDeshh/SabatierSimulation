/*
  Mass Flow Controller Firmware template 

  Made 25-07-2020 by Noah Caleanu
  Authors: Noah Caleanu, 
*/

#ifndef MFC_H
#define MFC_H

class MassFlowController {
    public: 
        MassFlowController();
        //int ID; // we need IDs to differentiate between the 3 MFCs
        int rate; // each MFC will have a flowrate
        int set_flow(float, int);  // function to set flow for a specific MFC 
        int read_flow(int);  // function to read flowrates for MFCs
        void purge(void);     // function to purge reactor with Argon
};

#endif
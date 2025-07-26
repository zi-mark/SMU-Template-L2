#include "SMU_Lib/drivercontrol.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

#ifdef Exam
    #if Exam == 1
    void DC(){
        int lv, rv;
        // bool save;
        Stop(coast);
        Brain.Screen.clearScreen(black);
        while(1){

            #if DriversHabit == 1
            lv = Con.Axis3.position() + Con.Axis4.position();
            rv = Con.Axis3.position() - Con.Axis4.position();

            #elif DriversHabit == 2
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            #endif

            if(abs(lv) < 5) lv = 0;
            if(abs(rv) < 5) rv = 0;
            SpinLR(lv, rv);

        }
    }
    #else
    void DC(){
        int lv, rv;
        bool save;
        Stop(coast);
        Brain.Screen.clearScreen(black);
        while(1){

            #if DriversHabit == 1
            lv = Con.Axis3.position() + Con.Axis4.position();
            rv = Con.Axis3.position() - Con.Axis4.position();

            #elif DriversHabit == 2
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            #endif

            if(abs(lv) < 5) lv = 0;
            if(abs(rv) < 5) rv = 0;
            SpinLR(lv, rv);

        }
    }
    #endif
#endif
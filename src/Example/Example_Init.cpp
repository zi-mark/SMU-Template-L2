#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

#ifdef Exam
    #if Exam == 1
    void Init(){
        
        CH.GR->calibrate();

        while(CH.GR->isCalibrating()) continue;

    }
    #else 
    void Init(){

        CH.GR->calibrate();
        ResetPosition();

        while(CH.GR->isCalibrating()) continue;
    }
    #endif
#endif
#include "definer.h"
#include "SMU_Lib/functional.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"

#ifdef Exam
    #if Exam == 1
    void Init(){
        
        CH.GR->calibrate();
        ResetPosition();
        if(CLSensor.installed()) CLSensor.setLightPower(CLData.light_power);

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
#include "definer.h"
#include "SMU_Lib/functional.h"
#include "robot-config.h"
#include "SMU_Lib/chassis.h"

#ifdef Exam
    #if Exam == 1
    //初始化函数，插上场控后到自动开始前执行，不能执行有关马达运动和遥控器按键运动的代码
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
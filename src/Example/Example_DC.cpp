#include "SMU_Lib/drivercontrol.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chassis.h"
#include "SMU_Lib/functional.h"
#include "SMU_Lib/PressureButton.h"

#ifdef Exam
    #if Exam == 1
    void DC(){
        int lv, rv;
        Stop(coast);
        Brain.Screen.clearScreen(black);
        PressureButton Abtn(Con.ButtonA);
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

            if(Abtn.JustPressed()){Hook.set(!Hook.value());}
            //单个按键控制气缸开关写法

            if(Con.ButtonX.pressing()) Hook.set(1);
            else if(Con.ButtonB.pressing()) Hook.set(0);
            //两个按键控制气缸开关写法

            if(Con.ButtonL1.pressing()) Sucks.Spin(100);
            else if(Con.ButtonL2.pressing()) Sucks.Spin(-100);
            else Sucks.Stop();
            //左右肩键控制吸盘正反转及停止

        }
    }
    #else//默认的手动函数，防止突然想测新机器的时候报错
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
#include "SMU_Lib/autonomous.h"
#include "SMU_Lib/drivercontrol.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

//测自动断点
void Break(){
    if(!Com.isFieldControl() && !Com.isCompetitionSwitch()){
    while(!Con.ButtonA.pressing()) continue;
    }
}

int ProgramChoice = 0;
//屏幕选程序
void ProgramChoosing(){
    timer T;
    bool save = 1;
    T.reset();
    Con.Screen.setCursor(1,1);
    Con.Screen.print(Auto[ProgramChoice].name);
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Auto[ProgramChoice].name);
    while(T.time() <= 3000){
        if(Brain.Screen.pressing()){
            if(save){
                save = 0;
                ProgramChoice++;
                if(ProgramChoice == MaxChoice) ProgramChoice = 0;

                Con.Screen.clearLine(1);
                Con.Screen.setCursor(1,1);
                Con.Screen.print(Auto[ProgramChoice].name);

                Brain.Screen.clearLine(1);
                Brain.Screen.setCursor(1,1);
                Brain.Screen.print(Auto[ProgramChoice].name);

                T.reset();
            }
        }
        else save = 1;
        task::sleep(100);
    }
}

//测试函数
void Test(){

    while(1){
        if(Con.ButtonUp.pressing()){
            LMs.ResetPosition();
            RMs.ResetPosition();
            PMGo(24);
            Brain.Screen.newLine();
            Brain.Screen.print((LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2);
        }
        else if(Con.ButtonDown.pressing()){
            LMs.ResetPosition();
            RMs.ResetPosition();
            PMGo(-24);
            Brain.Screen.newLine();
            Brain.Screen.print((LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2);
        }
        else if(Con.ButtonA.pressing()){
            PMTurnTo(90);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonY.pressing()){
            PMTurnTo(-90);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonX.pressing()){
            PMTurnTo(0);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonB.pressing()){
            PMTurnTo(180);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
    }
    
}



//MT程序主体
void Motor_Test(){
    
}

//自动函数与函数名链接
Autos Auto[MaxChoice]{
    {"DC ", &DC, 1}, 
    {"RR ", &RR, 1}, 
    {"RR2 ", &RR2, 1},
    {"RR3 ", &RR3, 1},
    {"RL ", &RL, 1}, 
    {"RL2 ", &RL2, 1}, 
    {"RL3 ", &RL3, 1}, 
    {"BL ", &BL, 0},
    {"BL2 ", &BL2, 0}, 
    {"BL3 ", &BL3, 0},
    {"BR ", &BR, 0},
    {"BR2 ", &BR2, 0},
    {"BR3 ", &BR3, 0},
    {"SK ", &Skills, 1},
    {"Test", &Test, 1},
    {"MT ", &Motor_Test, 1}
};

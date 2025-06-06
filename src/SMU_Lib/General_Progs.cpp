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
            ResetPosition();
            PMGo(24);
            Brain.Screen.newLine();
            Brain.Screen.print(AverPosition(deg));
        }
        else if(Con.ButtonDown.pressing()){
            ResetPosition();
            PMGo(-24);
            Brain.Screen.newLine();
            Brain.Screen.print(AverPosition(deg));
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

//MT专属
void Change_Groups(int Motor_Group, int *Motor_Count, motor** Motor_Groups){
        switch (Motor_Group)
        {
        case 1:
            *Motor_Groups = LMs;
            *Motor_Count = Chassis_Count;
            Con.Screen.clearLine(1);
            Con.Screen.setCursor(1,1);
            Con.Screen.print("LMs");
            break;
        case 2:
            *Motor_Groups = RMs;
            *Motor_Count = Chassis_Count;
            Con.Screen.clearLine(1);
            Con.Screen.setCursor(1,1);
            Con.Screen.print("RMs");
            break;
        case 3:
            *Motor_Groups = Sucks;
            *Motor_Count = Suck_Count;
            Con.Screen.clearLine(1);
            Con.Screen.setCursor(1,1);
            Con.Screen.print("Sucks");
            break;
        case 4:
            *Motor_Groups = Lifts;
            *Motor_Count = Lift_Count;
            Con.Screen.clearLine(1);
            Con.Screen.setCursor(1,1);
            Con.Screen.print("Lifts");
        default:
            break;
        }
}

//MT程序主体
void Motor_Test(){
    Con.Screen.clearScreen();
    motor* Motor_Groups = LMs;
    int Motor_Choice = 1, Motor_Count = Chassis_Count, Motor_Number = 0, MaxChoice = 4;
    bool UpSave = 1, DownSave = 1, LeftSave = 1, RightSave = 1;
    Change_Groups(Motor_Choice, &Motor_Count, &Motor_Groups);
        while(1){
            if(Con.ButtonUp.pressing()){
                if(UpSave){
                    UpSave = 0;
                    Motor_Choice = Motor_Choice==MaxChoice ? 1 : Motor_Choice+1;
                    Change_Groups(Motor_Choice, &Motor_Count, &Motor_Groups);
                }
            }
            else UpSave = 1;

            if(Con.ButtonDown.pressing()){
                if(DownSave){
                    DownSave = 0;
                    Motor_Choice = Motor_Choice==1 ? MaxChoice : Motor_Choice-1;
                    Change_Groups(Motor_Choice, &Motor_Count, &Motor_Groups);
                }
            }
            else DownSave = 1;

            if(Con.ButtonLeft.pressing()){
                if(LeftSave){
                    LeftSave = 0;
                    Motor_Number = Motor_Number==0 ? Motor_Count-1 : Motor_Number-1;
                    Con.Screen.clearLine(2);
                    Con.Screen.setCursor(2,1);
                    Con.Screen.print(Motor_Number);
                }
            }
            else LeftSave = 1;

            if(Con.ButtonRight.pressing()){
                if(RightSave){
                    RightSave = 0;
                    Motor_Number = Motor_Number==Motor_Count-1 ? 0 : Motor_Number+1;
                    Con.Screen.clearLine(2);
                    Con.Screen.setCursor(2,1);
                    Con.Screen.print(Motor_Number);
                }
            }
            else RightSave = 1;

            if(Con.ButtonA.pressing()) Motor_Groups[Motor_Number].spin(fwd, 100, pct);
            else if(Con.ButtonB.pressing()) Motor_Groups[Motor_Number].spin(fwd, -100, pct);
            else Motor_Groups[Motor_Number].stop(coast);
        }
}

//自动函数与函数名链接
Autos Auto[]{
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

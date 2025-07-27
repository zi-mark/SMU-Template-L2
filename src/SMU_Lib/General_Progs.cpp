#include "SMU_Lib/autonomous.h"
#include "SMU_Lib/functional.h"
#include "robot-config.h"
#include "SMU_Lib/PressureButton.h"

//测自动断点
void Break(){
    if(!Com.isFieldControl() && !Com.isCompetitionSwitch()){
    while(!Con.ButtonA.pressing()) continue;
    }
}

void Empty(){};

void Test(){
    // DC_Sorting(1);
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
void Auto_Test(){

    while(1){
        if(Con.ButtonUp.pressing()){
            ResetPosition();
            PMGo(24);
            Brain.Screen.newLine();
            Brain.Screen.print(AveragePosition(deg));
        }
        else if(Con.ButtonDown.pressing()){
            ResetPosition();
            PMGo(-24);
            Brain.Screen.newLine();
            Brain.Screen.print(AveragePosition(deg));
        }
        else if(Con.ButtonA.pressing()){
            PMTurnTo(90);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
        }
        else if(Con.ButtonY.pressing()){
            PMTurnTo(-90);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
        }
        else if(Con.ButtonX.pressing()){
            PMTurnTo(0);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
        }
        else if(Con.ButtonB.pressing()){
            PMTurnTo(180);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(CH.GR->rotation());
        }
    }
    
}

void PrintMotorGroups(int Group_Num, int Motor_Num){
    Con.Screen.clearScreen();
    Con.Screen.setCursor(1,1);
    Con.Screen.print(MotorGroups[Group_Num].Name());
    Con.Screen.print(" ");
    Con.Screen.print(Motor_Num + 1);
}
    

//MT程序主体
void Motor_Test(){

    int Group_Num = 0, Motor_Num = 0;
    PressureButton BtnL(Con.ButtonLeft);
    PressureButton BtnR(Con.ButtonRight);
    PressureButton BtnU(Con.ButtonUp);
    PressureButton BtnD(Con.ButtonDown);

    PrintMotorGroups(Group_Num, Motor_Num);

    while(1){
        
        if(BtnR.JustPressed()){
            Motor_Num++;
            if(Motor_Num >= MotorGroups[Group_Num].Count()) Motor_Num = 0;
            PrintMotorGroups(Group_Num, Motor_Num);
        }
        else if(BtnL.JustPressed()){
            Motor_Num--;
            if(Motor_Num <= -1) Motor_Num =  MotorGroups[Group_Num].Count() - 1;
            PrintMotorGroups(Group_Num, Motor_Num);
        }
        else if(BtnU.JustPressed()){
            Group_Num++;
            if(Group_Num >= MotorGroupsCount) Group_Num = 0;
            if(Motor_Num >= MotorGroups[Group_Num].Count()) Motor_Num = 0;
            Motor_Num = 0;
            PrintMotorGroups(Group_Num, Motor_Num);
        }
        else if(BtnD.JustPressed()){
            Group_Num--;
            if(Group_Num <= -1) Group_Num = MotorGroupsCount - 1;
            if(Motor_Num >= MotorGroups[Group_Num].Count()) Motor_Num = 0;
            PrintMotorGroups(Group_Num, Motor_Num);
        }
        task::sleep(100);
        if(Con.ButtonA.pressing()) MotorGroups[Group_Num].Motors()[Motor_Num].spin(forward, 100, pct);
        else if(Con.ButtonB.pressing()) MotorGroups[Group_Num].Motors()[Motor_Num].spin(reverse, 100, pct);
        else MotorGroups[Group_Num].Motors()[Motor_Num].stop(coast);
    }


}



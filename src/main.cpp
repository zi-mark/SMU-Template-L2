/*
 *
 * 你好，我是SMU-Template的编写者Mark Ma，很高兴您使用SMU-Template作为您VEX之旅的模板程序！
 *
 * 请您注意，此模板为L1！！L1！！L1级别难度模板
 *   **L1**  |  L2  |  L3  
 * 请根据队伍自身水平选择相应模板使用
 * 
 * 请您注意，Student Center Policy是VEX项目中非常核心的价值理念和行为准则
 * 也就意味着在任何情况下教练都不应直接帮助学生进行编程操作
 * 不可否认，模板库的出现极大的减少了重复工作，增加了编程效率
 * 使用与队伍水平匹配的模板进行编程符合SCP的要求
 * 但请您注意，模板库并不代表教练可以直接帮助学生编程
 * 请您在使用模板库时，务必遵守Student Center Policy
 * 保证程序库内容水平与队伍编程手水平相当
 * 以免造成不必要的麻烦与冲突
 * 
 * 本库为本人近年来参赛经验总结而来，由于本人不是专职的编程手，代码方面有诸多不合理的地方，请大家谅解
 * 如您需要更严谨，更丰富的内容请寻找L2，L3级别的SMU-Template，谢谢!
 * 
 * Copyright (c) 2025 SMU Robotics Team
 */

#include "vex.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/autonomous.h"
#include "SMU_Lib/drivercontrol.h"

using namespace vex;

brain Brain;
controller Con;
competition Com;

timer Auto_T;

int main(){
    Brain.Screen.clearScreen();
    #ifndef Testing
    ProgramChoosing();
    #endif
    Init();
    #ifndef Testing
    if(Com.isCompetitionSwitch() || Com.isFieldControl()){
        Com.drivercontrol(DC);
        Com.autonomous(Auto[ProgramChoice].Funcs);
        Con.Screen.print("Competition ");
    }
    else{
        Con.Screen.print("Not Competition ");
        while(!Con.ButtonA.pressing()) continue;
        Auto_T.reset();
        Auto[ProgramChoice].Funcs();
        Con.Screen.newLine();
        Con.Screen.print(Auto_T.value());
        DC();
    }
    #else
    Con.Screen.print("Init Compelete");
    while(!Con.ButtonA.pressing()) continue;
    Auto_T.reset();

    Test();
    
    Con.Screen.print(Auto_T.value());
    DC();
    #endif
    
 while(1) wait(10,msec);
}

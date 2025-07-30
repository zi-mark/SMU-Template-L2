/*
 *
 * 你好，我是SMU-Template的编写者Mark Ma，很高兴您使用SMU-Template作为您VEX之旅的模板程序！
 *
 * 请您注意，此模板为L2！！L2！！L2级别难度模板
 *   L1  |  **L2**  |  L3
 * 请根据队伍自身水平选择相应模板使用
 * 
 * L2相比L1添加了PID算法，同时保留了PM算法，学生可以根据不同的情况选择使用
 * L2也在函数上进行更系统，深层次的打包，降低出错的概率
 * 
 * L2需要学生在L1的基础上掌握以下知识：
 * 
 *  - PID算法
 *  - 指针
 *  - 结构体
 *  - 类
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
 * 如您需要更严谨，更丰富的内容请寻找L3级别的SMU-Template，谢谢!
 * 如您需要更简单，更明了的内容请寻找L1级别的SMU-Template，谢谢！
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
    if(Com.isCompetitionSwitch() || Com.isFieldControl()){
        Com.drivercontrol(DC);
    }
    #ifndef Testing
    ProgramChoosing();
    Init();

    if(Com.isCompetitionSwitch() || Com.isFieldControl()){
        // Com.drivercontrol(DC);
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
    Init();
    Con.Screen.print("Init Compelete | Press A to start"); 
    while(!Con.ButtonA.pressing()) continue;
    Auto_T.reset();

    Test();

    Con.Screen.newLine();
    Con.Screen.print(Auto_T.value());
    DC();
    #endif
    
    while(1) wait(10,msec);
}

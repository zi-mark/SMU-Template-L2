#include "robot-config.h"
#include "definer.h"

using namespace vex;

#ifdef Exam
    #if Exam == 1

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT1, ratio6_1, 0);
    motor R2(PORT2, ratio6_1, 0);
    motor R3(PORT5, ratio6_1, 0);

    motor L1(PORT10, ratio6_1, 1);
    motor L2(PORT9, ratio6_1, 1);
    motor L3(PORT6, ratio6_1, 1);

    motor Left_Motors[] = {L1, L2, L3};
    motor Right_Motors[] = {R1, R2, R3};

    MotorGroup Left_Motor_Group(Left_Motors, 3, "LMs");
    MotorGroup Right_Motor_Group(Right_Motors, 3, "RMs");

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 1.375;
    double ChasisRatio = 1;
    double ChasisWidth = 7.5;

    inertial GR(PORT21);

    ChassisData CH = {
        Left_Motors,// 左侧马达组
        Right_Motors,// 右侧马达组
        &GR,// 惯性传感器
        &Brain.Screen,// 显示屏
        3,// 轮子数量
        WheelRadius,// 轮子半径
        ChasisRatio,// 齿轮比 马达/轮子齿
        ChasisWidth,// 车身宽度
        {0.5, 10.0, 0.5}, // PMG: kp, ki, kd
        {0.5, 10.0, 0.5}, // PMT: kp, ki, kd
        {0.5, 10.0, 0.5}, // PMDT: kp, ki, kd
        {0.1, 0.01, 0.001, 0.1, 0}, // PIDG: kp, ki, kd, startI, offset
        {0.1, 0.01, 0.001, 0.1, 0}, // PIDT: kp, ki, kd, startI, offset
        {0.1, 0.01, 0.001, 0.1, 0} // PIDDT: kp, ki, kd, startI, offset
    };


    motor LiftL(PORT19, ratio36_1, 1);
    motor LiftR(PORT12, ratio36_1, 0);
    // motor Lift(PORT10, ratio36_1, 0);

    motor Lift_Motors[] = {LiftL, LiftR};
    MotorGroup Lifts(Lift_Motors, 2, "Lifts");

    motor Suck(PORT20, ratio6_1, 1);
    motor Suck2(PORT11, ratio6_1, 0);

    motor Suck_Motors[] = {Suck, Suck2};
    MotorGroup Sucks(Suck_Motors, 2, "Sucks");

    MotorGroup MotorGroups[] = {Left_Motor_Group, Right_Motor_Group, Lifts, Sucks};
    int MotorGroupsCount = 4;

    //惯性传感器(端口)
    optical CLSensor(PORT20);

    //电磁阀(三线接口)
    digital_out Hook(Brain.ThreeWirePort.A);
    
    #endif

#endif
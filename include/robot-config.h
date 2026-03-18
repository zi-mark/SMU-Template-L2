#include "vex.h"
#include "SMU_Lib/motor_group.h"
#include "SMU_Lib/functional.h"
#include "SMU_Lib/chassis.h"


using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern MotorGroup Sucks;
extern MotorGroup Sucks2;
extern MotorGroup Sucks3;

extern MotorGroup Lifts;
extern MotorGroup Levers;

extern MotorGroup MotorGroups[];
extern int MotorGroupsCount;

extern digital_out Hook;
extern digital_out Tongue;
extern digital_out Wing;
extern digital_out LWing;
extern digital_out RWing;
extern digital_out Needle;
extern digital_out Raise;
extern digital_out Cap;

extern optical CLSensor;
extern ColorData CLData;
extern distance Dis;

extern thread CL;
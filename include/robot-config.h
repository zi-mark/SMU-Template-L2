#include "vex.h"
#include "SMU_Lib/motor_group.h"
#include "SMU_Lib/functional.h"
#include "SMU_Lib/chasis.h"


using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern MotorGroup Sucks;
extern MotorGroup Sucks2;

extern MotorGroup Lifts;

extern MotorGroup MotorGroups[];
extern int MotorGroupsCount;

extern digital_out Hook;
extern digital_out Tongue;

extern optical CLSensor;
extern ColorData CLData;

extern thread CL;
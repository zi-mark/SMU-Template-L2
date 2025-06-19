#include "vex.h"
#include "SMU_Lib/motor_group.h"
#include "SMU_Lib/chasis.h"


using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern MotorGroup Sucks;

extern MotorGroup Lifts;

extern MotorGroup MotorGroups[];
extern int MotorGroupsCount;

extern digital_out Hook;

extern inertial GR;
extern optical CLSensor;

extern thread CL;
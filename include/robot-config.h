#include "vex.h"
#include "SMU_Lib/motor_groups.h"

#define Pi 3.14159265358979323846

using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern MotorGroup RMs;
extern MotorGroup LMs;

extern MotorGroup Sucks;

extern MotorGroup Lifts;

extern MotorGroup MotorGroups[];
extern int MotorGroupsCount;

extern digital_out Hook;

extern inertial GR;
extern optical CLSensor;

extern thread CL;

extern double WheelRadius, ChasisRatio, ChasisWidth;

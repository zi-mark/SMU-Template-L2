#include "vex.h"
#include "SMU_Lib/motor_groups.h"

#define Pi 3.14159265358979323846

using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern MotorGroups RMs;
extern MotorGroups LMs;

extern MotorGroups Sucks;

extern MotorGroups Lifts;

extern digital_out Hook;

extern inertial GR;
extern optical CLSensor;

extern thread CL;

extern double WheelRadius, ChasisRatio, ChasisWidth;

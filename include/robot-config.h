#include "vex.h"

#define Pi 3.14159265358979323846

using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern int Chassis_Count;
extern motor RMs[];
extern motor LMs[];

extern int Suck_Count;
extern motor Sucks[];

extern int Lift_Count;
extern motor Lifts[];

extern digital_out Hook;

extern inertial GR;
extern optical CLSensor;

extern thread CL;

extern double WheelRadius, ChasisRatio, ChasisWidth;

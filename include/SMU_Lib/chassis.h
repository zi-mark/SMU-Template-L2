#include "SMU_Lib/motor_group.h"
#include "SMU_Lib/calculator.h"

#define Pi 3.14159265358979323846

#pragma once

struct PM{
    double kp;
    double vmin;
    double offset;
};

struct PID{
    double kp;
    double ki;
    double kd;
    double startI;
    double offset;
};

struct  ChassisData
{
    vex::motor* LMs;
    vex::motor* RMs;
    vex::inertial* GR;
    vex::brain::lcd* Scn;
    int count;
    double WheelRadius;
    double ChasisRatio;
    double ChasisWidth;
    PM PMG;
    PM PMT;
    PM PMDT;
    PID PIDG;
    PID PIDT;
    PID PIDDT;
};

extern ChassisData CH;

void SpinLR(double leftSpeed, double rightSpeed, velocityUnits units = velocityUnits::pct);
void ResetPosition();
double AveragePosition(vex::rotationUnits units = vex::rotationUnits::deg);
void Stop(vex::brakeType bt = vex::brakeType::hold);
void Spin_T(double t, double speed = 90, velocityUnits velUnits = velocityUnits::pct);

void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
void TurnFor(double target, double v = 90, velocityUnits vu = velocityUnits::pct);



void PMTurnTo(double target);
void PMTurnFor(double target);
void PMDTurnTo(double rtn, double r);
void PMDTurnFor(double rtn, double r);
void PMLSwingTo(double target);
void PMRSwingTo(double target);
void PMGo(double target);

void PIDTurnTo(double target);
void PIDDTurnTo(double rtn, double r);
void PIDDTurnFor(double rtn, double r);
void PIDGo(double target);

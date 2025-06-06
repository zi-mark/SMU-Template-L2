#include "robot-config.h"
#include "definer.h"

void SpinLR(double lv, double rv, vex::velocityUnits vu = velocityUnits::pct);
void Stop(vex::brakeType bt = vex::brakeType::hold);
void ResetPosition();
double AverPosition(rotationUnits ru);

void Spin_T(double v, double t);

void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
void Turn();

struct PM{
    double kp;
    double vmin;
    double offset;
};

extern PM PMT;
extern PM PMDT;
extern PM PMG;

struct PID{
    double kp;
    double ki;
    double kd;
    double startI;
    double offset;
};

extern PID PIDG;
extern PID PIDT;
extern PID PIDDT;

extern void PMTurnTo(double target, double kp = PMT.kp, double vmin = PMT.vmin, double offset = PMT.offset);
extern void PMDTurnTo(double rtn, double r, double kp = PMDT.kp, double vmin = PMDT.vmin, double offset = PMDT.offset);
extern void PMGo(double target, double kp = PMG.kp, double vmin = PMG.vmin, double offset = PMG.offset);

extern void PIDTurnTo(double target, double kp = PIDT.kp, double ki = PIDT.ki, double kd = PIDT.kd, double startI = PIDT.startI, double offset = PIDT.offset);
extern void PIDDTurnTo(double rtn, double r, double kp = PIDDT.kp, double ki = PIDDT.ki, double kd = PIDDT.kd, double startI = PIDDT.startI, double offset = PIDDT.offset);
extern void PIDGo(double target, double kp = PIDG.kp, double ki = PIDG.ki, double kd = PIDG.kd, double startI = PIDG.startI, double offset = PIDG.offset);
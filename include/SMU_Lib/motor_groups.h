#include "vex.h"
#pragma once

using namespace vex;

class MotorGroup {
    private:
    vex::motor* motorGroup;
    int motorCount;
    const char* groupName;
    public:
    MotorGroup(vex::motor* motor, int count, const char name[]);
    vex::motor* Motors();
    int Count();
    const char* Name();

    void Spin(double speed, vex::velocityUnits units = vex::velocityUnits::pct);
    void Stop(vex::brakeType brakeType = vex::brakeType::hold);
    void ResetPosition();
    double AveragePosition(vex::rotationUnits units =  vex::rotationUnits::deg);
    bool isDone();
    void Spin_T(double t, double speed, vex::velocityUnits velUnits = vex::velocityUnits::pct);
    void SpinFor(double rotation, vex::rotationUnits units = vex::rotationUnits::deg, double speed = 80, vex::velocityUnits velUnits = vex::velocityUnits::pct, bool wait = true);

};
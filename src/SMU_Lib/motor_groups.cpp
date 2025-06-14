#include "SMU_Lib/motor_groups.h"
#include "definer.h"
#include "robot-config.h"

MotorGroups::MotorGroups(vex::motor* motor, int count, const char name[]) {
    motorGroup = motor;
    motorCount = count;
    groupName = name;
}

void MotorGroups::Spin(double speed, vex::velocityUnits units) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spin(fwd, speed, units);
    }
}

void MotorGroups::Stop(vex::brakeType brakeType) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].stop(brakeType);
    }
}

void MotorGroups::ResetPosition() {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].resetPosition();
    }
}

double MotorGroups::AveragePosition(vex::rotationUnits units) {
    double positionSum = 0.0;
    for (int i = 0; i < motorCount; i++) {
        positionSum += motorGroup[i].position(units);
    }
    return positionSum / motorCount;
}

void MotorGroups::Spin_T(double t, double speed, vex::velocityUnits velUnits) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spin(fwd, speed, velUnits);
    }
    task::sleep(t);
    Stop();
}

bool MotorGroups::isDone() {
    for (int i = 0; i < motorCount; i++) {
        if (!motorGroup[i].isDone()) {
            return false;
        }
    }
    return true;
}

void MotorGroups::SpinFor(double rotation, vex::rotationUnits units, double speed, vex::velocityUnits velUnits, bool wait) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spinFor(rotation, units, speed, velUnits, false);
    }
    if(wait){
        while(!isDone()) {
            task::sleep(10); 
        }
    }
}


#include "SMU_Lib/motor_group.h"

MotorGroup::MotorGroup(vex::motor* motor, int count, const char name[]) {
    motorGroup = motor;
    motorCount = count;
    groupName = name;
}

vex::motor* MotorGroup::Motors() { return motorGroup; }
int MotorGroup::Count() { return motorCount; }
const char* MotorGroup::Name() { return groupName; }

void MotorGroup::Spin(double speed, vex::velocityUnits units) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spin(fwd, speed, units);
    }
}

void MotorGroup::Stop(vex::brakeType brakeType) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].stop(brakeType);
    }
}

void MotorGroup::ResetPosition() {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].resetPosition();
    }
}

double MotorGroup::AveragePosition(vex::rotationUnits units) {
    double positionSum = 0.0;
    for (int i = 0; i < motorCount; i++) {
        positionSum += motorGroup[i].position(units);
    }
    return positionSum / motorCount;
}

double MotorGroup::AverageVelocity(vex::velocityUnits units) {
    double velocitySum = 0.0;
    for (int i = 0; i < motorCount; i++) {
        velocitySum += motorGroup[i].velocity(units);
    }
    return velocitySum / motorCount;
}

void MotorGroup::Spin_T(double t, double speed, vex::velocityUnits velUnits) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spin(fwd, speed, velUnits);
    }
    task::sleep(t);
    Stop();
}

bool MotorGroup::isDone() {
    for (int i = 0; i < motorCount; i++) {
        if (!motorGroup[i].isDone()) {
            return false;
        }
    }
    return true;
}

void MotorGroup::SpinFor(double rotation, vex::rotationUnits units, double speed, vex::velocityUnits velUnits, bool wait) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].spinFor(rotation, units, speed, velUnits, false);
    }
    if(wait){
        while(!isDone()) {
            task::sleep(10); 
        }
    }
}

void MotorGroup::SetMaxTourque(double torque) {
    for (int i = 0; i < motorCount; i++) {
        motorGroup[i].setMaxTorque(torque, percentUnits::pct);
    }
}


#include "SMU_Lib/calculator.h"
#include "vex.h"
#include <cmath>
PIDController::PIDController(double p, double i, double d, double start_i, double max_i, double slew_step) {
    kp = p; ki = i; kd = d;
    startI = start_i;
    maxIntegral = max_i;
    maxStep = slew_step;
    
    maxOutput = 12.0; // 默认电压模式
    minOutput = -12.0;
    
    reset(); // 初始化变量
}

void PIDController::reset() {
    error = 0;
    lastError = 0;
    integral = 0;
    derivative = 0;
    lastOutput = 0;
}

void PIDController::setOutputLimits(double min, double max) {
    minOutput = min;
    maxOutput = max;
}

void PIDController::setGains(double p, double i, double d) {
    kp = p; ki = i; kd = d;
}

double PIDController::calculate(double currentError) {
    error = currentError;
    
    // 1. 比例项
    double P = kp * error;

    // 2. 积分项 (带积分分离逻辑)
    if (fabs(error) < startI) {
        integral += error;
    } else {
        integral = 0;
    }
    
    // 积分限幅
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;
    
    double I = ki * integral;

    // 3. 微分项
    derivative = error - lastError;
    double D = kd * derivative;
    lastError = error;

    // 4. 计算原始输出
    double rawOutput = P + I + D;

    // 5. 限制最大/最小电压
    if (rawOutput > maxOutput) rawOutput = maxOutput;
    if (rawOutput < minOutput) rawOutput = minOutput;

    // 6. 应用 Slew Rate (加速度限制)
    double slewOutput = rawOutput;
    double delta = rawOutput - lastOutput;
    
    if (delta > maxStep) {
        slewOutput = lastOutput + maxStep;
    } else if (delta < -maxStep) {
        slewOutput = lastOutput - maxStep;
    }
    
    lastOutput = slewOutput;
    return slewOutput;
}
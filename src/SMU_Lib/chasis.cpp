#include "SMU_Lib/chasis.h" 
//赋予底盘左右速度
void SpinLR(double lv, double rv, vex::velocityUnits vu){
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].spin(fwd, lv, vu);
        RMs[i].spin(fwd, rv, vu);
    }
}
//令底盘停止
void Stop(brakeType bt){
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].stop(bt);
        RMs[i].stop(bt);
    }
}
//重置底盘编码器
void ResetPosition(){
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].resetPosition();
        RMs[i].resetPosition();
    }
}
//获取底盘平均编码器数值
double AverPosition(rotationUnits ru){
    double Position_Sum = 0.0;
    for(int i = 0; i < Chassis_Count; i++){
        Position_Sum += LMs[i].position(ru);
        Position_Sum += RMs[i].position(ru);
    }
    return (Position_Sum / (2.0 * Chassis_Count));
}
//直走一段时间
void Spin_T(double v, double t){
    SpinLR(v, v);
    task::sleep(t);
    Stop();
}

//内置编码器直走
void Go(double target, double v, velocityUnits vu){
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].spinFor(target, deg, v, vu, 0);
        RMs[i].spinFor(target, deg, v, vu, 0);
    }
    bool finish = 1;
    while(finish){
        for(int i = 0; i < Chassis_Count; i++){
            finish *= !LMs[i].isDone() * !RMs[i].isDone();
        }
    }
    Stop(hold);
}

//内置编码器转相对角度
void TurnFor(double target, double v, velocityUnits vu){
    target = target * ChasisWidth / (2 * WheelRadius * ChasisRatio);
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].spinFor(target, deg, v, vu, false);
        RMs[i].spinFor(-target, deg, v, vu, false);
    }
    bool finish = 1;
    while(finish){
        for(int i = 0; i < Chassis_Count; i++){
            finish *= !LMs[i].isDone() * !RMs[i].isDone();
        }
    }
    Stop(hold);

}

//PM转绝对角度
void PMTurnTo(double target, double kp, double vmin, double offset){
    double error, v;
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        v = kp * error;
        if(v < -vmin || v > vmin){
            SpinLR(v, -v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v < 0){
            SpinLR(-vmin, vmin, dps);
            Brain.Screen.clearScreen(green);
        }
        else{
            SpinLR(vmin, -vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
    }
    Stop(hold);
}

//PM转相对角度
void PMTurnFor(double target, double kp, double vmin, double offset){
    double error, v;
    target = target + GR.rotation();
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        v = kp * error;
        if(v < -vmin || v > vmin){
            SpinLR(v, -v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v < 0){
            SpinLR(-vmin, vmin, dps);
            Brain.Screen.clearScreen(green);
        }
        else{
            SpinLR(vmin, -vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
    }
    Stop(hold);
}


//PM直走
void PMGo(double target, double kp, double vmin, double offset){
    ResetPosition();
    double error, v;
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){
        error = target - AverPosition(deg);
        if(fabs(error) < offset) break;
        v = kp * error;
        if(v < -vmin || v > vmin){
            SpinLR(v,v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v > 0){
            SpinLR(vmin, vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
        else{
            SpinLR(-vmin, -vmin, dps);
            Brain.Screen.clearScreen(green);
        }
    }
    Stop(hold);
}

//PM差速转
void PMDTurnTo(double rtn, double r, double kp, double vmin, double offset){
    double error, cv, rv, lv;
    while(1){
        error = rtn - GR.rotation();
        if (fabs(error) <= offset) break;
        cv = kp * error;
        rv = cv * (r-ChasisWidth/2)/r;
        lv = cv * (r+ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100) SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else if(fabs(rv) < vmin) SpinLR(Sign(cv) * vmin * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * vmin);
            else SpinLR(lv, rv);
        }
        else{
            if(fabs(rv) >= 100) SpinLR(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * 100);
            else if(fabs(lv) < vmin) SpinLR(Sign(cv) * vmin, Sign(cv) * vmin * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else SpinLR(lv, rv);
        }

    }
    Stop(hold);
}

//PM差速转
void PMDTurnFor(double rtn, double r, double kp, double vmin, double offset){
    double error, cv, rv, lv;
    rtn = rtn + GR.rotation();
    while(1){
        error = rtn - GR.rotation();
        if (fabs(error) <= offset) break;
        cv = kp * error;
        rv = cv * (r-ChasisWidth/2)/r;
        lv = cv * (r+ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100) SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else if(fabs(rv) < vmin) SpinLR(Sign(cv) * vmin * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * vmin);
            else SpinLR(lv, rv);
        }
        else{
            if(fabs(rv) >= 100) SpinLR(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * 100);
            else if(fabs(lv) < vmin) SpinLR(Sign(cv) * vmin, Sign(cv) * vmin * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else SpinLR(lv, rv);
        }

    }
    Stop(hold);
}

void PIDTurnTo(double target, double kp, double ki, double kd, double startI, double offset){
    ResetPosition();
    double error, v, lastError = 0.0, integral = startI;
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        integral += error;
        v = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        SpinLR(v, -v, dps);
    }
    Stop(hold);
}

void PIDTurnFor(double target, double kp, double ki, double kd, double startI, double offset){
    double error, v, lastError = 0.0, integral = startI;
    target = target + GR.rotation();
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        integral += error;
        v = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        SpinLR(v, -v, dps);
    }
    Stop(hold);
}

void PIDGo(double target, double kp, double ki, double kd, double startI, double offset){
    ResetPosition();
    double error, v, lastError = 0.0, integral = startI;
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){
        error = target - AverPosition(deg);
        if(fabs(error) < offset) break;
        integral += error;
        v = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        SpinLR(v, v, dps);
    }
    Stop(hold);
}

void PIDDTurnTo(double rtn, double r, double kp, double ki, double kd, double startI, double offset){
    double error, cv, rv, lv, lastError = 0.0, integral = startI;
    while(1){
        error = rtn - GR.rotation();
        if (fabs(error) <= offset) break;
        integral += error;
        cv = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        rv = cv * (r-ChasisWidth/2)/r;
        lv = cv * (r+ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100) SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else SpinLR(lv, rv);
        }
        else{
            if(fabs(rv) >= 100) SpinLR(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * 100);
            else SpinLR(lv, rv);
        }
        
    }
    Stop(hold);
}

void PIDDTurnFor(double rtn, double r, double kp, double ki, double kd, double startI, double offset){
    double error, cv, rv, lv, lastError = 0.0, integral = startI;
    rtn = rtn + GR.rotation();
    while(1){
        error = rtn - GR.rotation();
        if (fabs(error) <= offset) break;
        integral += error;
        cv = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        rv = cv * (r-ChasisWidth/2)/r;
        lv = cv * (r+ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100) SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            else SpinLR(lv, rv);
        }
        else{
            if(fabs(rv) >= 100) SpinLR(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(cv) * 100);
            else SpinLR(lv, rv);
        }
        
    }
    Stop(hold);
}
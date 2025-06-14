#include "SMU_Lib/chasis.h" 

void Spin_T(double t, double speed, velocityUnits velUnits){
    LMs.Spin(speed, velUnits);
    RMs.Spin(speed, velUnits);
    task::sleep(t);
    LMs.Stop(hold);
    RMs.Stop(hold);
}

//内置编码器直走
void Go(double target, double v, velocityUnits vu){
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    LMs.SpinFor(target, deg, v, vu, 0);
    RMs.SpinFor(target, deg, v, vu, 0);
    while(!LMs.isDone() || !RMs.isDone()){
        task::sleep(10);
    }
}

//内置编码器转相对角度
void TurnFor(double target, double v, velocityUnits vu){
    target = target * ChasisWidth / (2 * WheelRadius * ChasisRatio);
    LMs.SpinFor(target, deg, v, vu, false);
    RMs.SpinFor(-target, deg, v, vu, false);
    while(!LMs.isDone() || !RMs.isDone()){
        task::sleep(10);
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
}

//PM转绝对角度
void PMTurnTo(double target, double kp, double vmin, double offset){
    double error, v;
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        v = kp * error;
        if(v < -vmin || v > vmin){
            LMs.Spin(v, dps);
            RMs.Spin(-v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v < 0){
            LMs.Spin(-vmin, dps);
            RMs.Spin(vmin, dps);
            Brain.Screen.clearScreen(green);
        }
        else{
            LMs.Spin(vmin, dps);
            RMs.Spin(-vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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
            LMs.Spin(v, dps);
            RMs.Spin(-v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v < 0){
            LMs.Spin(-vmin, dps);
            RMs.Spin(vmin, dps);
            Brain.Screen.clearScreen(green);
        }
        else{
            LMs.Spin(vmin, dps);
            RMs.Spin(-vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
}


//PM直走
void PMGo(double target, double kp, double vmin, double offset){
    LMs.ResetPosition();
    RMs.ResetPosition();
    double error, v;
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){
        error = target - (LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2;
        if(fabs(error) < offset) break;
        v = kp * error;
        if(v < -vmin || v > vmin){
            LMs.Spin(v, dps);
            RMs.Spin(v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v > 0){
            LMs.Spin(vmin, dps);
            RMs.Spin(vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
        else{
            LMs.Spin(-vmin, dps);
            RMs.Spin(-vmin, dps);
            Brain.Screen.clearScreen(green);
        }
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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
            if(fabs(lv) >= 100){
                LMs.Spin(Sign(cv) * 100);
                RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else if(fabs(rv) < vmin) {
                LMs.Spin(Sign(cv) * vmin * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * vmin);
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }
        else{
            if(fabs(rv) >= 100){
                LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * 100);
            }
            else if(fabs(lv) < vmin) {
                LMs.Spin(Sign(cv) * vmin);
                RMs.Spin(Sign(cv) * vmin * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }

    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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
            if(fabs(lv) >= 100){
                LMs.Spin(Sign(cv) * 100);
                RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else if(fabs(rv) < vmin) {
                LMs.Spin(Sign(cv) * vmin * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * vmin);
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * 100);
            }
            else if(fabs(lv) < vmin) {
                LMs.Spin(Sign(cv) * vmin);
                RMs.Spin(Sign(cv) * vmin * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }

    }
    LMs.Stop(hold);
    RMs.Stop(hold);
}

void PIDTurnTo(double target, double kp, double ki, double kd, double startI, double offset){
    LMs.ResetPosition();
    RMs.ResetPosition();
    double error, v, lastError = 0.0, integral = startI;
    while(1){
        error = target - GR.rotation();
        if (fabs(error) <= offset) break;
        integral += error;
        v = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        LMs.Spin(v, dps);
        RMs.Spin(-v, dps);
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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

        LMs.Spin(v, dps);
        RMs.Spin(-v, dps);
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
}

void PIDGo(double target, double kp, double ki, double kd, double startI, double offset){
    LMs.ResetPosition();
    RMs.ResetPosition();
    double error, v, lastError = 0.0, integral = startI;
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){
        error = target - (LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2;
        if(fabs(error) < offset) break;
        integral += error;
        v = kp * error + ki * integral + kd * (error - lastError);
        lastError = error;

        LMs.Spin(v, dps);
        RMs.Spin(v, dps);
    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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
            if(fabs(lv) >= 100){
                LMs.Spin(Sign(cv) * 100);
                RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * 100);
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }

    }
    LMs.Stop(hold);
    RMs.Stop(hold);
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
            if(fabs(lv) >= 100) {
                LMs.Spin(Sign(cv) * 100);
                RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
                RMs.Spin(Sign(cv) * 100);
            }
            else {
                LMs.Spin(lv);
                RMs.Spin(rv);
            }
        }

    }
    LMs.Stop(hold);
    RMs.Stop(hold);
} 
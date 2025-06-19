#include "SMU_Lib/chasis.h" 
#include "SMU_Lib/motor_group.h"



// void Chassis::SpinLR(double leftSpeed, double rightSpeed, velocityUnits units){
//         LMs.Spin(leftSpeed, units);
//         RMs.Spin(rightSpeed, units);
//     };
// void Chassis::ResetPosition(){
//         LMs.ResetPosition();
//         RMs.ResetPosition();
//     };
// double Chassis::AveragePosition(vex::rotationUnits units){
//         return (LMs.AveragePosition(units) + RMs.AveragePosition(units)) / 2;
//     };
// void Chassis::Stop(vex::brakeType bt){
//         LMs.Stop(bt);
//         RMs.Stop(bt);
//     };
//     void Chassis::Spin_T(double t, double speed, velocityUnits velUnits){
//         LMs.Spin(speed, velUnits);
//         RMs.Spin(speed, velUnits);
//         task::sleep(t);
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::Go(double target, double v, velocityUnits vu){
//         target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
//         LMs.SpinFor(target, deg, v, vu, 0);
//         RMs.SpinFor(target, deg, v, vu, 0);
//         while(!LMs.isDone() || !RMs.isDone()){
//             task::sleep(10);
//         }
//     };
//     void Chassis::TurnFor(double target, double v, velocityUnits vu){
//         target = target * ChasisWidth / (2 * WheelRadius * ChasisRatio);
//         LMs.SpinFor(target, deg, v, vu, false);
//         RMs.SpinFor(-target, deg, v, vu, false);
//         while(!LMs.isDone() || !RMs.isDone()){
//             task::sleep(10);
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PMTurnTo(double target){
//         double error, v;
//         while(1){
//             error = target - GR.rotation();
//             if (fabs(error) <= PMT.offset) break;
//             v = PMT.kp * error;
//             if(v < -PMT.vmin || v > PMT.vmin){
//                 LMs.Spin(v, dps);
//                 RMs.Spin(-v, dps);
//                 Brain.Screen.clearScreen(red);
//             }
//             else if(v < 0){
//                 LMs.Spin(-PMT.vmin, dps);
//                 RMs.Spin(PMT.vmin, dps);
//                 Brain.Screen.clearScreen(green);
//             }
//             else{
//                 LMs.Spin(PMT.vmin, dps);
//                 RMs.Spin(-PMT.vmin, dps);
//                 Brain.Screen.clearScreen(blue);
//             }
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PMTurnFor(double target){
//         double error, v;
//         target = target + GR.rotation();
//         while(1){
//             error = target - GR.rotation();
//             if (fabs(error) <= PMT.offset) break;
//             v = PMT.kp * error;
//             if(v < -PMT.vmin || v > PMT.vmin){
//                 LMs.Spin(v, dps);
//                 RMs.Spin(-v, dps);
//                 Brain.Screen.clearScreen(red);
//             }
//             else if(v < 0){
//                 LMs.Spin(-PMT.vmin, dps);
//                 RMs.Spin(PMT.vmin, dps);
//                 Brain.Screen.clearScreen(green);
//             }
//             else{
//                 LMs.Spin(PMT.vmin, dps);
//                 RMs.Spin(-PMT.vmin, dps);
//                 Brain.Screen.clearScreen(blue);
//             }
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PMDTurnTo(double rtn, double r){
//         double error, v;
//         while(1){
//             error = rtn - GR.rotation();
//             if (fabs(error) <= PMDT.offset) break;
//             v = PMDT.kp * error;
//             if(v < -PMDT.vmin || v > PMDT.vmin){
//                 LMs.Spin(v, dps);
//                 RMs.Spin(-v, dps);
//                 Brain.Screen.clearScreen(red);
//             }
//             else if(v < 0){
//                 LMs.Spin(-PMDT.vmin, dps);
//                 RMs.Spin(PMDT.vmin, dps);
//                 Brain.Screen.clearScreen(green);
//             }
//             else{
//                 LMs.Spin(PMDT.vmin, dps);
//                 RMs.Spin(-PMDT.vmin, dps);
//                 Brain.Screen.clearScreen(blue);
//             }
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PMDTurnFor(double rtn, double r){
//         double error, v;
//         rtn = rtn + GR.rotation();
//         while(1){
//             error = rtn - GR.rotation();
//             if (fabs(error) <= PMDT.offset) break;
//             v = PMDT.kp * error;
//             if(v < -PMDT.vmin || v > PMDT.vmin){
//                 LMs.Spin(v, dps);
//                 RMs.Spin(-v, dps);
//                 Brain.Screen.clearScreen(red);
//             }
//             else if(v < 0){
//                 LMs.Spin(-PMDT.vmin, dps);
//                 RMs.Spin(PMDT.vmin, dps);
//                 Brain.Screen.clearScreen(green);
//             }
//             else{
//                 LMs.Spin(PMDT.vmin, dps);
//                 RMs.Spin(-PMDT.vmin, dps);
//                 Brain.Screen.clearScreen(blue);
//             }
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PMGo(double target){
//         double error, v;
//         LMs.ResetPosition();
//         RMs.ResetPosition();
//         target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
//         while(1){
//             error = target - (LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2;
//             if(fabs(error) < PMT.offset) break;
//             v = PMT.kp * error;
//             if(v < -PMT.vmin || v > PMT.vmin){
//                 LMs.Spin(v, dps);
//                 RMs.Spin(v, dps);
//                 Brain.Screen.clearScreen(red);
//             }
//             else if(v > 0){
//                 LMs.Spin(PMT.vmin, dps);
//                 RMs.Spin(PMT.vmin, dps);
//                 Brain.Screen.clearScreen(blue);
//             }
//             else{
//                 LMs.Spin(-PMT.vmin, dps);
//                 RMs.Spin(-PMT.vmin, dps);
//                 Brain.Screen.clearScreen(green);
//             }
//         }
//     };
//     void Chassis::PIDTurnTo(double target){
//         LMs.ResetPosition();
//         RMs.ResetPosition();
//         double error, v, lastError = 0.0, integral = PIDT.startI;
//         while(1){
//             error = target - GR.rotation();
//             if (fabs(error) <= PIDT.offset) break;
//             integral += error;
//             v = PIDT.kp * error + PIDT.ki * integral + PIDT.kd * (error - lastError);
//             lastError = error;

//             LMs.Spin(v, dps);
//             RMs.Spin(-v, dps);
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };

//     void Chassis::PIDDTurnTo(double rtn, double r){
//         double error, cv, rv, lv;
//         while(1){
//             error = rtn - GR.rotation();
//             if (fabs(error) <= PIDDT.offset) break;
//             cv = PIDDT.kp * error + PIDDT.ki * PIDDT.startI;
//             rv = cv * (r-ChasisWidth/2)/r;
//             lv = cv * (r+ChasisWidth/2)/r;

//             if(r>0){
//                 if(fabs(lv) >= 100){
//                     LMs.Spin(Sign(cv) * 100);
//                     RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
//                 }
//                 else {
//                     LMs.Spin(lv);
//                     RMs.Spin(rv);
//                 }
//             }
//             else{
//                 if(fabs(rv) >= 100) {
//                     LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
//                     RMs.Spin(Sign(cv) * 100);
//                 }
//                 else {
//                     LMs.Spin(lv);
//                     RMs.Spin(rv);
//                 }
//             }

//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PIDDTurnFor(double rtn, double r){
//         double error, cv, rv, lv;
//         rtn = rtn + GR.rotation();
//         while(1){
//             error = rtn - GR.rotation();
//             if (fabs(error) <= PIDDT.offset) break;
//             cv = PIDDT.kp * error + PIDDT.ki * PIDDT.startI;
//             rv = cv * (r-ChasisWidth/2)/r;
//             lv = cv * (r+ChasisWidth/2)/r;

//             if(r>0){
//                 if(fabs(lv) >= 100){
//                     LMs.Spin(Sign(cv) * 100);
//                     RMs.Spin(Sign(cv) * 100 * (r-ChasisWidth/2)/(r+ChasisWidth/2));
//                 }
//                 else {
//                     LMs.Spin(lv);
//                     RMs.Spin(rv);
//                 }
//             }
//             else{
//                 if(fabs(rv) >= 100) {
//                     LMs.Spin(Sign(cv) * 100 * (r+ChasisWidth/2)/(r-ChasisWidth/2));
//                     RMs.Spin(Sign(cv) * 100);
//                 }
//                 else {
//                     LMs.Spin(lv);
//                     RMs.Spin(rv);
//                 }
//             }

//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };
//     void Chassis::PIDGo(double target){
//         LMs.ResetPosition();
//         RMs.ResetPosition();
//         double error, v, lastError = 0.0, integral = PIDG.startI;
//         target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
//         while(1){
//             error = target - (LMs.AveragePosition(deg) + RMs.AveragePosition(deg)) / 2;
//             if(fabs(error) < PIDG.offset) break;
//             integral += error;
//             v = PIDG.kp * error + PIDG.ki * integral + PIDG.kd * (error - lastError);
//             lastError = error;

//             LMs.Spin(v, dps);
//             RMs.Spin(v, dps);
//         }
//         LMs.Stop(hold);
//         RMs.Stop(hold);
//     };

void SpinLR(double leftSpeed, double rightSpeed, velocityUnits units){
    for(int i = 0; i < CH.count; i++){
        CH.LMs[i].spin(fwd, leftSpeed, units);
        CH.RMs[i].spin(fwd, rightSpeed, units);
    }
}

void Stop(vex::brakeType bt){
    for(int i = 0; i < CH.count; i++){
        CH.LMs[i].stop(bt);
        CH.RMs[i].stop(bt);
    }
}

void ResetPosition(){
    for(int i = 0; i < CH.count; i++){
        CH.LMs[i].resetPosition();
        CH.RMs[i].resetPosition();
    }
}

double AveragePosition(vex::rotationUnits units){
    double sum = 0.0;
    for(int i = 0; i < CH.count; i++){
        sum += (CH.LMs[i].position(units) + CH.RMs[i].position(units)) / 2;
    }
    return sum / CH.count;
}

void Spin_T(double t, double speed, velocityUnits velUnits){
    SpinLR(speed, speed, velUnits);
    task::sleep(t);
    Stop(hold);
}

//内置编码器直走
void Go(double target, double v, velocityUnits vu){
    target = target * 360 / (2 * Pi * CH.WheelRadius * CH.ChasisRatio);
    for(int i = 0; i < CH.count; i++){
        CH.LMs[i].spinFor(target, deg, v, vu, false);
        CH.RMs[i].spinFor(target, deg, v, vu, false);
    }
    while(1){
        bool done = true;
        for(int i = 0; i < CH.count; i++){
            if(!CH.LMs[i].isDone() || !CH.RMs[i].isDone()){
                done = false;
                break;
            }
        }
        if(done) break;
        task::sleep(1);
    }

}

//内置编码器转相对角度
void TurnFor(double target, double v, velocityUnits vu){
    target = target * CH.ChasisWidth / (2 * CH.WheelRadius * CH.ChasisRatio);
    for(int i = 0; i < CH.count; i++){
        CH.LMs[i].spinFor(target, deg, v, vu, false);
        CH.RMs[i].spinFor(-target, deg, v, vu, false);
    }
    while(1){
        bool done = true;
        for(int i = 0; i < CH.count; i++){
            if(!CH.LMs[i].isDone() || !CH.RMs[i].isDone()){
                done = false;
                break;
            }
        }
        if(done) break;
        task::sleep(1);
    }
    Stop(hold);
}


//PM转绝对角度
void PMTurnTo(double target){
    double error, v;
    while(1){
        error = target - CH.GR->rotation();
        if (fabs(error) <= CH.PMT.offset) break;
        v = CH.PMT.kp * error;
        if(v < -CH.PMT.vmin || v > CH.PMT.vmin){
            SpinLR(v, -v, dps);
            CH.Scn->clearScreen(red);
        }
        else if(v < 0){
            SpinLR(-CH.PMT.vmin, CH.PMT.vmin, dps);
            CH.Scn->clearScreen(green);
        }
        else{
            SpinLR(CH.PMT.vmin, -CH.PMT.vmin, dps);
            CH.Scn->clearScreen(blue);
        }
    }
    Stop(hold);
}

//PM转相对角度
void PMTurnFor(double target){
    double error, v;
    target += CH.GR->rotation();
    while(1){
        error = target - CH.GR->rotation();
        if (fabs(error) <= CH.PMT.offset) break;
        v = CH.PMT.kp * error;
        if(v < -CH.PMT.vmin || v > CH.PMT.vmin){
            SpinLR(v, -v, dps);
            CH.Scn->clearScreen(red);
        }
        else if(v < 0){
            SpinLR(-CH.PMT.vmin, CH.PMT.vmin, dps);
            CH.Scn->clearScreen(green);
        }
        else{
            SpinLR(CH.PMT.vmin, -CH.PMT.vmin, dps);
            CH.Scn->clearScreen(blue);
        }
    }
    Stop(hold);
}

//PM直走
void PMGo(double target){
    ResetPosition();
    double error, v;
    target = target * 360 / (2 * Pi * CH.WheelRadius * CH.ChasisRatio);
    while(1){
        error = target - AveragePosition(deg);
        if(fabs(error) < CH.PMG.offset) break;
        v = CH.PMG.kp * error;
        if(v < -CH.PMG.vmin || v > CH.PMG.vmin){
            SpinLR(v, v, dps);
            CH.Scn->clearScreen(red);
        }
        else if(v > 0){
            SpinLR(CH.PMG.vmin, CH.PMG.vmin, dps);
            CH.Scn->clearScreen(blue);
        }
        else{
            SpinLR(-CH.PMG.vmin, -CH.PMG.vmin, dps);
            CH.Scn->clearScreen(green);
        }
    }
    Stop(hold);
}

//PM差速转
void PMDTurnTo(double rtn, double r){
    double error, cv, rv, lv;
    while(1){
        error = rtn - CH.GR->rotation();
        if (fabs(error) <= CH.PMDT.offset) break;
        cv = CH.PMDT.kp * error;
        rv = cv * (r-CH.ChasisWidth/2)/r;
        lv = cv * (r+CH.ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100){
                SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2), dps);
            }
            else if(fabs(rv) < CH.PMDT.vmin) {
                SpinLR(Sign(cv) * CH.PMDT.vmin * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * CH.PMDT.vmin, dps);
            }
            else {
                SpinLR(lv, rv, dps);
            }
        }
        else{
            if(fabs(rv) >= 100){
                SpinLR(Sign(cv) * 100 * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * 100, dps);
            }
            else if(fabs(lv) < CH.PMDT.vmin) {
                SpinLR(Sign(cv) * CH.PMDT.vmin, Sign(cv) * CH.PMDT.vmin * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2), dps);
            }
            else {
                SpinLR(lv, rv, dps);
            }
        }

    }
    Stop(hold);
}

//PM差速转
void PMDTurnFor(double rtn, double r){
    double error, cv, rv, lv;
    rtn += CH.GR->rotation();
    while(1){
        error = rtn - CH.GR->rotation();
        if (fabs(error) <= CH.PMDT.offset) break;
        cv = CH.PMDT.kp * error;
        rv = cv * (r-CH.ChasisWidth/2)/r;
        lv = cv * (r+CH.ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100){
                SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2), dps);
            }
            else if(fabs(rv) < CH.PMDT.vmin) {
                SpinLR(Sign(cv) * CH.PMDT.vmin * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * CH.PMDT.vmin, dps);
            }
            else {
                SpinLR(lv, rv, dps);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                SpinLR(Sign(cv) * 100 * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * 100, dps);
            }
            else if(fabs(lv) < CH.PMDT.vmin) {
                SpinLR(Sign(cv) * CH.PMDT.vmin, Sign(cv) * CH.PMDT.vmin * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2), dps);
            }
            else {
                SpinLR(lv, rv, dps);
            }
        }

    }
    Stop(hold);
}

void PIDTurnTo(double target){
    ResetPosition();
    double error, v, lastError = 0.0, integral = CH.PIDT.startI;
    error = target - CH.GR->rotation();
    while(1){
        error = target - CH.GR->rotation();
        if (fabs(error) <= CH.PIDT.offset) break;
        integral += error;
        v = CH.PIDT.kp * error + CH.PIDT.ki * integral + CH.PIDT.kd * (error - lastError);
        lastError = error;

        SpinLR(v, -v, dps);
    }
    Stop(hold);
}

void PIDTurnFor(double target){
    double error, v, lastError = 0.0, integral = CH.PIDT.startI;
    target = target + CH.GR->rotation();
    while(1){
        error = target - CH.GR->rotation();
        if (fabs(error) <= CH.PIDT.offset) break;
        integral += error;
        v = CH.PIDT.kp * error + CH.PIDT.ki * integral + CH.PIDT.kd * (error - lastError);
        lastError = error;

        SpinLR(v, -v, dps);
    }
    Stop(hold);
}

void PIDGo(double target){
    ResetPosition();
    double error, v, lastError = 0.0, integral = CH.PIDG.startI;
    target = target * 360 / (2 * Pi * CH.WheelRadius * CH.ChasisRatio);
    while(1){
        error = target - AveragePosition(deg);
        if(fabs(error) < CH.PIDG.offset) break;
        integral += error;
        v = CH.PIDG.kp * error + CH.PIDG.ki * integral + CH.PIDG.kd * (error - lastError);
        lastError = error;

        SpinLR(v, v, dps);
    }
    Stop(hold);
}

void PIDDTurnTo(double rtn, double r){
    double error, cv, rv, lv, lastError = 0.0, integral = CH.PIDDT.startI;
    while(1){
        error = rtn - CH.GR->rotation();
        if (fabs(error) <= CH.PIDDT.offset) break;
        integral += error;
        cv = CH.PIDDT.kp * error + CH.PIDDT.ki * integral + CH.PIDDT.kd * (error - lastError);
        lastError = error;

        rv = cv * (r-CH.ChasisWidth/2)/r;
        lv = cv * (r+CH.ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100){
                SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2));
            }
            else {
                SpinLR(lv, rv);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                SpinLR(Sign(cv) * 100 * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * 100);
            }
            else {
                SpinLR(lv, rv);
            }
        }

    }
    Stop(hold);
}

void PIDDTurnFor(double rtn, double r){
    double error, cv, rv, lv, lastError = 0.0, integral = CH.PIDDT.startI;
    rtn = rtn + CH.GR->rotation();
    while(1){
        error = rtn - CH.GR->rotation();
        if (fabs(error) <= CH.PIDDT.offset) break;
        integral += error;
        cv = CH.PIDDT.kp * error + CH.PIDDT.ki * integral + CH.PIDDT.kd * (error - lastError);
        lastError = error;

        rv = cv * (r-CH.ChasisWidth/2)/r;
        lv = cv * (r+CH.ChasisWidth/2)/r;

        if(r>0){
            if(fabs(lv) >= 100) {
                SpinLR(Sign(cv) * 100, Sign(cv) * 100 * (r-CH.ChasisWidth/2)/(r+CH.ChasisWidth/2));
            }
            else {
                SpinLR(lv, rv);
            }
        }
        else{
            if(fabs(rv) >= 100) {
                SpinLR(Sign(cv) * 100 * (r+CH.ChasisWidth/2)/(r-CH.ChasisWidth/2), Sign(cv) * 100);
            }
            else {
                SpinLR(lv, rv);
            }
        }

    }
    Stop(hold);
}
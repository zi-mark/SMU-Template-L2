#include "SMU_Lib/functional.h"
#include "robot-config.h"

void Auto_Sorting(bool color) {
    while(1){
        // if(CLSensor.isNearObject()){
            if(color) {
                if(CLSensor.hue() > 160){
                    Sucks2.Spin(-100);
                    task::sleep(20);
                }
                else if(CLSensor.hue() < 60){
                    Sucks2.Spin(100);
                    Sucks.Spin(100);
                    task::sleep(20);
                }
                else{
                    // Sucks2.Stop();
                }
            }
            else {
                if(CLSensor.hue() < 50){
                    Sucks2.Spin(-100);
                    task::sleep(300);
                }
                else if(CLSensor.hue() > 170){
                    Sucks2.Spin(100);
                    task::sleep(300);
                }
                else{
                    // Sucks2.Stop();
                }
            }
        // }
        // else{
        //     Sucks2.Stop();
        // }

        if(Con.ButtonR1.pressing()){
            Sucks.Spin(100);
        }
        else if(Con.ButtonR2.pressing()){
            Sucks.Spin(-100);
        }
        else{
            Sucks.Stop();
        }

        if(Con.ButtonL1.pressing()){
            Sucks2.Spin(100);
        }
        else if(Con.ButtonL2.pressing()){
            Sucks2.Spin(-100);
        }
        else{
            Sucks2.Stop();
        }

        // task::sleep(10);
        printf("Hue: %f\n", CLSensor.hue());
    } 
}
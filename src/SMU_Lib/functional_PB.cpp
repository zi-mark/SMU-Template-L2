#include "SMU_Lib/functional.h"
#include "robot-config.h"

void DC_Sorting(bool color, int red_offset, int blue_offset) {
    while(1){
            if(color) {
                if(CLSensor.hue() > blue_offset){
                    Sucks2.Spin(-100);
                    task::sleep(20);
                }
                else if(CLSensor.hue() < red_offset){
                    Sucks2.Spin(100);
                    Sucks.Spin(100);
                    task::sleep(20);
                }
            }
            else {
                if(CLSensor.hue() < red_offset){
                    Sucks2.Spin(-100);
                    task::sleep(300);
                }
                else if(CLSensor.hue() > blue_offset){
                    Sucks2.Spin(100);
                    task::sleep(300);
                }
            }

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

        task::sleep(5);
        printf("Hue: %f\n", CLSensor.hue());
    } 
}

void Eat(){
    Sucks.Spin(100);
    Sucks2.Spin(100);
    Sucks3.Spin(100);
}

void Low_Goal(){
    Sucks.Spin(-100);
    Sucks2.Spin(-100);
    Sucks3.Spin(-100);
}

void High_Goal(){
    Sucks.Spin(100);
    Sucks2.Spin(-100);
    Sucks3.Spin(-100);
}

void Long_Goal(){
    Sucks.Spin(100);
    Sucks2.Spin(100);
    Sucks3.Spin(-100);
}

void Sucks_Stop(){
    Sucks.Stop();
    Sucks2.Stop();
    Sucks3.Stop();
}
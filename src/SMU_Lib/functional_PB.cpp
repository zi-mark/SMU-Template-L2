#include "SMU_Lib/functional.h"
#include "robot-config.h"
#include "SMU_Lib/autonomous.h"

// void DC_Sorting(bool color, int red_offset, int blue_offset) {
//     while(1){
//             if(color) {
//                 if(CLSensor.hue() > blue_offset){
//                     Sucks2.Spin(-100);
//                     task::sleep(20);
//                 }
//                 else if(CLSensor.hue() < red_offset){
//                     Sucks2.Spin(100);
//                     Sucks.Spin(100);
//                     task::sleep(20);
//                 }
//             }
//             else {
//                 if(CLSensor.hue() < red_offset){
//                     Sucks2.Spin(-100);
//                     task::sleep(300);
//                 }
//                 else if(CLSensor.hue() > blue_offset){
//                     Sucks2.Spin(100);
//                     task::sleep(300);
//                 }
//             }

//         if(Con.ButtonR1.pressing()){
//             Sucks.Spin(100);
//         }
//         else if(Con.ButtonR2.pressing()){
//             Sucks.Spin(-100);
//         }
//         else{
//             Sucks.Stop();
//         }

//         if(Con.ButtonL1.pressing()){
//             Sucks2.Spin(100);
//         }
//         else if(Con.ButtonL2.pressing()){
//             Sucks2.Spin(-100);
//         }
//         else{
//             Sucks2.Stop();
//         }

//         task::sleep(5);
//         printf("Hue: %f\n", CLSensor.hue());
//     } 
// }

// void CL_Eat(){
//     if(Auto[ProgramChoice].color){
//         if(CLSensor.hue() > CLData.blue_offset){
//             Sucks.Spin(100);
//             Sucks2.Spin(-100);
//             Sucks3.Spin(100);
//         }
//         else{
//             Sucks.Spin(100);
//             Sucks2.Spin(100);
//             Sucks3.Spin(100);
//         }
//     }
//     else{
//         if(CLSensor.hue() < CLData.red_offset){
//             Sucks.Spin(100);
//             Sucks2.Spin(-100);
//             Sucks3.Spin(100);
//         }
//         else{
//             Sucks.Spin(100);
//             Sucks2.Spin(100);
//             Sucks3.Spin(100);
//         }
//     }
// }

// void Eat(){
//         Sucks.Spin(100);
//         Sucks2.Spin(100);
//         Sucks3.Spin(100);
// }

// void Low_Goal(){
//     Sucks.Spin(-100);
//     Sucks2.Spin(-100);
//     Sucks3.Spin(-100);
// }

// void High_Goal(){
//     Sucks.Spin(100);
//     Sucks2.Spin(-100);
//     Sucks3.Spin(-100);
// }

// void Long_Goal(){
//     Sucks.Spin(100);
//     Sucks2.Spin(100);
//     Sucks3.Spin(-100);
// }

// void CL_Long_Goal(){
//     if(Auto[ProgramChoice].color){
//         if(CLSensor.hue() > CLData.blue_offset){
//             Sucks.Spin(100);
//             Sucks2.Spin(-100);
//             Sucks3.Spin(-100);
//         }
//         else{
//             Sucks.Spin(100);
//             Sucks2.Spin(100);
//             Sucks3.Spin(-100);
//         }
//     }
//     else{
//         if(CLSensor.hue() < CLData.red_offset){
//             Sucks.Spin(100);
//             Sucks2.Spin(-100);
//             Sucks3.Spin(-100);
//         }
//         else{
//             Sucks.Spin(100);
//             Sucks2.Spin(100);
//             Sucks3.Spin(-100);
//         }
//     }
// }

// void Sucks_Stop(){
//     Sucks.Stop();
//     Sucks2.Stop();
//     Sucks3.Stop();
// }
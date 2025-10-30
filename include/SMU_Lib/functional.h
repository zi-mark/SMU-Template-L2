#include "vex.h"
#pragma once
struct ColorData {
    int red_offset;
    int blue_offset;
    double right_duration;
    double false_duration;
    int light_power;
};
extern void DC_Sorting(bool color);
extern void Auto_Sorting(bool color);

extern void Eat();
extern void Low_Goal();
extern void High_Goal();
extern void Long_Goal();
extern void Sucks_Stop();
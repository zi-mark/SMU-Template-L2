#include "vex.h"
#pragma once
struct ColorData {
    int red_offset;
    int blue_offset;
    double right_duration;
    double false_duration;
};
extern void DC_Sorting(bool color);
extern void Auto_Sorting(bool color);
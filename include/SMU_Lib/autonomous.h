#include "robot-config.h"
//
void Init();
void ProgramChoosing();

extern int ProgramChoice;
// #define MaxChoice 16
//
void Break();
void RR();
void RR2();
void RR3();
void RL();
void RL2();
void RL3();
void BR();
void BR2();
void BR3();
void BL();
void BL2();
void BL3();
void Skills();
void Motor_Test();
void Test();
void Empty();

struct Autos{
    const char* name;
    void (*Funcs)();
    int color;
};

extern Autos Auto[];
extern int MaxChoice;
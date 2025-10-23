#include "robot-config.h"
//
void Init();
void ProgramChoosing();

void Break();

void Motor_Test();
void Auto_Test();
void Empty();

struct Autos{
    const char* name;
    void (*Funcs)();
    int color;
};

extern Autos Auto[];
extern int MaxChoice;
extern int ProgramChoice;
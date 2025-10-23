#include "robot-config.h"
//
void Init();
void ProgramChoosing();

void Break();

void Auto_Test();

struct Autos{
    const char* name;
    void (*Funcs)();
    int color;
};

extern Autos Auto[];
extern int MaxChoice;
extern int ProgramChoice;
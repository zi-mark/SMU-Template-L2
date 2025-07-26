#include "SMU_Lib/autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

#ifdef Exam
    #if Exam == 1

        void RR(){}
        void RR2(){}
        void RR3(){}
        void RL(){}
        void RL2(){}
        void RL3(){}
        void BR(){}
        void BR2(){}
        void BR3(){}
        void BL(){}
        void BL2(){}
        void BL3(){}
        void Skills(){}
    #else
        void RR(){}
        void RR2(){}
        void RR3(){}
        void RL(){}
        void RL2(){}
        void RL3(){}
        void BR(){}
        void BR2(){}
        void BR3(){}
        void BL(){}
        void BL2(){}
        void BL3(){}
        void Skills(){}
    #endif

    //自动函数与函数名链接
    int MaxChoice = 16; 
    Autos Auto[]{
        {"DC ", Empty, 1},//默认第一个是手动
        {"RR ", RR, 1}, 
        {"RR2 ", RR2, 1},
        {"RR3 ", RR3, 1},
        {"RL ", RL, 1}, 
        {"RL2 ", RL2, 1}, 
        {"RL3 ", RL3, 1}, 
        {"BL ", BL, 0},
        {"BL2 ", BL2, 0}, 
        {"BL3 ", BL3, 0},
        {"BR ", BR, 0},
        {"BR2 ", BR2, 0},
        {"BR3 ", BR3, 0},
        {"SK ", Skills, 1},
        {"Test", Test, 1},
        {"MT ", Motor_Test, 1}
    };

#endif


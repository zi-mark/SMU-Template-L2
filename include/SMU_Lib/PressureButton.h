#include "vex.h"

class PressureButton {
    private:
    vex::controller::button button;
    bool save;
    public:
    PressureButton(vex::controller::button btn);
    bool IsPressing();
    bool JustPressed();
};

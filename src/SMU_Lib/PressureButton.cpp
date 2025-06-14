#include "SMU_Lib/PressureButton.h"

PressureButton::PressureButton(vex::controller::button btn) : button(btn), save(false) {}
bool PressureButton::IsPressing() {
    return button.pressing();
}
bool PressureButton::JustPressed() {
    if (button.pressing()) {
        if (!save) {
            save = true;
            return true;
        }
    }
    else save = false;

    return false;
}
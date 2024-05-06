#include "dac_algorithms/xbox_360.hpp"

namespace DACAlgorithms {
namespace Xbox360 {

void actuateXbox360Report(GpioToButtonSets::F1::ButtonSet buttonSet) {
    
    buttonSet.up = buttonSet.up || buttonSet.up2;
    
    bool left = buttonSet.left && !(buttonSet.ms);
    bool right = buttonSet.right && !(buttonSet.ms);
    bool up = buttonSet.up && !(buttonSet.ms);
    bool down = buttonSet.down && !(buttonSet.ms);

    bool dLeft = buttonSet.left && buttonSet.ms;
    bool dRight = buttonSet.right && buttonSet.ms;
    bool dUp = buttonSet.up && buttonSet.ms;
    bool dDown = buttonSet.down && buttonSet.ms;

    bool home = buttonSet.start && buttonSet.ms;        // Xbox
    bool start = buttonSet.start && !(buttonSet.ms);    // Menu
    bool back = buttonSet.b && buttonSet.ms;            // View
    bool b = buttonSet.b && !(buttonSet.ms);

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = buttonSet.my;
    xInputReport.leftStickPress = buttonSet.mx;
    xInputReport.back = back;
    xInputReport.start = start;
    xInputReport.dRight = dRight;
    xInputReport.dLeft = dLeft;
    xInputReport.dDown = dDown;
    xInputReport.dUp = dUp;
    xInputReport.zl = buttonSet.ls;
    xInputReport.zr = buttonSet.z;
    xInputReport.home = home;
    xInputReport.pad1 = 0;
    xInputReport.a = buttonSet.a;
    xInputReport.b = b;
    xInputReport.x = buttonSet.x;
    xInputReport.y = buttonSet.y;
	xInputReport.leftTrigger = buttonSet.l ? 255 : 0;
	xInputReport.rightTrigger = buttonSet.r ? 255 : 0;
	xInputReport.leftStickX = left && right ? 0 : left ? 0x8000 : right ? 0x7FFF : 0;
	xInputReport.leftStickY = down && up ? 0 : down ? 0x8000 : up ? 0x7FFF : 0;
	xInputReport.rightStickX = buttonSet.cLeft && buttonSet.cRight ? 0 : buttonSet.cLeft ? 0x8000 : buttonSet.cRight ? 0x7FFF : 0;
	xInputReport.rightStickY = buttonSet.cDown && buttonSet.cUp ? 0 : buttonSet.cDown ? 0x8000 : buttonSet.cUp ? 0x7FFF : 0;
};

// Map face and shoulder buttons to top two rows on right side. We're a fightstick now.
// Use up2 for up to appease WASD players.
// Use MY for up to appease Hitbox players.
// MX and A are LS Press and RS Press.
// L is a modifier: L+Start = Home, L+Left/Right/Up/Down = Dpad left/right/up/down, L+MY = Back
void actuateLeverlessReport(GpioToButtonSets::F1::ButtonSet buttonSet) {

    // Modifier button is L
    bool mod = buttonSet.l;

    // up -> RB (you can always have too many ups)
    bool zr = buttonSet.up;

    // up2 -> up
    // MY -> up (you can never have too many ups)
    buttonSet.up = (buttonSet.up2 || buttonSet.my);

    bool left = buttonSet.left && !(mod);
    bool right = buttonSet.right && !(mod);
    bool up = buttonSet.up && !(mod);
    bool down = buttonSet.down && !(mod);

    // Left stick + Modifer button -> D-Pad
    bool dLeft = buttonSet.left && mod;
    bool dRight = buttonSet.right && mod;
    bool dUp = buttonSet.up && mod;
    bool dDown = buttonSet.down && mod;

    // Start +/- Modifier button -> Home / Photo
    bool start = buttonSet.start && (!mod);
    bool home = buttonSet.start && mod;

    // MX / A / MX + Modifier Button -> LS Press / RS Press / Back
    bool l3 = buttonSet.mx && (!mod);
    bool r3 = buttonSet.a;
    bool back = buttonSet.mx && mod;

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = r3;
    xInputReport.leftStickPress = l3;
    xInputReport.back = back;
    xInputReport.start = start;
    xInputReport.dRight = dRight;
    xInputReport.dLeft = dLeft;
    xInputReport.dDown = dDown;
    xInputReport.dUp = dUp;
    xInputReport.zl = buttonSet.z;
    xInputReport.zr = zr;
    xInputReport.home = home;
    xInputReport.pad1 = 0;
    xInputReport.a = buttonSet.b;
    xInputReport.b = buttonSet.x;
    xInputReport.x = buttonSet.r;
    xInputReport.y = buttonSet.y;
    xInputReport.leftTrigger = buttonSet.ls ? 255 : 0;
    xInputReport.rightTrigger = buttonSet.ms ? 255 : 0;
    xInputReport.leftStickX = left && right ? 0 : left ? 0x8000 : right ? 0x7FFF : 0; // Neutral SOCD 
    xInputReport.leftStickY = down && up ? 0x7FFF : down ? 0x8000 : up ? 0x7FFF : 0; // Up overrides down
    xInputReport.rightStickX = buttonSet.cLeft && buttonSet.cRight ? 0 : buttonSet.cLeft ? 0x8000 : buttonSet.cRight ? 0x7FFF : 0; // Neutral SOCD 
    xInputReport.rightStickY = buttonSet.cDown && buttonSet.cUp ? 0x7FFF : buttonSet.cDown ? 0x8000 : buttonSet.cUp ? 0x7FFF : 0; // Up overrides down
};


}
}
#ifndef ENHANCED_DISPLAY_SWITCH_H
#define ENHANCED_DISPLAY_SWITCH_H

#include <iostream>

namespace EDS {
    void displayHelp();
    std::wstring getLastMode();
    void runDisplaySwitch(int mode);
}

#endif // ENHANCED_DISPLAY_SWITCH_H

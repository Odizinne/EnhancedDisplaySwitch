#ifndef ENHANCED_DISPLAY_SWITCH_H
#define ENHANCED_DISPLAY_SWITCH_H

#include <iostream>

void displayHelp();
void saveLastMode(const std::wstring& mode);
std::wstring getLastMode();
void runDisplaySwitch(int mode);

#endif // ENHANCED_DISPLAY_SWITCH_H

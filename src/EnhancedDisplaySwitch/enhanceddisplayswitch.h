#ifndef ENHANCED_DISPLAY_SWITCH_H
#define ENHANCED_DISPLAY_SWITCH_H

#include <iostream>

void displayHelp();
void saveLastMode(const std::wstring& mode);
std::wstring getLastMode();
void runDisplaySwitch(const std::wstring& modeArg);

#endif // ENHANCED_DISPLAY_SWITCH_H

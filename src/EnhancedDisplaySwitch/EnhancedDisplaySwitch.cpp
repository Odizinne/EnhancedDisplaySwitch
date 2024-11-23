#include "enhanceddisplayswitch.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <shlobj.h>

void displayHelp() {
    std::wcout << L"Usage: EnhancedDisplaySwitch.exe [option]\n";
    std::wcout << L"Options:\n";
    std::wcout << L"  /internal or 1     Set display mode to internal\n";
    std::wcout << L"  /clone    or 2     Set display mode to clone\n";
    std::wcout << L"  /external or 3     Set display mode to external\n";
    std::wcout << L"  /extend   or 4     Set display mode to extend\n";
    std::wcout << L"  /lastmode or 5     Show the last used mode\n";
    std::wcout << L"  -h, --help, /?     Display this help message\n";
}

void saveLastMode(const std::wstring& mode) {
    HKEY hKey;
    std::wstring subKey = L"SOFTWARE\\EnhancedDisplaySwitch";

    if (RegCreateKeyExW(HKEY_CURRENT_USER, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExW(hKey, L"LastMode", 0, REG_SZ, (const BYTE*)mode.c_str(), static_cast<DWORD>((mode.size() + 1) * sizeof(wchar_t)));
        RegCloseKey(hKey);
    }
}

std::wstring getLastMode() {
    HKEY hKey;
    std::wstring subKey = L"SOFTWARE\\EnhancedDisplaySwitch";
    std::wstring mode;

    if (RegOpenKeyExW(HKEY_CURRENT_USER, subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        wchar_t buffer[256];
        DWORD bufferSize = sizeof(buffer);

        if (RegQueryValueExW(hKey, L"LastMode", NULL, NULL, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            mode = buffer;
        }

        RegCloseKey(hKey);
    }

    return mode.empty() ? L"No last mode found." : mode;
}

void runDisplaySwitch(int mode) {
    LONG result = ERROR_SUCCESS;

    switch (mode) {
    case 1:
        result = SetDisplayConfig(0, NULL, 0, NULL, SDC_TOPOLOGY_INTERNAL | SDC_APPLY);
        break;

    case 2:
        result = SetDisplayConfig(0, NULL, 0, NULL, SDC_TOPOLOGY_CLONE | SDC_APPLY);
        break;

    case 3:
        result = SetDisplayConfig(0, NULL, 0, NULL, SDC_TOPOLOGY_EXTEND | SDC_APPLY);
        break;

    case 4:
        result = SetDisplayConfig(0, NULL, 0, NULL, SDC_TOPOLOGY_EXTERNAL | SDC_APPLY);
        break;

    default:
        std::cerr << "Invalid mode selected.\n";
        return;
    }

    if (result == ERROR_SUCCESS) {
        return;
    } else {
        std::cerr << "Failed to set display configuration. Error: " << result << "\n";
        return;
    }
}

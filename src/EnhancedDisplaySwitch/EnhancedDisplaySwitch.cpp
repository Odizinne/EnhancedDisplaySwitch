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
    // Define the registry path
    std::wstring subKey = L"SOFTWARE\\EnhancedDisplaySwitch";

    // Create or open the registry key
    if (RegCreateKeyExW(HKEY_CURRENT_USER, subKey.c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        // Set the value of "LastMode" in the registry
        RegSetValueExW(hKey, L"LastMode", 0, REG_SZ, (const BYTE*)mode.c_str(), (mode.size() + 1) * sizeof(wchar_t));
        // Close the registry key
        RegCloseKey(hKey);
    }
}

std::wstring getLastMode() {
    HKEY hKey;
    // Define the registry path
    std::wstring subKey = L"SOFTWARE\\EnhancedDisplaySwitch";
    std::wstring mode;

    // Open the registry key
    if (RegOpenKeyExW(HKEY_CURRENT_USER, subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        wchar_t buffer[256];
        DWORD bufferSize = sizeof(buffer);

        // Query the value of "LastMode" from the registry
        if (RegQueryValueExW(hKey, L"LastMode", NULL, NULL, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            mode = buffer;
        }

        // Close the registry key
        RegCloseKey(hKey);
    }

    // Check if mode was retrieved, otherwise return a default message
    return mode.empty() ? L"No last mode found." : mode;
}


void runDisplaySwitch(const std::wstring& mode) {
    std::wstring commandLine = L"displaySwitch.exe " + mode;
    LPWSTR commandLineW = const_cast<LPWSTR>(commandLine.c_str());
    std::wprintf(L"Running command: %s\n", commandLineW);

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    CreateProcess(
        NULL,                  // No module name (use command line)
        commandLineW,          // Command line
        NULL,                  // Process handle not inheritable
        NULL,                  // Thread handle not inheritable
        FALSE,                 // Set handle inheritance to FALSE
        DETACHED_PROCESS,      // Creation flags (detached process)
        NULL,                  // Use parent's environment block
        NULL,                  // Use parent's starting directory
        &si,                   // Pointer to STARTUPINFO structure
        &pi                    // Pointer to PROCESS_INFORMATION structure
        );

    // Close handles as they are no longer needed
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

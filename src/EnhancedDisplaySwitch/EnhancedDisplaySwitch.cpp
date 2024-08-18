#include "enhanceddisplayswitch.h"
#include <windows.h>
#include <iostream>
#include <fstream>
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
    wchar_t appDataPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, appDataPath))) {
        std::wstring historyFilePath = std::wstring(appDataPath) + L"\\EnhancedDisplaySwitch\\history.txt";
        std::wstring historyDir = std::wstring(appDataPath) + L"\\EnhancedDisplaySwitch";
        CreateDirectoryW(historyDir.c_str(), NULL);
        std::wofstream historyFile(historyFilePath, std::ios::out | std::ios::trunc);
        if (historyFile.is_open()) {
            historyFile << mode;
            historyFile.close();
        }
    }
}

std::wstring getLastMode() {
    wchar_t appDataPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, appDataPath))) {
        std::wstring historyFilePath = std::wstring(appDataPath) + L"\\EnhancedDisplaySwitch\\history.txt";

        std::wifstream historyFile(historyFilePath);
        if (historyFile.is_open()) {
            std::wstring mode;
            std::getline(historyFile, mode);
            historyFile.close();
            if (!mode.empty()) {
                return mode;
            }
        }
    }
    return L"No last mode found.";
}

void runDisplaySwitch(const std::wstring& mode) {
    std::wstring commandLine;
    commandLine = L"displaySwitch.exe " + mode;
    LPWSTR commandLineW = const_cast<LPWSTR>(commandLine.c_str());
    std::wprintf(L"Running command: %s\n", commandLineW);

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    BOOL result = CreateProcess(
        NULL,                  // No module name (use command line)
        commandLineW,          // Command line
        NULL,                  // Process handle not inheritable
        NULL,                  // Thread handle not inheritable
        FALSE,                 // Set handle inheritance to FALSE
        0,                     // No creation flags
        NULL,                  // Use parent's environment block
        NULL,                  // Use parent's starting directory
        &si,                   // Pointer to STARTUPINFO structure
        &pi                    // Pointer to PROCESS_INFORMATION structure
        );

    if (result) {
        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        std::wprintf(L"Failed to start displaySwitch.exe. Error: %lu\n", GetLastError());
    }
}

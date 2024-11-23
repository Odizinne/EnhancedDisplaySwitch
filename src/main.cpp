#include "enhanceddisplayswitch.h"
#include <iostream>
#include <string>

int wmain(int argc, wchar_t* argv[])
{
    if (argc < 2) {
        std::wcerr << L"No argument provided. Use /? -h or --help for usage information.\n";
        return 1;
    }

    std::wstring arg = argv[1];

    if (arg == L"-h" || arg == L"--help" || arg == L"/?") {
        displayHelp();
    } else if (arg == L"/internal" || arg == L"1") {
        runDisplaySwitch(1);
        saveLastMode(L"internal");
    } else if (arg == L"/clone" || arg == L"2") {
        runDisplaySwitch(2);
        saveLastMode(L"clone");
    } else if (arg == L"/extend" || arg == L"3") {
        runDisplaySwitch(3);
        saveLastMode(L"extend");
    } else if (arg == L"/external" || arg == L"4") {
        runDisplaySwitch(4);
        saveLastMode(L"external");
    } else if (arg == L"/lastmode" || arg == L"5") {
        std::wcout << getLastMode() << std::endl;
    } else {
        std::wcerr << L"Invalid argument. Use /? -h or --help for usage information.\n";
        return 1;
    }

    return 0;
}

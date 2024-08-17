#include "enhanceddisplayswitch.h"
#include <iostream>
#include <string>

int wmain(int argc, wchar_t* argv[])
{
    if (argc < 2) {
        std::wcerr << L"No argument provided. Use -h or --help for usage information.\n";
        return 1;
    }

    std::wstring arg = argv[1];

    if (arg == L"-h" || arg == L"--help") {
        displayHelp();
    } else if (arg == L"--clone" || arg == L"--internal" || arg == L"--external" || arg == L"--extend") {
        runDisplaySwitch(arg);
        saveLastMode(arg.substr(2));
    } else if (arg == L"--lastmode") {
        std::wcout << getLastMode() << std::endl;
    } else {
        std::wcerr << L"Invalid argument. Use -h or --help for usage information.\n";
        return 1;
    }

    return 0;
}

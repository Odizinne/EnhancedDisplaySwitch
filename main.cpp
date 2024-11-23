#include "EnhancedDisplaySwitch.h"
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
        EDS::displayHelp();
    } else if (arg == L"/internal" || arg == L"1") {
        EDS::runDisplaySwitch(1);
    } else if (arg == L"/clone" || arg == L"2") {
        EDS::runDisplaySwitch(2);
    } else if (arg == L"/extend" || arg == L"3") {
       EDS:: runDisplaySwitch(3);
    } else if (arg == L"/external" || arg == L"4") {
        EDS::runDisplaySwitch(4);
    } else if (arg == L"/lastmode" || arg == L"5") {
        std::wcout << EDS::getLastMode() << std::endl;
    } else {
        std::wcerr << L"Invalid argument. Use /? -h or --help for usage information.\n";
        return 1;
    }

    return 0;
}

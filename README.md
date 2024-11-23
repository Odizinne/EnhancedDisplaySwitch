# EnhancedDisplaySwitch

`DisplaySwitch.exe` alternative providing access to last used command.  
Made for scripting and automation purpose.

## Requirements

- [Microsoft Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe)

## Download

You can get latest release [here](https://github.com/Odizinne/EnhancedDisplaySwitch/releases/latest).

## Usage

Add it to your path or simply call it from where you need it.

```
Usage: EnhancedDisplaySwitch.exe [option]
Options:
  /internal or 1     Set display mode to internal
  /clone    or 2     Set display mode to clone
  /external or 3     Set display mode to external
  /extend   or 4     Set display mode to extend
  /lastmode or 5     Show the last used mode
  -h, --help, /?     Display this help message
```

When setting mode, EnhancedDisplaySwitch will create `HKEY_CURRENT_USER\Software\EnhancedDisplaySwitch\LastMode` and save the last used mode inside the string.
When `/lastmode` is used, reg string content will be returned.


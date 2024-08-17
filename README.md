# EnhancedDisplaySwitch

displayswitch.exe wrapper providing access to last used command.  
Made for scripting and automation purpose.

## Requirements

- [Microsoft Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe)

## Usage

Add it to your path or simply call it from where you need it.

- `--help`: Show available commands.
- `--internal` / `--external` / `--extend` / `--clone`: call displayswitch.exe with specified arg.  
Write set mode to `%appdata%\EnhancedDisplaySwitch\history.txt`.
- `--lastmode`: print last set mode.
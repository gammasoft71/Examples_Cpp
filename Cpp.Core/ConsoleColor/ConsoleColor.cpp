#include <iostream>
#include <memory>
#include <cstdio>
#include <string>

template<typename ... Args>
auto string_format(const std::string& format, Args&& ... args) -> std::string {
  std::string formated_string(snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args) ...), 0); 
  snprintf(&formated_string[0], formated_string.size() + 1, format.c_str(), std::forward<Args>(args) ...);
  return formated_string;
}

/// @remarks To enable ANSI colors on Windows, add following key in the registry :
/// [HKEY_CURRENT_USER\Console] "VirtualTerminalLevel"=dword:00000001

using namespace std;

auto main() -> int {
  const auto backgroundWhite = "\033[107m";
  const auto foregroundBlue = "\033[94m";
  const auto foregroundDarkGray = "\033[90m";
  const auto resetBackground = "\033[49m";
  const auto resetForeground = "\033[39m";

  cout << string_format("                                     %s%s▓▓▓▓▓▓▓%s%s                                    ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                                %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s                                ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                            %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s                            ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                        %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s                        ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                    %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s                     ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s                 ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("             %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s             ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("         %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s         ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("     %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s     ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("   %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓%s%s  ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("  %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                              ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█%s%s ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format(" %s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                        ▓▓▓▓▓▓▓▓▓▓▓█████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                            ▓▓▓▓▓█████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                   ▓▓▓▓▓▓▓▓                  ██████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓           █████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     █████████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████████████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████   ████████   █████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████████▀▀▀   ▀▀▀██▀▀▀   ▀▀▀██%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓▓▓▓▓▓▓▓▓▓███████████████████         ██         ██%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓██████████████████████████   ████████   █████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓██████████████████████████████▄▄▄████████▄▄▄█████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ███████████████████████████████████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ███████████████████     █████████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                 ██████████████            █████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█                    ██████                   ██████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓▓▓▓▓██████                                          ███████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s%s▓▓▓▓▓▓▓▓▓███████████                                        ████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format(" %s%s▓▓▓▓▓█████████████████                                  ███████████████████████%s%s", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("  %s%s████████████████████████                            █████████████████████████%s%s ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("  %s%s████████████████████████████                    ████████████████████████████%s%s  ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("      %s%s██████████████████████████████         █████████████████████████████%s%s      ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("          %s%s█████████████████████████████████████████████████████████████%s%s         ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("             %s%s██████████████████████████████████████████████████████%s%s             ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                 %s%s██████████████████████████████████████████████%s%s                 ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                     %s%s██████████████████████████████████████%s%s                     ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                         %s%s██████████████████████████████%s%s                         ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                             %s%s██████████████████████%s%s                             ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                                %s%s████████████████%s%s                                ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("                                    %s%s████████%s%s                                    ", backgroundWhite, foregroundBlue, resetBackground, resetForeground) << endl;
  cout << string_format("%s                                  Modern C++17                                  %s", foregroundDarkGray, resetForeground) << endl;
  cout << string_format("%s C++17 is the name for the most recent revision of the ISO/IEC 14882 standard   %s", foregroundDarkGray, resetForeground) << endl;
  cout << string_format("%s                       for the C++ programming language.                        %s", foregroundDarkGray, resetForeground) << endl;
}

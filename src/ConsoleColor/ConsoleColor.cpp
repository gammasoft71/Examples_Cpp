#include <iostream>
#include <string>

using namespace std;
using namespace string_literals;

/// @remarks To enable ANSI colors on Windows, add following key in the registry :
/// [HKEY_CURRENT_USER\Console] "VirtualTerminalLevel"=dword:00000001

int main() {
  const auto backgroundWhite = "\033[107m"s;
  const auto foregroundBlue = "\033[94m"s;
  const auto foregroundDarkGray = "\033[90m"s;
  const auto resetBackground = "\033[49m"s;
  const auto resetForeground = "\033[39m"s;

  cout << "                                     "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                                    "s << endl;
  cout << "                                "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                                "s << endl;
  cout << "                            "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                            "s << endl;
  cout << "                        "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                        "s << endl;
  cout << "                    "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                     "s << endl;
  cout << "                "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "                 "s << endl;
  cout << "             "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "             "s << endl;
  cout << "         "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "         "s << endl;
  cout << "     "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "     "s << endl;
  cout << "   "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"s + resetBackground + resetForeground + "  "s << endl;
  cout << "  "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                              ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█"s + resetBackground + resetForeground + " "s << endl;
  cout << " "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                        ▓▓▓▓▓▓▓▓▓▓▓█████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                                            ▓▓▓▓▓█████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                   ▓▓▓▓▓▓▓▓                  ██████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓           █████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     █████████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█████████████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████████████   ████████   █████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████████▀▀▀   ▀▀▀██▀▀▀   ▀▀▀██"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓▓▓▓▓▓▓▓▓▓███████████████████         ██         ██"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓██████████████████████████   ████████   █████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓              ▓▓▓██████████████████████████████▄▄▄████████▄▄▄█████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓               ███████████████████████████████████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                ███████████████████     █████████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓                 ██████████████            █████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█                    ██████                   ██████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓▓▓▓▓██████                                          ███████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << ""s + backgroundWhite + foregroundBlue + "▓▓▓▓▓▓▓▓▓███████████                                        ████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << " "s + backgroundWhite + foregroundBlue + "▓▓▓▓▓█████████████████                                  ███████████████████████"s + resetBackground + resetForeground + ""s << endl;
  cout << "  "s + backgroundWhite + foregroundBlue + "████████████████████████                            █████████████████████████"s + resetBackground + resetForeground + " "s << endl;
  cout << "  "s + backgroundWhite + foregroundBlue + "████████████████████████████                    ████████████████████████████"s + resetBackground + resetForeground + "  "s << endl;
  cout << "      "s + backgroundWhite + foregroundBlue + "██████████████████████████████         █████████████████████████████"s + resetBackground + resetForeground + "      "s << endl;
  cout << "          "s + backgroundWhite + foregroundBlue + "█████████████████████████████████████████████████████████████"s + resetBackground + resetForeground + "         "s << endl;
  cout << "             "s + backgroundWhite + foregroundBlue + "██████████████████████████████████████████████████████"s + resetBackground + resetForeground + "             "s << endl;
  cout << "                 "s + backgroundWhite + foregroundBlue + "██████████████████████████████████████████████"s + resetBackground + resetForeground + "                 "s << endl;
  cout << "                     "s + backgroundWhite + foregroundBlue + "██████████████████████████████████████"s + resetBackground + resetForeground + "                     "s << endl;
  cout << "                         "s + backgroundWhite + foregroundBlue + "██████████████████████████████"s + resetBackground + resetForeground + "                         "s << endl;
  cout << "                             "s + backgroundWhite + foregroundBlue + "██████████████████████"s + resetBackground + resetForeground + "                             "s << endl;
  cout << "                                "s + backgroundWhite + foregroundBlue + "████████████████"s + resetBackground + resetForeground + "                                "s << endl;
  cout << "                                    "s + backgroundWhite + foregroundBlue + "████████"s + resetBackground + resetForeground + "                                    "s << endl;
  cout << foregroundDarkGray;
  cout << "                                  Modern C++17                                  "s << endl;
  cout << " C++17 is the name for the most recent revision of the ISO/IEC 14882 standard   "s << endl;
  cout << "                       for the C++ programming language.                        "s << endl;
  cout << resetBackground + resetForeground;
}

#pragma once
#include <iostream>
#include <map>

/// @remarks To enable ANSI colors on Windows, add following key in the registry :
/// [HKEY_CURRENT_USER\Console] "VirtualTerminalLevel"=dword:00000001

namespace console {
  enum class console_color {black, dark_blue, dark_green, dark_cyan, dark_red, dark_magenta, dark_yellow, gray, dark_gray, blue, green, cyan, red, magenta, yellow, white};

  inline void background_color(console_color color) noexcept {
    static std::map<console_color, const char*> colors {{console_color::black, "\033[40m"}, {console_color::dark_blue, "\033[44m"}, {console_color::dark_green, "\033[42m"}, {console_color::dark_cyan, "\033[46m"}, {console_color::dark_red, "\033[41m"}, {console_color::dark_magenta, "\033[45m"}, {console_color::dark_yellow, "\033[43m"}, {console_color::gray, "\033[47m"}, {console_color::dark_gray, "\033[100m"}, {console_color::blue, "\033[104m"}, {console_color::green, "\033[102m"}, {console_color::cyan, "\033[106m"}, {console_color::red, "\033[101m"}, {console_color::magenta, "\033[105m"}, {console_color::yellow, "\033[103m"}, {console_color::white, "\033[107m"}};
    if (colors.find(color) != colors.end()) std::cout << colors[color] << std::flush;
  }

  inline void foreground_color(console_color color) noexcept {
    static std::map<console_color, const char*> colors {{console_color::black, "\033[30m"}, {console_color::dark_blue, "\033[34m"}, {console_color::dark_green, "\033[32m"}, {console_color::dark_cyan, "\033[36m"}, {console_color::dark_red, "\033[31m"}, {console_color::dark_magenta, "\033[35m"}, {console_color::dark_yellow, "\033[33m"}, {console_color::gray, "\033[37m"}, {console_color::dark_gray, "\033[90m"}, {console_color::blue, "\033[94m"}, {console_color::green, "\033[92m"}, {console_color::cyan, "\033[96m"}, {console_color::red, "\033[91m"}, {console_color::magenta, "\033[95m"}, {console_color::yellow, "\033[93m"}, {console_color::white, "\033[97m"}};
    if (colors.find(color) != colors.end()) std::cout << colors[color] << std::flush;
  }
  
  inline void reset_color() noexcept {std::cout << "\033[49m\033[39m" << std::flush;}
};

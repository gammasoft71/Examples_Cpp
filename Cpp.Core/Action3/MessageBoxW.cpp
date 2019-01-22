#include "MessageBox.h"

#if defined(_WIN32)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h>

message_box::result message_box::show(const std::string& message, const std::string& title) {
  MessageBox(GetActiveWindow(), message.c_str(), title.c_str(), MB_OK);
  return 0;
}
#endif

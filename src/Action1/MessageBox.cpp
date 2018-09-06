#include "MessageBox.h"

#if defined(__linx__)
#include <gtkmm/messagedialog.h>

void message_box(const std::string& message) {
  static Gtk::Window emptyWindow;
  Gtk::MessageDialog dialog(*emptyWindow, message.c_str(), true /* use_markup */, Gtk::MESSAGE_OTHER, Gtk::BUTTONS_OK, true);
  dialog.set_modal();
  dialog.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  dialog.run();
}
#endif

#if defined(_WIN32)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h>

void message_box(const std::string& message) {
  MessageBox(GetActiveWindow(), message.c_str(), "", MB_OK);
}
#endif

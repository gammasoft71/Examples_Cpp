#include "MessageBox.h"

#if defined(__linux__)
#include <gtkmm/messagedialog.h>

message_box::result message_box::show(const std::string& message, const std::string& title) {
  static Glib::RefPtr<Gtk::Application> __application__ = Gtk::Application::create();
  static Gtk::Window emptyWindow;
  Gtk::MessageDialog dialog(emptyWindow, message.c_str(), true, Gtk::MESSAGE_OTHER, Gtk::BUTTONS_OK, true);
  dialog.set_title(title.c_str());
  dialog.set_modal();
  dialog.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  dialog.run();
  return 0;
}
#endif

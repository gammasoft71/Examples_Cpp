#include <functional>
#include <iostream>
#include "MessageBox.h"

using namespace std;

template<typename T>
using action = std::function<void(T)>;

static void show_windows_message(const string& message) {
  message_box::show(message);
}

static void write_line(const string& message) {
  cout << message << endl;
}

auto main(int argc, char* argv[]) -> int {
  action<const string&> message_target = argc > 1 ? [](const string& s) {show_windows_message(s);} : [](const string& s) {write_line(s);};
  
  message_target("Hello, World!");
}

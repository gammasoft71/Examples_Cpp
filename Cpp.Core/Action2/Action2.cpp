#include <functional>
#include <iostream>
#include "MessageBox.h"

using namespace std;

template<typename T>
using action = function<void(T)>;

void show_windows_message(const string& message) {
  message_box::show(message);
}

void write_line(const string& message) {
  cout << message << endl;
}

auto main(int argc, char* argv[]) -> int {
  action<const string&> message_target = argc > 1 ? show_windows_message : write_line;
  
  message_target("Hello, World!");
}

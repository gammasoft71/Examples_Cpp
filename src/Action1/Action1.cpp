#include <functional>
#include <iostream>
#include "MessageBox.h"

using namespace std;

using DisplayMessage = std::function<void(const string&)>;

static void ShowWindowsMessage(const string& message) {
  message_box(message);
}

static void WriteLine(const string& message) {
  cout << message << endl;
}

int main(int argc, char* argv[]) {
  DisplayMessage messageTarget;
  
  if (argc > 1)
    messageTarget = ShowWindowsMessage;
  else
    messageTarget = WriteLine;
  
  messageTarget("Hello, World!");
}

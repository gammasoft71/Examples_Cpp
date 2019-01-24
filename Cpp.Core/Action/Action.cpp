#include <iostream>
#include <algorithm>

using namespace std;

void print(const string& s) {
  cout << s << endl;
}

auto main() -> int {
  auto names = {"Bruce", "Alfred", "Tim", "Richard"};

  // Display the contents of the initializer_list using the print method.
  for_each(names.begin(), names.end(), print);

  // The following demonstrates the lambda of C++ to display the contents of the initializer_list to the console.
  for_each(names.begin(), names.end(), [](const auto& s) {
    cout << s << endl;
  });

}

// This code produces the following output:
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard

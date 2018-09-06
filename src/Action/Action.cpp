#include <iostream>
#include <list>
#include <string>

using namespace std;

void print(const string& s) {
  cout << s << endl;
}

int main(int argc, char* argv[]) {
  list<string> names;
  names.push_back("Bruce");
  names.push_back("Alfred");
  names.push_back("Tim");
  names.push_back("Richard");

  // Display the contents of the list using the Print method.
  for_each(names.begin(), names.end(), print);

  // The following demonstrates the lambda of C++ to display the contents of the list to the console.
  for_each(names.begin(), names.end(), [](const string& s) {
    std::cout << s << endl;
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

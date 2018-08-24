#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Hello ";
  cout << "World!" << endl;
  cout << "Enter your name: ";
  string name;
  cin >> name;
  cout << "Good day, ";
  cout << name;
  cout << "!" << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!

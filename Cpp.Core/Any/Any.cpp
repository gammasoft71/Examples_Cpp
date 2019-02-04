#include <any>
#include <iostream>
#include <string>

using namespace std;
using namespace std::string_literals;

int main() {
  // Create an empty a
  any a;
  cout << "a " << (a.has_value() ? "has" : "hasn't") << " value" << endl;
  cout << "a = " << endl;
  cout << endl;
  
  // Assign integer to a
  a = 42;
  cout << "a " << (any_cast<int>(&a) ? "is" : "isn't") << " int" << endl;
  cout << "a " << (any_cast<string>(&a) ? "is" : "isn't") << " string" << endl;
  cout << "a = " << any_cast<int>(a) << endl;
  auto i = any_cast<int32_t>(a);
  cout << "i = " << i << endl;
  cout << endl;

  // Assign string to a
  a = "Hello, World!"s;
  cout << "a " << (any_cast<int>(&a) ? "is" : "isn't") << " int" << endl;
  cout << "a " << (any_cast<string>(&a) ? "is" : "isn't") << " string" << endl;
  cout << "a = " << any_cast<string>(a) << endl;
  string s = any_cast<string>(a);
  cout << "s = " << s << endl;
  cout << endl;

  // Cast any of type string into a int
  try {
    auto i2 = any_cast<int>(a);
    cout << "i2 = " << i2 << endl;
  } catch (const bad_any_cast&) {
    cout << "'a' cannot be cast to int" << endl;
  }
}

// This code produces the following output:
//
// a hasn't value
// a =
// 
// a is int
// a isn't string
// a = 42
// i = 42
// 
// a isn't int
// a is string
// a = Hello, World!
// s = Hello, World!
// 
// 'a' cannot be cast to int

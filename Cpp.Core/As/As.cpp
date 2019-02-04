#include <any>
#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;
using namespace string_literals;

auto main() -> int {
  double d = 41.6;
  int i1 = (int)(d);
  int i2 = static_cast<int>(d);
  cout << "d = " << d << ", (int)d = " << i1 << ", static_cast<int>(d) = " << i2 << endl;

  int i = 42;
  string s1 = to_string(i);
  cout << "i = " << i << ", to_string(i) = " << s1 << endl;

  any a = "string"s;
  s1 = any_cast<string>(a);
  cout << "a = string, any_cast<string>(a) = " << s1 << endl;

  stringstream sstr;
  try {
    s1 = dynamic_cast<string&>(sstr);
    cout << "dynamic_cast<string&>(sstr) = " << s1 << endl;
  } catch (const bad_cast& e) {
    cout << "Bad cast : " << e.what() << " !" << endl;
  }

  shared_ptr<stringstream> sp = make_shared<stringstream>();
  shared_ptr<string> str = dynamic_pointer_cast<string>(sp);
  if (str == nullptr)
    cout << "Bad cast!" << endl;
}

// This code produces the following output:
//
// d = 41.6, (int)d = 41, static_cast<int>(d) = 41
// i = 42, to_string(i) = 42
// a = string, any_cast<string>(a) = string
// Bad cast : std::bad_cast !

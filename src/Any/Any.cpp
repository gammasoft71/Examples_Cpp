#include <iostream>
#include <experimental/any>

using namespace std;
using namespace std::experimental;

int main(int argc, char* argv[]) {
  any a;
  cout << "a " << (a.empty() ? "hasn't" : "has") << " value" << endl;
  //cout << "a = " << a << endl;
  cout << endl;
  
  // Assign integer to a
  a = 42;
  cout << "a = " << *any_cast<int32_t>(&a) << endl;
  cout << "a " <<  (any_cast<int32_t>(&a) ? "is" : "isn't") << " int" << endl;
  /*
  Console::WriteLine("a {0} string", is<string>(a) ? "is" : "isn't");
  int i = a;
  Console::WriteLine("i = {0}", i);
  cout << endl;

  // Assign string to a
  a = "Hello, World!";
  Console::WriteLine("a = {0}", a);
  Console::WriteLine("a {0} int", is<int32>(a) ? "is" : "isn't");
  Console::WriteLine("a {0} string", is<string>(a) ? "is" : "isn't");
  string s = a;
  Console::WriteLine("s = {0}", s);
  cout << endl;

  // Cast any of type string into a int
  try {
    int i2 = a;
    Console::WriteLine("i2 = {0}", i2);
  } catch (const InvalidCastException&) {
    Console::WriteLine("a cannot cast in int");
  }
   */
}

// This code produces the following output:
//
// Hello, World!

#include <any>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace string_literals;

using array_list = vector<any>;

void print_values(const array_list& my_list) {
  for (any obj : my_list)
    if (any_cast<string>(&obj))
      cout << "   " << any_cast<string>(obj);
   cout << endl;
}

// The main entry point for the application.
auto main() -> int {
  // Creates and initializes a new ArrayList.
  array_list my_al;
  my_al.push_back("Hello"s);
  my_al.push_back("World"s);
  my_al.push_back("!"s);

  // Displays the properties and values of the ArrayList.
  cout << "my_al" << endl;
  cout << "    Count:    " << my_al.size() << endl;
  cout << "    Capacity: " << my_al.capacity() << endl;
  cout << "    Values:" ;
  print_values(my_al);
}

// This code example produces the following output:
//
// my_al
//     Count:    3
//     Capacity: 4
//     Values:   Hello   World   !

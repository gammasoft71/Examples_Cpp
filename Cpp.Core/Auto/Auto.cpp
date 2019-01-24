#include <iostream>
#include <map>
#include <string>

using namespace std;

using string_pair = pair<std::string, string>;
using string_dictionary = map<std::string, string>;

auto to_string(const string_pair& pair) {
  return "[" + pair.first + ", " + pair.second +  "]";
}

auto main() -> int {
  string_dictionary pets = {{"Belgian Sheperd", "Dog"}, {"Bengal", "Cat"}, {"Cocker", "Dog"}, {"Dalmatian", "Dog"}, {"Egyptian Mau", "Cat"}, {"Persian", "Cat"}, {"Pied Mutation Cockatiel", "Bird"}};

  // you can use auto type insted :
  // string_pair item
  for (auto item : pets)
    cout << to_string(item) << endl;
}

// This code produces the following output:
//
// [Belgian Sheperd, Dog]
// [Bengal, Cat]
// [Cocker, Dog]
// [Dalmatian, Dog]
// [Egyptian Mau, Cat]
// [Persian, Cat]
// [Pied Mutation Cockatiel, Bird]

#include <iostream>
#include <map>
#include <string>

using namespace std;

using string_pair = std::pair<std::string, std::string>;
using string_dictionary = std::map<std::string, std::string>;

std::string to_string(const string_pair& pair) {
  return "[" + pair.first + ", " + pair.second +  "]";
}

int main(int argc, char* argv[]) {
  string_dictionary pets;
  pets["Belgian Sheperd"] = "Dog";
  pets["Bengal"] = "Cat";
  pets["Cocker"] = "Dog";
  pets["Dalmatian"] = "Dog";
  pets["Egyptian Mau"] = "Cat";
  pets["Persian"] = "Cat";
  pets["Pied Mutation Cockatiel"] = "Bird";

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

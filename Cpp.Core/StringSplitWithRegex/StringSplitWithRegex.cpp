#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;
using namespace std::literals;

auto main() -> int {
  auto str = "One Two Three Four\nFive"s;
  regex rgx("(\x9|\xA|\xB|\xC|\xD|\x20)+");
  
  vector<string> strings;
  for (std::sregex_token_iterator it(str.begin(), str.end(), rgx, -1), end; it != end; ++it)
    strings.push_back(*it);
  
  cout << "strings::Length = " << strings.size() << endl;
  for (auto s : strings)
    std::cout << s << '\n';
}

// This code produces the following output:
//
// strings.Length = 5
// One
// Two
// Three
// Four
// Five

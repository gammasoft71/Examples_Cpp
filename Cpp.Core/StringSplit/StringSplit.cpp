#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::literals;

vector<string> split_string(const string& str, const vector<char>& splitCharSeparators = {}, uint32_t count = std::numeric_limits<uint32_t>::max(), bool removeEmptyEntries = false) {
  if (count == 0) return {};
  if (count == 1) return {str};
  
  vector<string> list;
  string subString;
  vector<char> separators = splitCharSeparators.size() == 0 ? vector<char> {9, 10, 11, 12, 13, 32} : splitCharSeparators;
  for (string::const_iterator it = str.begin(); it != str.end(); it++) {
    bool isSeparator =  std::find(separators.begin(), separators.end(), *it) != separators.end();
    if (!isSeparator) subString.append(string(1, *it));
    if ((it - str.begin() == str.length() - 1 || isSeparator) && (subString.length() > 0 || (subString.length() == 0 && removeEmptyEntries == false))) {
      if (list.size() == count - 1) {
        list.push_back(subString + string(str.c_str(), it - str.begin() + (isSeparator ? 1 : 0), str.length() - (it - str.begin()) + (isSeparator ? 1 : 0)));
        return list;
      }
      list.push_back(subString);
      subString.clear();
    }
  }
  
  return list;
}

auto main() -> int {
  auto strings = split_string("One Two Three Four\nFive");
  
  cout << "strings::Length = " << strings.size() << endl;
  for (auto s : strings)
    cout << s << endl;
}

// This code produces the following output:
//
// strings.Length = 5
// One
// Two
// Three
// Four
// Five

#include <algorithm>
#include <any>
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
using namespace std::string_literals;

using array_list = vector<any>;

auto to_upper(const string& str) {
  stringstream result;
  for_each(str.begin(), str.end(), [&](const char& value) {result << static_cast<char>(toupper(value));});
  return result.str();
}

auto join(const string& separator, const array_list& al) {
  stringstream result;
  for (size_t index = 0; index < al.size(); ++index) {
    if (index != 0) result << separator;
    if (any_cast<string>(&al[index])) result << any_cast<string>(al[index]);
    if (any_cast<int>(&al[index])) result << any_cast<int>(al[index]);
    if (any_cast<float>(&al[index])) result << any_cast<float>(al[index]);
    if (any_cast<hours>(&al[index])) result << any_cast<hours>(al[index]).count();
  }
  return result.str();
}

// The main entry point for the application.
auto main() -> int {
  array_list al = {42, "This is a string"s, "Another string"s, 4.2f,  2h};

  cout << "al = {" << join(", ", al) << "}" << endl;
  cout << endl;

  for (auto item : al) {
    if (any_cast<string>(&item)) cout << "\"" << to_upper(any_cast<string>(item)) << "\"" << endl;
    if (any_cast<int>(&item)) cout << any_cast<int>(item) << endl;
    if (any_cast<float>(&item)) cout << any_cast<float>(item) << endl;
    if (any_cast<hours>(&item)) cout << any_cast<hours>(item).count() << "h" << endl;
  }
}

// This code example produces the following output:
//
// al = {42, This is a string, Another string, 4.2, 2}
//
// 42
// "THIS IS A STRING"
// "ANOTHER STRING"
// 4.2
// 02h

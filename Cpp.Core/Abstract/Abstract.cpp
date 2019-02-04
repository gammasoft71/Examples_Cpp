#include <iostream>
#include <string>

using namespace std;
using namespace string_literals;

struct TextReader {
  virtual ~TextReader() = default;
  virtual auto ReadByte() -> char = 0;
  
  auto ReadLine() {
    string line;
    for (int b = ReadByte(); b != -1 && b != '\n'; b = ReadByte())
      line += static_cast<char>(b);
    return line;
  }
  
  auto ReadText() {
    string text;
    for (int b = ReadByte(); b != -1; b = ReadByte())
      text += static_cast<char>(b);
    return text;
  }
};

class StringReader : public TextReader {
public:
  StringReader(const string& value) : iterator(value.begin()), end(value.end()) {}
  
  auto ReadByte() -> char override {
    if (this->iterator == this->end) return -1;
    return *this->iterator++;
  }
  
private:
  string::const_iterator iterator;
  string::const_iterator end;
};

auto main() -> int {
  auto text = "Line 1\nLine 2\nLine 3"s;
  
  StringReader sr(text);
  cout << sr.ReadLine() << endl;
  cout << sr.ReadLine() << endl;
  cout << sr.ReadLine() << endl;
}

// This code produces the following output:
//
// Line 1
// Line 2
// Line 3

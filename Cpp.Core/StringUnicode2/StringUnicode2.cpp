#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

#if WIN32
#include <Windows.h>
#else
int SetConsoleOutputCP(int codePage) {return 1;}
#endif

using namespace std;

int main(int argc, char* argv[]) {
  wstring str = L"\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A\u002c\u0020\u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA\U0001F428\u0021";
  
  wstring result = L"";
  for(wchar_t c : str) {
    wstringstream ss;
    ss << c << L" ";
    result += ss.str();
  }
  auto s = string(result.size() * sizeof(wchar_t), 0);
  wcstombs(&s[0], result.c_str(), s.size() * sizeof(wchar_t));
  cout << s << endl;

  result = L"";
  for(wchar_t c : str) {
    wstringstream ss;
    ss << (c > 0xFFFF ? L"\\U" : L"\\u") << right << setfill(L'0') << setw(c > 0xFFFF ? 8 : 4) << hex << (int)c;
    result += ss.str();
  }
  s = string(result.size() * sizeof(wchar_t), 0);
  wcstombs(&s[0], result.c_str(), s.size() * sizeof(wchar_t));
  cout << s << endl;
}

// 日 本 語 の ひ ら が な ,   漢 字 と カ タ カ ナ 🐨 !
// \u65e5\u672c\u8a9e\u306e\u3072\u3089\u304c\u306a\u002c\u0020\u6f22\u5b57\u3068\u30ab\u30bf\u30ab\u30ca\U0001f428\u0021

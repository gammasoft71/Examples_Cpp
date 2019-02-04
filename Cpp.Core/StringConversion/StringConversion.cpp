#include <iostream>
#include <codecvt>
#include <locale>
#include <numeric>

using namespace std;

auto main() -> int {
  auto s = "こんにちは世界！"s;

  wstring ws(s.size(), 0);
  mbstowcs(&ws[0], s.c_str(), s.size());
}

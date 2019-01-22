#include <iostream>
#include <codecvt>
#include <locale>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
  string s = "こんにちは世界！";

  wstring ws(s.size(), 0);
  mbstowcs(&ws[0], s.c_str(), s.size());

}

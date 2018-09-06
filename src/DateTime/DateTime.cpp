#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

std::string to_string(const std::chrono::system_clock::time_point& time_point) {
  time_t time = std::chrono::system_clock::to_time_t(time_point);
  std::string result = std::ctime(&time);
  return result.substr(0, result.size()-1);;
}

bool roughly_equals(const std::chrono::system_clock::time_point& time, const std::chrono::system_clock::time_point& time_with_window, int window_in_seconds, int frequency_in_seconds) {
  std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(time_with_window - time);
  int delta = seconds.count() % frequency_in_seconds;
  
  delta = delta > window_in_seconds ? frequency_in_seconds - delta : delta;
  
  return abs(delta) < window_in_seconds;
}

int main(int argc, char* argv[]) {
  int window = 10;
  int freq = 60 * 60 * 2; // 2 hours;

  system_clock::time_point d1 = system_clock::now();
  
  system_clock::time_point d2 = d1 + seconds(2 * window);
  system_clock::time_point d3 = d1 + seconds(-2 * window);
  system_clock::time_point d4 = d1 + seconds(window / 2);
  system_clock::time_point d5 = d1 + seconds(-window / 2);
  
  system_clock::time_point d6 = d1 + hours(2) + seconds(2 * window);
  system_clock::time_point d7 = d1 + hours(2) + seconds(-2 * window);
  system_clock::time_point d8 = d1 + hours(2) + seconds(window / 2);
  system_clock::time_point d9 = d1 + hours(2) + seconds(-window / 2);
  
  cout << "d1 (" << to_string(d1 )<< " ) ~= d1 (" << to_string(d1) << "): " << (roughly_equals(d1, d1, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d2 (" << to_string(d2) << "): " << (roughly_equals(d1, d2, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d3 (" << to_string(d3) << "): " << (roughly_equals(d1, d3, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d4 (" << to_string(d3) << "): " << (roughly_equals(d1, d4, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d5 (" << to_string(d3) << "): " << (roughly_equals(d1, d5, window, freq) ? "true" : "false") << endl;
  
  cout << "d1 (" << to_string(d1 )<< " ) ~= d1 (" << to_string(d6) << "): " << (roughly_equals(d1, d6, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d2 (" << to_string(d7) << "): " << (roughly_equals(d1, d7, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d3 (" << to_string(d8) << "): " << (roughly_equals(d1, d8, window, freq) ? "true" : "false") << endl;
  cout << "d1 (" << to_string(d1 )<< " ) ~= d4 (" << to_string(d9) << "): " << (roughly_equals(d1, d9, window, freq) ? "true" : "false") << endl;
}

// This code produces the following output:
//
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d1 (Thu Sep  6 15:59:02 2018): true
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d2 (Thu Sep  6 15:59:22 2018): false
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d3 (Thu Sep  6 15:58:42 2018): false
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d4 (Thu Sep  6 15:58:42 2018): true
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d5 (Thu Sep  6 15:58:42 2018): true
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d1 (Thu Sep  6 17:59:22 2018): false
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d2 (Thu Sep  6 17:58:42 2018): false
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d3 (Thu Sep  6 17:59:07 2018): true
// d1 (Thu Sep  6 15:59:02 2018 ) ~= d4 (Thu Sep  6 17:58:57 2018): true

#include <exception>
#include <iostream>
#include <string>

using namespace std;

auto divide_by_two(int num) {
  // If num is an odd number, throw an ArgumentException.
  if ((num & 1) == 1)
    throw invalid_argument("Number must be even");

  // num is even, return half of its value.
  return num / 2;
}

// The main entry point for the application.
int main() {
  // ArgumentException is not thrown because 10 is an even number.
  cout << "10 divided by 2 is " << divide_by_two(10) << endl;
  try {
    // ArgumentException is thrown because 7 is not an even number.
    cout << "7 divided by 2 is " << divide_by_two(7) << endl;
  } catch (const invalid_argument&) {
    // Show the user that 7 cannot be divided by 2.
    cout << "7 is not divided by 2 integrally." << endl;
  }
}

// This code produces the following output:
//
// 10 divided by 2 is 5
// 7 is not divided by 2 integrally.

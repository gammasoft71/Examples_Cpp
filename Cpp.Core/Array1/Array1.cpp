#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The main entry point for the application.
auto main() -> int {
  // make a single dimension array
  vector<int> my_array_1(5);

  // make an array from native array
  int my_native_array[] = {10, 20, 30, 40, 50, 60, 70};
  vector<int> my_array_3(my_native_array, my_native_array + 7);

  // make an array with initialiser list
  vector<int> my_array_4 = {100, 200, 300, 400, 500, 600, 700};

  int index = 0;
  // show the array values
  cout << "The Array contains the following values:" << endl;
  for (int value : my_array_3)
    cout << "[" << index++ << "]" << value << endl;
}

// This code example produces the following output:
//
// The Array contains the following values:
// [0] 10
// [1] 20
// [2] 30
// [3] 40
// [4] 50
// [5] 60
// [6] 70

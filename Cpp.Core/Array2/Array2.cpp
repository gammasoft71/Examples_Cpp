#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_values(const vector<vector<vector<int>>>& my_arr) {
  for (size_t i = 0; i < my_arr.size(); i++) {
    for (size_t j = 0; j < my_arr[i].size(); j++) {
      for (size_t k = 0; k < my_arr[i][j].size(); k++) {
        cout << "\t" << my_arr[i][j][k];
      }
      cout << endl;
    }
  }
}

// The main entry point for the application.
auto main() -> int {
  // Creates and initializes a new three-dimensional Array of type int.
  vector<vector<vector<int>>> my_arr(2, vector<vector<int>>(3, vector<int> (4)));
  for (size_t i = 0; i < my_arr.size(); i++)
    for (size_t j = 0; j < my_arr[i].size(); j++)
      for (size_t k = 0; k < my_arr[i][j].size(); k++)
        my_arr[i][j][k] = (i * 100) + (j * 10) + k;

  cout << "The Array has 3 dimension(s) and a total of " << my_arr.size() * my_arr[0].size() * my_arr[0][0].size() << " elements." << endl;
  cout << "\tLength\tLower\tUpper" << endl;
  cout << "0:\t" << my_arr.size() << "\t0\t" << my_arr.size() - 1 << endl;
  cout << "1:\t" << my_arr[0].size() << "\t0\t" << my_arr[0].size() - 1 << endl;
  cout << "2:\t" << my_arr[0][0].size() << "\t0\t" << my_arr[0][0].size() - 1 << endl;

  // Displays the contents of the Array.
  cout << "The Array contains the following values:" << endl;
  print_values(my_arr);
}

// This code example produces the following output:
//
// The Array has 3 dimension(s) and a total of 24 elements.
//         Length  Lower   Upper
// 0:      2       0       1
// 1:      3       0       2
// 2:      4       0       3
// The Array contains the following values:
//         0       1       2       3
//         10      11      12      13
//         20      21      22      23
//         100     101     102     103
//         110     111     112     113
//         120     121     122     123

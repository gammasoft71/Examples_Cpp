#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

// The main entry point for the application.
auto main() -> int {
  // Instantiate random number generator using system-supplied value as seed.
  minstd_rand rand_generator(random_device{}());
  
  // Generate and display 5 random byte (integer) values.
  vector<uint8_t> bytes(5);
  uniform_int_distribution<int32_t> rand_byte_distribution(0, numeric_limits<uint8_t>::max());
  for_each(bytes.begin(), bytes.end(), [&](uint8_t& value) {value = static_cast<uint8_t>(rand_byte_distribution(rand_generator));});

  cout << "Five random byte values:" << endl;
  for (uint8_t byteValue : bytes)
    cout << setw(5) << static_cast<int>(byteValue);
  cout << endl;
  
  // Generate and display 5 random integers.
  cout << "Five random integer values:" << endl;
  uniform_int_distribution<int32_t> rand_int_distribution(numeric_limits<int32_t>::min());
  for (int ctr = 0; ctr <= 4; ctr++)
    cout << setw(15) << rand_int_distribution(rand_generator);
  cout << endl;
  
  // Generate and display 5 random integers between 0 and 100.//
  cout << "Five random integers between 0 and 100:" << endl;
  uniform_int_distribution<int32_t> rand_int_0_100_distribution(0, 100);
  for (int ctr = 0; ctr <= 4; ctr++)
    cout << setw(10) << rand_int_0_100_distribution(rand_generator);
  cout << endl;
  
  // Generate and display 5 random integers from 50 to 100.
  cout << "Five random integers between 50 and 100:" << endl;
  uniform_int_distribution<int32_t> rand_int_50_100_distribution(50, 100);
  for (int ctr = 0; ctr <= 4; ctr++)
    cout << setw(10) << rand_int_50_100_distribution(rand_generator);
  cout << endl;

  // Generate and display 5 random floating point values from 0 to 1.
  cout << "Five Doubles:" << endl;
  uniform_real_distribution<double> rand_double_distribution;
  for (int ctr = 0; ctr <= 4; ctr++)
    cout << setw(10) << rand_double_distribution(rand_generator);
  cout << endl;

  // Generate and display 5 random floating point values from 0 to 5.
  cout << "Five Doubles between 0 and 5" << endl;
  uniform_real_distribution<double> rand_double_0_5_distribution(0, 5);
  for (int ctr = 0; ctr <= 4; ctr++)
    cout << setw(10) << rand_double_0_5_distribution(rand_generator);
  cout << endl;
}

// This code produces the following output:
//
//   Five random byte values:
//      83  150  213  251  143
//   Five random integer values:
//         309514098    -1675642838    -1722923713    -1018113968      354020448
//   Five random integers between 0 and 100:
//            9        49        94        36        33
//   Five random integers between 50 and 100:
//           57        53        83        60        76
//   Five Doubles:
//    0.0239899 0.0247499   0.22295  0.124891 0.0632575
//   Five Doubles between 0 and 5
//       3.8619  0.520773    2.5082   4.53484   2.65078

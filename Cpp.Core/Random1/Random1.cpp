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
  vector<uint8_t> bytes1(100);
  vector<uint8_t> bytes2(100);
  minstd_rand rand_generator1(random_device{}());
  minstd_rand rand_generator2(random_device{}());
  uniform_int_distribution<int32_t> rand_byte_distribution(0, numeric_limits<uint8_t>::max());

  for_each(bytes1.begin(), bytes1.end(), [&](uint8_t& value) {value = static_cast<int8_t>(rand_byte_distribution(rand_generator1));});
  for_each(bytes2.begin(), bytes2.end(), [&](uint8_t& value) {value = static_cast<uint8_t>(rand_byte_distribution(rand_generator2));});

  cout << "First Series:" << endl;
  for (size_t i = 0; i < bytes1.size(); i++) {
    cout << setw(5) << static_cast<int>(bytes1[i]);
    if ((i + 1) % 10 == 0)
      cout << endl;
  }

  cout << endl;
  cout << "Second Series:" << endl;
  for (size_t i = 0; i < bytes2.size(); i++) {
    cout << setw(5) << static_cast<int>(bytes2[i]);
    if ((i + 1) % 10 == 0)
      cout << endl;
  }
}

// This code produces the following output:
//
// First Series:
//   217   71  212  132   89    6  110   38   66  243
//   194  101   65  242  144  233   88   34  126  224
//   180  157  242  209   82  125   37  178   70  190
//   232   60  199  132   40  138  212   98  232  242
//   178  160    0   51  139  180    6   71  136   58
//   136  128   48  128  153    2   76  243   75  237
//    72  189   68  167   57  214  223   64  126  193
//   160  232  143  183  252  254   55  202  147  154
//   107  162   83   56  218   81   47  210  252   41
//    44  221  230  243  213  253  130  114  155   62
// 
// Second Series:
//   201  133  105    1  176   19  127  172   15   15
//   189  125  218   62  149  221  239  199   14  214
//    75  250   26   54    0    1   53  146  102   50
//    19   68  128  148   34   30   83  234  162  112
//   248   17   41    8    4  148  215   24  108   49
//   195   81  207  160  220  152   84  216  239   31
//    51   56   56   94  248  125  119  158   67  198
//    23   45    0  247  217   92   94   91  198  130
//   228  199  136  196   51   18  145   46   59  186
//    83  143   70   30  129  138   58  237   73   82

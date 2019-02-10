#include <iostream>
#include <iomanip>
#include <ciso646>

using namespace std;

void check_attributes() {
  cout << "Attributes" << endl;
  
#if __has_cpp_attribute(assert)
  cout << "  assert             [" << setw(10) << 201806L << "]" << endl;
#else
  cout << "  assert             [" << "no present]" << endl;
#endif
  
#if __has_cpp_attribute(carries_dependency)
  cout << "  carries_dependency [" << setw(10) << 200809L << "]" << endl;
#else
  cout << "  carries_dependency [" << "no present]" << endl;
#endif
  
#if __has_cpp_attribute(deprecated)
  cout << "  deprecated         [" << setw(10) << 201309L << "]" << endl;
#else
  cout << "  deprecated         [" << "no present]" << endl;
#endif
  
#if __has_cpp_attribute(ensures)
  cout << "  ensures            [" << setw(10) << 201806L << "]" << endl;
#else
  cout << "  ensures            [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(expects)
  cout << "  expects            [" << setw(10) << 201806L << "]" << endl;
#else
  cout << "  expects            [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(fallthrough)
  cout << "  fallthrough        [" << setw(10) << 201603L << "]" << endl;
#else
  cout << "  fallthrough        [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(likely)
  cout << "  likely             [" << setw(10) << 201803L << "]" << endl;
#else
  cout << "  likely             [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(maybe_unused)
  cout << "  maybe_unused       [" << setw(10) << 201603L << "]" << endl;
#else
  cout << "  maybe_unuse        [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(no_unique_address)
  cout << "  no_unique_address  [" << setw(10) << 201803L << "]" << endl;
#else
  cout << "  no_unique_address  [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(nodiscard)
  cout << "  nodiscard          [" << setw(10) << 201603L << "]" << endl;
#else
  cout << "  nodiscard          [" << "no present]" << endl;
#endif
  
#if __has_cpp_attribute(noreturn)
  cout << "  noreturn           [" << setw(10) << 200809L << "]" << endl;
#else
  cout << "  noreturn           [" << "no present]" << endl;
#endif

#if __has_cpp_attribute(unlikely)
  cout << "  unlikely           [" << setw(10) << 201803L << "]" << endl;
#else
  cout << "  unlikely           [" << "no present]" << endl;
#endif

  cout << endl;
}

void check_language_features() {
  cout << "Language features" << endl;
  
#if defined(__cpp_aggregate_bases)
  cout << "  __cpp_aggregate_bases           [" << setw(10) << __cpp_aggregate_bases << "]" << endl;
#else
  cout << "  __cpp_aggregate_bases           [" << "no present]" << endl;
#endif

#if defined(__cpp_aggregate_nsdmi)
  cout << "  __cpp_aggregate_nsdmi           [" << setw(10) << __cpp_aggregate_nsdmi << "]" << endl;
#else
  cout << "  __cpp_aggregate_nsdmi           [" << "no present]" << endl;
#endif

#if defined(__cpp_alias_templates)
  cout << "  __cpp_alias_templates           [" << setw(10) << __cpp_alias_templates << "]" << endl;
#else
  cout << "  __cpp_alias_templates           [" << "no present]" << endl;
#endif

#if defined(__cpp_aligned_new)
  cout << "  __cpp_aligned_new               [" << setw(10) << __cpp_aligned_new << "]" << endl;
#else
  cout << "  __cpp_aligned_new               [" << "no present]" << endl;
#endif

  
  
#if defined(__cpp_impl_three_way_comparison)
  cout << "  __cpp_impl_three_way_comparison [" << setw(10) << __cpp_impl_three_way_comparison << "]" << endl;
#else
  cout << "  __cpp_impl_three_way_comparison [" << "no present]" << endl;
#endif

  cout << endl;
}

#include <memory>

void check_library_features() {
  cout << "Library features" << endl;
  
#if defined(__cpp_lib_addressof_constexpr)
  cout << "  __cpp_lib_addressof_constexpr   [" << setw(10) << __cpp_lib_addressof_constexpr << "]" << endl;
#else
  cout << "  __cpp_lib_addressof_constexpr   [" << "no present]" << endl;
#endif

  cout << endl;
}

auto main() -> int {
  check_attributes();
  check_language_features();
  check_library_features();
}

// This code produces the following output:
//
// Hello, World!

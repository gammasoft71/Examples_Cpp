#include <cstdint>
#include <exception>
#include <iostream>
#include <thread>

using namespace std;

auto main() -> int {
  exception_ptr exceptionPointer;

  thread thread([&] {
    try {
      throw logic_error("Ouch there are an exception !");
    } catch (...) {
      exceptionPointer = current_exception();
    }
  });
  
  thread.join();

  if (exceptionPointer) {
    try {
      rethrow_exception(exceptionPointer);
    } catch (const logic_error& exception) {
      cout << exception.what() << endl;
    }
  }
}


// This code produces the following output:
//
// Ouch there are an exception !

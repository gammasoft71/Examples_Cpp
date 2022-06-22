#include <cstdint>
#include <exception>
#include <iostream>
#include <thread>

using namespace std;

auto main() -> int {
  // exception_ptr to store the thread exception
  exception_ptr except_ptr;
  
  thread thread([&] {
    try {
      // Generation of classic exception...
      throw logic_error("Ouch there are an exception !");
    } catch (...) {
      // stores the current exception in the except_ptr
      except_ptr = current_exception();
    }
  });
  
  thread.join();
  
  // Check if an exception has occurred in the thread
  if (except_ptr) {
    try {
      // Rethorws the exception pointer
      rethrow_exception(except_ptr);
    } catch (const logic_error& exception) {
      // At the end catch the exception
      cout << exception.what() << endl;
    }
  }
}

// This code produces the following output:
//
// Ouch there are an exception !

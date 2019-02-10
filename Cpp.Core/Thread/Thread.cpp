#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace chrono_literals;

// The ThreadProc method is called when the thread starts.
// It loops ten times, writing to the console and yielding
// the rest of its time slice each time, and then ends.
void ThreadProc() {
  for (int i = 0; i < 10; i++) {
    cout << "ThreadProc: " << i << endl;
    cout.flush();
    // Yield the rest of the time slice.
    this_thread::sleep_for(0ns);
  }
}

auto main() -> int {
  cout << "Main thread: Start a second thread." << endl;
  cout.flush();
  // Start ThreadProc.  Note that on a uniprocessor, the new
  // thread does not get any processor time until the main thread
  // is preempted or yields.  Uncomment the this_thread::sleep_for that
  // follows to see the difference.
  thread t(ThreadProc);
  //this_thread::sleep_for(0ns);

  for (int i = 0; i < 4; i++) {
    cout << "Main thread: Do some work." << endl;
    cout.flush();
    this_thread::sleep_for(0ns);
  }
  
  cout << "Main thread: Call Join(), to wait until ThreadProc ends." << endl;
  cout.flush();
  t.join();
  cout << "Main thread: ThreadProc.Join has returned." << endl;
  cout.flush();
}

// This code produces the following output:
//
// Hello, World!

#include<iostream>
#include<thread>

/*
 * Copy from
 * https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
 */

//This function will be called from a thread
void call_from_thread(int tid) {
  std::cout << "Launched by thread " << tid << std::endl;
}

static const int num_threads = 10;

int main() {

  std::thread t[num_threads];


  for (int i = 0; i < num_threads; ++i) {
    t[i] = std::thread(call_from_thread,i);
  }

  std::cout << "Launched from the main\n";

  for (int i = 0; i < num_threads; ++i) {
    t[i].join();
  }

  return 0;
}

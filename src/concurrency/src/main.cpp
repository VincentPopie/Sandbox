#include<atomic>
#include<functional>
#include<iostream>
#include<thread>
#include<vector>

/*
 * Copy from
 * https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
 */

//This function will be called from a thread
void call_from_thread(int tid) {
  std::cout << "Launched by thread " << tid << std::endl;
}

std::vector<int> bounds(int nbr_splits, int nbr_elements){
  std::vector<int> limits;

  limits.push_back(0);
  for (int i=1; i < nbr_splits; i++){
    limits.push_back(nbr_elements/nbr_splits*i);
  }
  limits.push_back(nbr_elements);
  return limits;
}

void dot_product_fail(const std::vector<int>& iVectorL,
    const std::vector<int>& iVectorR,
    int& oResult,
    int lowerBound,
    int upperBound) {

  //int partialSum = 0;
  for (int i = lowerBound; i < upperBound; i++) {
    oResult += iVectorL[i] * iVectorR[i];
  }
  //oResult += partialSum;
}

void dot_product(const std::vector<int>& iVectorL,
    const std::vector<int>& iVectorR,
    std::atomic<int>& oResult,
    int lowerBound,
    int upperBound) {

  int partialSum = 0;
  for (int i = lowerBound; i < upperBound; i++) {
    partialSum += iVectorL[i] * iVectorR[i];
  }
  oResult += partialSum;
}



int main() {
  int nbr_elements = 100000;
  int nbr_threads = 2;
  int resultFail = 0;
  std::atomic<int> result(0);

  std::vector<std::thread> threads;


  std::vector<int> v1(nbr_elements,1), v2(nbr_elements,2);
  std::vector<int> limits = bounds(nbr_threads, nbr_elements);


  for (int i = 0; i < nbr_threads; i++) {
    threads.push_back(std::thread(dot_product_fail,std::cref(v1), std::cref(v2), std::ref(resultFail), limits[i], limits[i+1]));
  }


  for (auto& t : threads) {
    t.join();
  }

  std::cout<< "Result: " << resultFail << std::endl;
  threads.clear();

  for (int i = 0; i < nbr_threads; i++) {
    threads.push_back(std::thread(dot_product, std::cref(v1), std::cref(v2), std::ref(result), limits[i], limits[i+1]));
  }


  for (auto& t : threads) {
    t.join();
  }

  std::cout<< "Result: " << result << std::endl;


  return 0;
}

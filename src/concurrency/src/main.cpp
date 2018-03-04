#include<atomic>
#include<chrono>
#include<functional>
#include<future>
#include<iostream>
#include<thread>
#include<vector>

/*
 * Copy from
 * https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
 */


/*
 * Compute the begin and end indices of a given amount of subdivision of a vector
 */
std::vector<int> bounds(int nbr_splits, int nbr_elements){
  std::vector<int> limits;

  limits.push_back(0);
  for (int i=1; i < nbr_splits; i++){
    limits.push_back(nbr_elements/nbr_splits*i);
  }
  limits.push_back(nbr_elements);
  return limits;
}


/*
 * Compute the dot product of a two vectors
 * Not optimized for parallelization, as a locked resource is used in the loop
 */
template<typename T>
void dotProduct(const std::vector<int>& iVectorL,
    const std::vector<int>& iVectorR,
    T& oResult,
    int lowerBound,
    int upperBound) {
  for (int i = lowerBound; i < upperBound; i++) {
    oResult += iVectorL[i] * iVectorR[i];
  }
}

/*
 * Compute the dot product of a two vectors
 * Optimized for parallelization, as a locked resource is used only for an assignment
 */
template<typename T>
void dotProductWithPartial(const std::vector<int>& iVectorL,
    const std::vector<int>& iVectorR,
    T& oResult,
    int lowerBound,
    int upperBound) {

  int partialSum = 0;
  for (int i = lowerBound; i < upperBound; i++) {
    partialSum += iVectorL[i] * iVectorR[i];
  }
  oResult += partialSum;
}

/*
 * Dot Product written to use std::asynchronus
 */

int dotProductFut(const std::vector<int>& iVectorL,
    const std::vector<int>& iVectorR,
    int lowerBound,
    int upperBound) {
  int result=0;
  for (int i = lowerBound; i < upperBound; i++) {
    result += iVectorL[i] * iVectorR[i];
  }
  return result;
}

/*
 * Enum to call decide which function call
 */
enum class DotProduct {
  DotProduct,
  DotProductWithPartial
};



/*
 * Test the dot Product in different case
 */
template <typename T>
void testDotProductThread(const std::vector<int>& v1,
    const std::vector<int>& v2,
    const std::vector<int>& limits,
    int nbr_threads,
    DotProduct algorithmChoice) {

  T result(0);
  std::vector<std::thread> threads;

  auto t1 = std::chrono::system_clock::now();

  std::function<void(const std::vector<int>& iVectorL,
      const std::vector<int>& iVectorR,
      T& oResult,
      int lowerBound,
      int upperBound)> dotProductCall;

  if (algorithmChoice == DotProduct::DotProduct) {
    dotProductCall = dotProduct<T>;
  } else if (algorithmChoice == DotProduct::DotProductWithPartial)  {
    dotProductCall = dotProductWithPartial<T>;
  }


  for (int i = 0; i < nbr_threads; i++) {
    threads.emplace_back(std::thread(dotProductCall,std::cref(v1), std::cref(v2), std::ref(result), limits[i], limits[i+1]));
  }


  for (auto& t : threads) {
    t.join();
  }
  auto t2 = std::chrono::system_clock::now();

  std::cout<< "Result: " << result << std::endl;
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  std::cout << "Duration: " << duration <<  " ms" << std::endl << std::endl;

  threads.clear();
}



void testDotProductAsynchronus(const std::vector<int>& v1,
    const std::vector<int>& v2,
    const std::vector<int>& limits,
    int nbr_asynch){

  int result(0);
  std::vector<std::future<int>> futures;

  auto t1 = std::chrono::system_clock::now();


  for (int i = 0; i < nbr_asynch; i++) {
    futures.emplace_back(std::async(std::launch::async, dotProductFut, std::cref(v1), std::cref(v2), limits[i], limits[i+1]));
  }

  for (auto& fut : futures) {
    result += fut.get();
  }

  auto t2 = std::chrono::system_clock::now();

  std::cout<< "Result: " << result << std::endl;
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  std::cout << "Duration: " << duration <<  " ms" << std::endl << std::endl;

  futures.clear();
}


int main() {

  int nbr_elements = 100000000;
  int nbr_threads = std::thread::hardware_concurrency();

  std::vector<int> v1(nbr_elements,1), v2(nbr_elements,2);
  std::vector<int> limits = bounds(nbr_threads, nbr_elements);

  std::vector<DotProduct> algorithms {DotProduct::DotProduct, DotProduct::DotProductWithPartial};

  for (auto algorithm: algorithms) {
    testDotProductThread<int>(v1, v2, limits, nbr_threads, algorithm);
    testDotProductThread<std::atomic<int>>(v1, v2, limits, nbr_threads, algorithm);
  }

  testDotProductAsynchronus(v1, v2, limits, nbr_threads);


  return 0;
}

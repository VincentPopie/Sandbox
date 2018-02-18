#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>

#include "Foo.hpp"
#include "FooWithoutCompare.hpp"

/*
 * COnvert into a string the content of a vector
 */
template <typename T>
std::string vectorContentToString(const std::vector<T>& iVector) {
  std::string vectorContent;
  for_each(iVector.cbegin(), iVector.cend(),
      [&vectorContent](auto aFoo){ vectorContent += std::to_string(aFoo.getRecord()); vectorContent += " ";});
  return vectorContent;
}


/*
 * Implement a lambda expression in a sort aigorithm
 */
void lambdaInSortAlgorithm() {

  //Foo overload < operator, no need to provide a comparison function in sort algorithm
  Foo a(1);
  Foo b(2);

  std::vector<Foo> aVector{b,a};

  std::cout << "Before sorting: " << vectorContentToString(aVector) << std::endl;
  std::sort(aVector.begin(), aVector.end());
  std::cout << "After sorting: " << vectorContentToString(aVector) << std::endl;

  /****************************************************************************************************/
  FooWithoutCompare c(1);
  FooWithoutCompare d(2);

  std::vector<FooWithoutCompare> aVectorBis{d,c};

  std::cout << "Before sorting: " << vectorContentToString(aVectorBis) << std::endl;
  std::sort(aVectorBis.begin(), aVectorBis.end(),[](auto& a,auto& b){return (a.getRecord() < b.getRecord());});
  std::cout << "After sorting: " << vectorContentToString(aVectorBis) << std::endl;
}




/*
 * Implement a lambda expression in a find_if algorithm
 */
void lambdaInFindIfAlgorithm() {
  std::map<std::string, Foo> aMap;
  aMap.emplace(std::make_pair("Toto",Foo(1)));
  aMap.emplace(std::make_pair("Tata",Foo(5)));
  aMap.emplace(std::make_pair("Titi",Foo(2)));

  auto it = std::find_if(aMap.cbegin(),aMap.cend(),[](auto& a) {return(a.second.getRecord() == 5);});
  if (it != aMap.cend()) {
    std::cout << "Key found: " << it->first << ", value found: " << std::to_string(it->second.getRecord()) << std::endl;
  } else {
    std::cout << "Nothing was found." << std::endl;
  }
}


int main() {

  lambdaInSortAlgorithm();
  lambdaInFindIfAlgorithm();


}

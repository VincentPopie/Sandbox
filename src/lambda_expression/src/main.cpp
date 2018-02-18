#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>


class Foo {
public:
  Foo(int iRecord): _record(iRecord) {}
  int getRecord() const { return _record;}
  bool operator< (const Foo& iCompare) {
    return (this->_record < iCompare._record);
  }

private:
  int _record;
};


class FooWithoutCompare {
public:
  FooWithoutCompare(int iRecord): _record(iRecord) {}
  int getRecord() const { return _record;}

private:
  int _record;
};


template <typename T>
std::string vectorContentToString(const std::vector<T>& iVector) {
  std::string vectorContent;
  for_each(iVector.cbegin(), iVector.cend(), [&vectorContent](auto aFoo){ vectorContent += std::to_string(aFoo.getRecord()); vectorContent += " ";});
  return vectorContent;
}


int main() {

  FooWithoutCompare a(1);
  FooWithoutCompare b(2);

  std::vector<FooWithoutCompare> aVector{b,a};

  std::cout << vectorContentToString(aVector) << std::endl;
  std::sort(aVector.begin(), aVector.end(),[](auto& a,auto& b){return (a.getRecord() < b.getRecord());});
  std::cout << vectorContentToString(aVector) << std::endl;

  /******************************************************************************/

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

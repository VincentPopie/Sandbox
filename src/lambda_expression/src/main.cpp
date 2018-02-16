#include<algorithm>
#include<iostream>
#include<string>
#include<vector>


class Foo {
public:
  Foo(int iRecord): _record(iRecord) {}
  int getRecord() { return _record;}
  bool operator< (const Foo& iCompare) {
    return (this->_record < iCompare._record);
  }

private:
  int _record;
};


class FooWithoutCompare {
public:
  FooWithoutCompare(int iRecord): _record(iRecord) {}
  int getRecord() { return _record;}

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
}

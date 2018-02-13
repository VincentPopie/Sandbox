#include "SmartPtr.hpp"

#include<iostream>
#include "Foo.hpp"

//Shared ownership - will cause a big bang when destructed
/*SmartPtr::SmartPtr(const SmartPtr& aCopy) {
  _foo = aCopy._foo;
}*/

//Move Constructor => ownership transfered
SmartPtr::SmartPtr(SmartPtr&& aMove) {
  std::cout << "Call SmartPtr move constructor" << std::endl;
  _foo = aMove._foo;
  aMove._foo = nullptr;
}

SmartPtr::~SmartPtr(){
  std::cout << "Call SmartPtr destructor...";
  if (_foo != nullptr) {
    std::cout << "Foo is not null, it will be destructed" << std::endl;
    delete _foo;
  }
}

SmartPtr& SmartPtr::operator= (SmartPtr&& aMove) {
  std::cout << "Call SmartPtr move assignment operator" << std::endl;
  if (_foo != nullptr) {
    delete _foo;
  }

  _foo = aMove._foo;
  aMove._foo = nullptr;
  return *this;
}

std::string SmartPtr::getName() const {
  return _foo->getName();
}

bool SmartPtr::operator!= (const SmartPtr& compare) const {
  return (_foo != compare._foo);
}


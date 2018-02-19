#pragma once
#include "SmartPtr.hpp"

#include<iostream>

//Shared ownership - will cause a big bang when destructed
/*SmartPtr::SmartPtr(const SmartPtr& aCopy) {
  _foo = aCopy._foo;
}*/

//Move Constructor => ownership transfered
template <typename T> SmartPtr<T>::SmartPtr(SmartPtr<T>&& aMove) {
  std::cout << "Call SmartPtr move constructor" << std::endl;
  _ptr = aMove._ptr;
  aMove._ptr = nullptr;
}

template <typename T> SmartPtr<T>::~SmartPtr(){
  std::cout << "Call SmartPtr destructor...";
  if (_ptr != nullptr) {
    std::cout << " foo is not null, it will be destructed" << std::endl;
    delete _ptr;
  } else {
    std::cout << " foo is null" << std::endl;
  }

}

template <typename T> SmartPtr<T>& SmartPtr<T>::operator= (SmartPtr<T>&& aMove) {
  std::cout << "Call SmartPtr move assignment operator" << std::endl;
  if (_ptr != nullptr) {
    delete _ptr;
  }

  _ptr = aMove._ptr;
  aMove._ptr = nullptr;
  return *this;
}


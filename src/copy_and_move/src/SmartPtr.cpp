#include "SmartPtr.hpp"

#include<iostream>

//Shared ownership - will cause a big bang when destructed
/*SmartPtr::SmartPtr(const SmartPtr& aCopy) {
  _foo = aCopy._foo;
}*/

//Move Constructor => ownership transfered
template <class T> SmartPtr<T>::SmartPtr(SmartPtr<T>&& aMove) {
  std::cout << "Call SmartPtr move constructor" << std::endl;
  _ptr = aMove._ptr;
  aMove._ptr = nullptr;
}

template <class T> SmartPtr<T>::~SmartPtr(){
  std::cout << "Call SmartPtr destructor...";
  if (_ptr != nullptr) {
    std::cout << " foo is not null, it will be destructed" << std::endl;
    delete _ptr;
  } else {
    std::cout << " foo is null" << std::endl;
  }

}

template <class T> SmartPtr<T>& SmartPtr<T>::operator= (SmartPtr<T>&& aMove) {
  std::cout << "Call SmartPtr move assignment operator" << std::endl;
  if (_ptr != nullptr) {
    delete _ptr;
  }

  _ptr = aMove._ptr;
  aMove._ptr = nullptr;
  return *this;
}

/*
 *

std::string SmartPtr::getName() const {
  return _foo->getName();
}*/


template <class T> bool SmartPtr<T>::operator!= (const SmartPtr<T>& compare) const {
  return (_ptr != compare._ptr);
}


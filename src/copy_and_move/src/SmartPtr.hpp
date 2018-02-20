#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class SmartPtr {
public:
  SmartPtr(): _ptr(nullptr) {};

  explicit SmartPtr(T* iPtr): _ptr(iPtr) {};

  SmartPtr(const SmartPtr<T>& aCopy) = delete;

  SmartPtr(SmartPtr<T>&& aMove) {
    std::cout << "Call SmartPtr move constructor" << std::endl;
    _ptr = aMove._ptr;
    aMove._ptr = nullptr;
  }

  SmartPtr& operator= (SmartPtr<T>&& aMove){
    std::cout << "Call SmartPtr move assignment operator" << std::endl;
    if (_ptr != nullptr) {
      delete _ptr;
    }

    _ptr = aMove._ptr;
    aMove._ptr = nullptr;
    return *this;
  }

  T* operator->() const
      { return _ptr; }

  ~SmartPtr() {
    std::cout << "Call SmartPtr destructor...";
    if (_ptr != nullptr) {
      std::cout << " foo is not null, it will be destructed" << std::endl;
      delete _ptr;
    } else {
      std::cout << " foo is null" << std::endl;
    }
  }

  bool operator!= (const SmartPtr<T>& compare) const {
    return (_ptr != compare._ptr);
  }

  template <typename Y>
  bool operator!= (const Y compare) const {
    return  (_ptr != compare);
  }


private:
  T* _ptr;

};

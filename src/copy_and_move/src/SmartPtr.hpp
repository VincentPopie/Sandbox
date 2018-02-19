#pragma once
#include <cstddef>

template <typename T>
class SmartPtr {
public:
  SmartPtr(): _ptr(nullptr) {};

  explicit SmartPtr(T* iPtr): _ptr(iPtr) {};

  SmartPtr(const SmartPtr<T>& aCopy) = delete;
  SmartPtr(SmartPtr<T>&& aMove);
  SmartPtr& operator= (SmartPtr<T>&& aMove);
  T* operator->() const
      { return _ptr; }
  ~SmartPtr();

  bool operator!= (const SmartPtr<T>& compare) const {
    return (_ptr != compare._ptr);
  }

  bool operator!= (const std::nullptr_t compare) const {
    return  (_ptr != compare);
  }


private:
  T* _ptr;

};

#include "SmartPtr.cpp"


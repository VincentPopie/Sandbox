#pragma once

template <class T>
class SmartPtr {
public:
  SmartPtr(): _ptr(nullptr) {};
  SmartPtr(T* iPtr): _ptr(iPtr) {};
  SmartPtr(const SmartPtr<T>& aCopy) = delete;
  SmartPtr(SmartPtr<T>&& aMove);
  SmartPtr& operator= (SmartPtr<T>&& aMove);
  T* operator->() const
      { return _ptr; }
  ~SmartPtr();

  bool operator!= (const SmartPtr<T>& compare) const;

  //std::string getName() const;

private:
  T* _ptr;

};


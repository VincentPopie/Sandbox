#pragma once
#include<string>

class Foo;

class SmartPtr {
public:
  SmartPtr(): _foo(nullptr) {};
  SmartPtr(Foo* iFoo): _foo(iFoo) {};
  SmartPtr(const SmartPtr& aCopy) = delete;
  SmartPtr(SmartPtr&& aMove);
  SmartPtr& operator= (SmartPtr&& aMove);

  ~SmartPtr();

  bool operator!= (const SmartPtr& compare) const;

  std::string getName() const;

private:
  Foo* _foo;

};


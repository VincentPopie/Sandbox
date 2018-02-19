#include "SmartWidget.hpp"

#include<iostream>
#include "Foo.hpp"


SmartWidget::SmartWidget(int iValue): _value(iValue) {
  std::string fooName = "test Foo";
  std::cout << "Call SmartWidget constructor: _value = " << iValue << ", _foo name = " << fooName << std::endl;
  _foo = SmartPtr<Foo>(new Foo(fooName));
}



std::string SmartWidget::getFooName() const {
  std::string aFooName;
  if (_foo != nullptr) {
    aFooName = _foo->getName();
  } else {
    aFooName = "foo is empty!";
  }
  return aFooName;
}

#include "SmartWidget.hpp"

#include<iostream>
#include "Foo.hpp"


SmartWidget::SmartWidget(const std::string& iName): _name(iName) {
  std::cout << "Call SmartWudget constructor" << std::endl;
  _foo = SmartPtr(new Foo("test Foo"));
}



std::string SmartWidget::getFooName() const {
  std::string aFooName;
  if (_foo != nullptr) {
    aFooName = _foo.getName();
  } else {
    aFooName = "foo is empty!";
  }
  return aFooName;
}

#include<iostream>
#include "Widget.hpp"
#include "Foo.hpp"


Widget::Widget(const std::string& iName): _name(iName) {
  _foo = new Foo("test Foo");
}

Widget::~Widget() {
  std::cout << std::endl << "Call Widget destructor" << std::endl;
  if (_foo != nullptr) {
    std::cout << "_foo is not empty, delete _foo" << std::endl << std::endl;
    delete _foo;
  }
}

std::string Widget::getFooName() const {
  std::string aFooName;
  if (_foo != nullptr) {
    aFooName = _foo->getName();
  }
  return aFooName;
}

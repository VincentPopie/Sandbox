#include<iostream>
#include "Widget.hpp"
#include "Foo.hpp"


Widget::Widget(int iValue): _value(iValue) {
  std::string fooName = "test Foo";
  std::cout << "Call Widget constructor: _value = " << iValue << ", _foo name = " << fooName << std::endl;
  _foo = new Foo(fooName);
}

Widget::Widget(const Widget& iWidget): _value(iWidget.getValue()) {
  _foo = new Foo(iWidget.getFooName());
  std::cout << "Call Widget copy constructor" << std::endl;
}

Widget::Widget(Widget&& iWidget): _value(iWidget._value),_foo(iWidget._foo) {
  iWidget._value = 0;
  iWidget._foo = nullptr;
  std::cout << "Call Widget move constructor" << std::endl;
}

Widget::~Widget() {
  std::cout << "Call Widget destructor... ";
  if (_foo != nullptr) {
    std::cout << "_foo is not empty, delete _foo" << std::endl;
    delete _foo;
  } else {
    std::cout << "_foo is empty." << std::endl;
  }
}

std::string Widget::getFooName() const {
  std::string aFooName;
  if (_foo != nullptr) {
    aFooName = _foo->getName();
  } else {
    aFooName = "_foo points to no object";
  }
  return aFooName;
}

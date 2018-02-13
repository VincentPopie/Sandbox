#include<iostream>
#include "Widget.hpp"
#include "Foo.hpp"


Widget::Widget(const std::string& iName): _name(iName) {
  std::cout << "Call constructor" << std::endl;
  _foo = new Foo("test Foo");
}

// Default copy means -> copy all data member
Widget::Widget(const Widget& iWidget): _name(iWidget.getName()) {
  _foo = new Foo(iWidget.getFooName());
  std::cout << "Call copy constructor";
}

Widget::Widget(Widget&& iWidget): _name(iWidget.getName()),_foo(iWidget.getFoo()) {
  iWidget._name = "";
  iWidget._foo = nullptr;
  std::cout << "Call the move constructor";
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
  } else {
    aFooName = "foo is empty!";
  }
  return aFooName;
}

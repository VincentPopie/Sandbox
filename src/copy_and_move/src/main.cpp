#include<iostream>
#include<string>
#include<vector>


class Foo{
public:
  Foo(const std::string& iName): _name(iName){}
  std::string getName() const { return _name;}
private:
  std::string _name;
};



class Widget {

public:
  Widget(const std::string& iName, Foo* iFoo): _name(iName), _foo(iFoo) {}
  explicit Widget(const std::string& iName);

  ~Widget();
  std::string getName() const { return _name;}
  std::string getFooName() const;

private:
  std::string _name;
  Foo* _foo;
};

Widget::Widget(const std::string& iName): _name(iName) {
  _foo = new Foo("test Foo");
}

Widget::~Widget() {
  std::cout << "Call Widget destructor" << std::endl;
  if (_foo != nullptr) {
    std::cout << "_foo is not empty, delete the object" << std::endl << std::endl;
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


int main() {


  Widget aWidget("test Widget");


  std::cout << "Widget Name: " << aWidget.getName() << std::endl
      << "Widget Foo Name: " << aWidget.getFooName() << std::endl;

  return 0;
}

#pragma once

#include<string>

class Foo;
class Widget {

public:
  Widget(const std::string& iName, Foo* iFoo): _name(iName), _foo(iFoo) {}
  Widget(const Widget& iWidget);
  Widget(Widget&& iWidget);
  explicit Widget(const std::string& iName);

  ~Widget();
  std::string getName() const { return _name;}
  Foo* getFoo() const {return _foo;}
  std::string getFooName() const;

private:
  std::string _name;
  Foo* _foo;
};


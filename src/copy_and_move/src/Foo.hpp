#pragma once

#include<string>

class Foo{
public:
  Foo(const std::string& iName): _name(iName){}
  std::string getName() const { return _name;}
private:
  std::string _name;
};



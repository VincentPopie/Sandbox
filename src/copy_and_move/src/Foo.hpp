#pragma once

#include<string>

/*
 * Class Foo contains a _name attribute.
 */
class Foo{
public:
  /*
   * Foo constructor, set the _name.
   */
  Foo(const std::string& iName): _name(iName){}

  /*
   * Retrieve Foo name.
   */
  std::string getName() const { return _name;}
private:
  std::string _name;
};



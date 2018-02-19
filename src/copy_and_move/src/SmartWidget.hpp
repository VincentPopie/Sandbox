#pragma once

#include<string>
#include"Foo.hpp"
#include"SmartPtr.hpp"

class SmartWidget {

public:

  /*
   * Smart Widget Constructor. Set the _value attribute.
   */
  explicit SmartWidget(int iValue);

  /*
   * Return the value content
   */
  int getValue() const { return _value;}

  /*
   * Return the _name parameter in Foo object pointed by _foo
   */
  std::string getFooName() const;

private:
  int _value;
  SmartPtr _foo;
};



#pragma once

#include<string>

class Foo;

/*
 * Class Widget containing a nacked pointer to a Foo object
 */
class Widget {

public:

  /*
   * Widget Constructor. Set the _value attribute.
   */
  explicit Widget(int iValue);

  /*
   * Widget copy constructor. Copy the object pointed by _foo.
   */
  Widget(const Widget& iWidget);

  /*
   * Widget move constructor. Move the object pointed by _foo and let the parameter in a safe state.
   */
  Widget(Widget&& ioWidget);


  /*
   * Widget destructor. Delete the Foo object pointed by _foo.
   */
  ~Widget();

  /*
   * Return the _value content.
   */
  int getValue() const { return _value;}


  /*
   * Return the _name parameter in Foo object pointed by _foo
   */
  std::string getFooName() const;

private:
  int _value;
  Foo* _foo;
};


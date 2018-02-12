#include<iostream>
#include<string>
#include<vector>

#include"Widget.hpp"

int main() {


  Widget aWidget("test Widget");


  std::cout << "Widget Name: " << aWidget.getName() << std::endl
      << "Widget Foo Name: " << aWidget.getFooName() << std::endl;

  return 0;
}

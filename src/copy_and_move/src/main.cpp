#include<iostream>
#include<string>
#include<vector>

#include"SmartWidget.hpp"
#include"Widget.hpp"

Widget generateWidget (int i) {

  std::cout << "Begin generate Widget..." << std::endl;
  Widget aWidget("test generate");

  // To avoid RVO
  if (i%2 == 0) {
    std::cout << "Generate Widget before return..." << std::endl;
    return aWidget;
  }

  return Widget("test generate bis");
}



SmartWidget generateSmartWidget (int i) {

  std::cout << "Begin generate SmartWidget..." << std::endl;
  SmartWidget aSmartWidget("test generate");

  // To avoid RVO
  if (i%2 == 0) {
    std::cout << "Generate SmartWidget before return..." << std::endl;
    return aSmartWidget;
  }

  return SmartWidget("test generate bis");
}




int main() {


  Widget aWidget = generateWidget(2);

  std::cout << "Widget Name: " << aWidget.getName() << std::endl
      << "Widget Foo Name: " << aWidget.getFooName() << std::endl << std::endl << std::endl;


  SmartWidget aSmartWidget = generateSmartWidget(2);
  //SmartWidget aSmartWidgetBis = aSmartWidget; //Won't compile copy deleted
  SmartWidget aSmartWidgetBis = std::move(aSmartWidget); //Won't compile copy deleted


  std::cout << "SmartWidget Name: " << aSmartWidget.getName() << std::endl
      << "SmartWidget Foo Name: " << aSmartWidget.getFooName() << std::endl;
  return 0;
}

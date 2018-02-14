#include<iostream>
#include<string>
#include<vector>

#include"SmartWidget.hpp"
#include"Widget.hpp"

Widget generateWidgetAvoidingRVO (int i) {

  std::cout << "Begin generate Widget..." << std::endl;
  Widget aWidget(1);

  // To avoid RVO
  if (i%2 == 0) {
    std::cout << "End generate Widget (before return)..." << std::endl;
    return aWidget;
  }

  std::cout << "End generate Widget (before return)..." << std::endl;
  return Widget(2);
}

void testWidgetCopyMove() {

  std::cout << std::endl << std::endl << "Begin test copyable and movable Widget..." << std::endl << std::endl;

  Widget aWidget = generateWidgetAvoidingRVO(2);

  std::cout << std::endl << "Verify Widget content in the 'main' function: " << std::endl;
  std::cout << "Widget Name: " << aWidget.getValue() << std::endl
      << "Widget Foo Name: " << aWidget.getFooName() << std::endl;
  std::cout << "End test copyable and movable Widget..." << std::endl;
}


SmartWidget generateSmartWidget (int i) {

  std::cout << std::endl << std::endl << "Begin generate SmartWidget..." << std::endl;
  SmartWidget aSmartWidget("test generate");

  // To avoid RVO
  if (i%2 == 0) {
    std::cout << "Generate SmartWidget before return..." << std::endl;
    return aSmartWidget;
  }

  return SmartWidget("test generate bis");
}




int main() {

  testWidgetCopyMove();



  SmartWidget aSmartWidget = generateSmartWidget(2);
  //SmartWidget aSmartWidgetBis = aSmartWidget; //Won't compile copy deleted
  SmartWidget aSmartWidgetBis = std::move(aSmartWidget); //Won't compile copy deleted


  std::cout << "SmartWidget Name: " << aSmartWidget.getName() << std::endl
      << "SmartWidget Foo Name: " << aSmartWidget.getFooName() << std::endl;
  return 0;
}

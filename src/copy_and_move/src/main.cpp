#include<iostream>
#include<string>
#include<vector>

#include"SmartWidget.hpp"
#include"Widget.hpp"


template <typename T>
T generateWidgetAvoidingRVO (int i) {

  std::cout << "Begin generator..." << std::endl;
  T aWidget(1);

  // To avoid RVO
  if (i%2 == 0) {
    std::cout << "End generator (before return)..." << std::endl;
    return aWidget;
  }

  std::cout << "End generator (before return)..." << std::endl;
  return T(2);
}




void testWidgetCopyMove() {

  std::cout << std::endl << std::endl << "Begin test copyable and movable Widget..." << std::endl << std::endl;

  Widget aWidget = generateWidgetAvoidingRVO<Widget>(2);

  std::cout << std::endl << "Verify Widget content in the 'main' function: " << std::endl;
  std::cout << "Widget Name: " << aWidget.getValue() << std::endl
      << "Widget Foo Name: " << aWidget.getFooName() << std::endl;
  std::cout << "End test copyable and movable Widget..." << std::endl;
}


void testWidgetMove() {

  std::cout << std::endl << std::endl << "Begin test non-copyable and movable Widget..." << std::endl << std::endl;

  SmartWidget aSmartWidget = generateWidgetAvoidingRVO<SmartWidget>(2);
  //SmartWidget aSmartWidgetBis = aSmartWidget; //Won't compile copy deleted
  //SmartWidget aSmartWidgetBis = std::move(aSmartWidget); Move assignment is working

  std::cout << std::endl << "Verify Widget content in the 'main' function: " << std::endl;
  std::cout << "SmartWidget Name: " << aSmartWidget.getValue() << std::endl
      << "SmartWidget Foo Name: " << aSmartWidget.getFooName() << std::endl;
  std::cout << "End test non copyable and movable Widget..." << std::endl;
}



int main() {

  testWidgetCopyMove();
  testWidgetMove();

  return 0;
}

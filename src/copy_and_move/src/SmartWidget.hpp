#pragma once

#include<string>
#include"Foo.hpp"
#include"SmartPtr.hpp"

class SmartWidget {

public:
  explicit SmartWidget(const std::string& iName);
  std::string getName() const { return _name;}
  std::string getFooName() const;

private:
  std::string _name;
  SmartPtr _foo;
};



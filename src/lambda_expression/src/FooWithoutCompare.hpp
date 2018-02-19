#pragma once

class FooWithoutCompare {
public:
  FooWithoutCompare(int iRecord): _record(iRecord) {}
  int getRecord() const { return _record;}

private:
  int _record;
};

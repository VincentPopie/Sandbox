#pragma once

class Foo {
public:
  Foo(int iRecord): _record(iRecord) {}
  int getRecord() const { return _record;}
  bool operator< (const Foo& iCompare) {
    return (this->_record < iCompare._record);
  }

private:
  int _record;
};

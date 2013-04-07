#include "BasicTypeDesc.h"

BasicTypeDesc::BasicTypeDesc(string t): type(t) {
}

BasicTypeDesc::~BasicTypeDesc() {}

string BasicTypeDesc::getType() {
  return type;
}

void BasicTypeDesc::setType(string t) {
  type = t;
}

#include "BasicTypeDesc.h"

BasicTypeDesc::BasicTypeDesc() {
  type = "default";
}

BasicTypeDesc::BasicTypeDesc(string t): type(t) {
}

BasicTypeDesc::BasicTypeDesc(const BasicTypeDesc& btype) {
  type = btype.type;
}

BasicTypeDesc::~BasicTypeDesc() {}

string BasicTypeDesc::getType() {
  return type;
}

void BasicTypeDesc::setType(string t) {
  type = t;
}


#include "ArrayTypeDesc.h"

using namespace std;

ArrayTypeDesc::ArrayTypeDesc(string t):
    BasicTypeDesc("array"), elementType(t) {
}

ArrayTypeDesc::~ArrayTypeDesc() {}

int ArrayTypeDesc::getLower() {
  return lower;
}

int ArrayTypeDesc::getUpper() {
  return upper;
}

string ArrayTypeDesc::getElementType() {
  return elementType;
}

void ArrayTypeDesc::setLower(int l) {
  lower = l;
}

void ArrayTypeDesc::setUpper(int u) {
  upper = u;
}

void ArrayTypeDesc::setElementType(string t) {
  elementType = t;
}


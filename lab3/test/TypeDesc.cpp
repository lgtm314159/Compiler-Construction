#include "TypeDesc.h"
#include "Env.h"

using namespace std;

//TypeDesc::TypeDesc() {}

TypeDesc::TypeDesc(const string& t):
    type(t), lower(0), upper(0), arrayEleType(""), fieldList(NULL) {
}

TypeDesc::TypeDesc(const string& t, int l, int u, const string& et):
    type(t), lower(l), upper(u), arrayEleType(et), fieldList(NULL) {}

TypeDesc::TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fl):
    type(t), lower(0), upper(0), arrayEleType(""), fieldList(fl) {
}

TypeDesc::TypeDesc(const TypeDesc& td):
    type(td.type), lower(td.lower), upper(td.upper),
    arrayEleType(td.arrayEleType), fieldList(td.fieldList) {
}

TypeDesc::~TypeDesc() {
  if (fieldList != NULL) {
    for(int i = 0; i < fieldList->size(); ++i) {
      delete fieldList->at(i).second;
      fieldList->at(i).second = NULL;
    }

    delete fieldList;
    fieldList = NULL;
  }
}

string& TypeDesc::getType() {
  return type;
}

void TypeDesc::setType(const string& t) {
  type = t;
}

int TypeDesc::getLower() {
  return lower;
}

void TypeDesc::setLower(int l) {
  lower = l;
}

int TypeDesc::getUpper() {
  return upper;
}

void TypeDesc::setUpper(int u) {
  upper = u;
}

string& TypeDesc::getArrayEleType() {
  return arrayEleType;
}

void TypeDesc::setArrayEleType(const string& t) {
  arrayEleType = t;
}

vector<pair<string, TypeDesc*> >* TypeDesc::getFieldList() {
  return fieldList;
}


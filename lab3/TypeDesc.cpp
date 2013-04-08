#include "TypeDesc.h"
#include "Env.h"

using namespace std;

//TypeDesc::TypeDesc() {}

TypeDesc::TypeDesc(const string& t):
    type(t), lower(0), upper(0), arrayEleType(NULL), fieldList(NULL) {
}

TypeDesc::TypeDesc(const string& t, int l, int u, TypeDesc* et):
    type(t), lower(l), upper(u), arrayEleType(et), fieldList(NULL) {}

TypeDesc::TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fl):
    type(t), lower(0), upper(0), arrayEleType(NULL), fieldList(fl) {
}

TypeDesc::TypeDesc(const TypeDesc& td):
    type(td.type), lower(td.lower), upper(td.upper),
    arrayEleType(td.arrayEleType) {
  if (td.fieldList != NULL) {
    fieldList = new vector<pair<string, TypeDesc*> >();
    for (int i = 0; i < td.fieldList->size(); ++i) {
      TypeDesc* tmp = new TypeDesc(*(td.fieldList->at(i).second));
      fieldList->push_back(pair<string, TypeDesc*>(td.fieldList->at(i).first, tmp));
    }
  } else {
    fieldList = NULL;
  }

  if (arrayEleType != NULL) {
    arrayEleType = new TypeDesc(*(td.arrayEleType));
  } else {
    arrayEleType = NULL;
  }
}

TypeDesc::~TypeDesc() {
  if (fieldList != NULL) {
    for(int i = 0; i < fieldList->size(); ++i) {
      delete fieldList->at(i).second;
      fieldList->at(i).second = NULL;
    }

    delete fieldList;
    fieldList = NULL;

    delete arrayEleType;
    arrayEleType = NULL;
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

TypeDesc* TypeDesc::getArrayEleType() {
  return arrayEleType;
}

void TypeDesc::setArrayEleType(TypeDesc* t) {
  arrayEleType = t;
}

vector<pair<string, TypeDesc*> >* TypeDesc::getFieldList() {
  return fieldList;
}


#include "TypeDesc.h"
#include "Env.h"
#include <iostream>

using namespace std;

//TypeDesc::TypeDesc() {}

TypeDesc::TypeDesc(const string& t):
    type(t), lower(0), upper(0), arrayEleType(NULL), fieldList(NULL),
    formalParamList(NULL), resultType(NULL) {}

TypeDesc::TypeDesc(const string& t, int l, int u, TypeDesc* et):
    type(t), lower(l), upper(u), arrayEleType(et), fieldList(NULL),
    formalParamList(NULL), resultType(NULL) {}
TypeDesc::TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fl):
    type(t), lower(0), upper(0), arrayEleType(NULL),
    formalParamList(NULL), resultType(NULL) {
  fieldList = new vector<pair<string, TypeDesc*> >();
  for (int i = 0; i < fl->size(); ++i) {
    TypeDesc* td = new TypeDesc(*(fl->at(i).second));
    fieldList->push_back(pair<string, TypeDesc*>(fl->at(i).first, td));
  }
}

TypeDesc::TypeDesc(const string& t, vector<TypeDesc*>* fpl,
    TypeDesc* rt):
    type(t), lower(0), upper(0), arrayEleType(NULL), fieldList(NULL),
    formalParamList(fpl), resultType(rt) {}

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

  if (td.formalParamList != NULL) {
    formalParamList = new vector<TypeDesc*>();
    for (int i = 0; i < td.formalParamList->size(); ++i) {
      TypeDesc* tmp = new TypeDesc(*(td.formalParamList->at(i)));
      formalParamList->push_back(tmp);
    }
  }

  if (td.resultType != NULL) {
    resultType = new TypeDesc(*(td.resultType));
  } else {
    resultType = NULL;
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
  }


  if (arrayEleType != NULL) {
    delete arrayEleType;
    arrayEleType = NULL;
  }

  if (formalParamList != NULL) {
    delete formalParamList;
    formalParamList = NULL;
  }

  if (resultType != NULL) {
    delete resultType;
    resultType = NULL;
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

TypeDesc* TypeDesc::getTypeDescFromFieldList(const string& name) {
  for (int i = 0; i < fieldList->size(); ++i) {
    if (fieldList->at(i).first.compare(name) == 0) {
      return fieldList->at(i).second;
    }
  }
  return NULL;
}

void TypeDesc::displayFieldList() {
  cout << "field list size: " << fieldList->size() << endl;
  for(int i = 0; i < fieldList->size(); ++i) {
    cout << "record field: " << fieldList->at(i).first << " " <<
        fieldList->at(i).second->getType() << endl;

    if (fieldList->at(i).second->getType().compare("record") == 0) {
      fieldList->at(i).second->displayFieldList();
    }
  }
}


#include "TypeDesc.h"
#include "Env.h"

using namespace std;

TypeDesc::TypeDesc(const string& t) {
  type = t;
}

TypeDesc::TypeDesc(const string& t, int l, int u):
    type(t), lower(l), upper(u) {}

TypeDesc::TypeDesc(const string& t, Env* re):
    type(t), recordEnv(re) {
}

TypeDesc::TypeDesc(const TypeDesc& td):
    type(td.type), lower(td.lower), upper(td.upper), recordEnv(td.recordEnv) {
}

TypeDesc::~TypeDesc() {
  delete recordEnv;
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

Env* TypeDesc::getRecordEnv() {
  return recordEnv;
}

void TypeDesc::setRecordEnv(Env* re) {
  recordEnv = re;
}

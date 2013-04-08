#include "Env.h"

using namespace std;

Env::Env(Env* p): prev(p) {
  populateKeywords();
}

Env::Env(const Env& e) {
  prev = e.prev;
  table = e.table;
  populateKeywords();
}

Env::~Env() {}

Env* Env::getPrevEnv() {
  return prev;
}

void Env::setPrevEnv(Env* p) {
  prev = p;
}

Symbol* Env::getSymbol(const string& name) {
  map<string, Symbol>::iterator it = table.find(name);
  if (it != table.end())
    return &((*it).second);
  return NULL;
}

void Env::setSymbol(const string& name, Symbol& symbol) {
  table.insert(pair<string, Symbol>(name, symbol));
}

void Env::populateKeywords() {
  TypeDesc td("nil");
  Symbol sb1("integer", 0, td);
  table.insert(pair<string, Symbol>("integer", sb1));
  Symbol sb2("float", 0, td);
  table.insert(pair<string, Symbol>("float", sb2));
  Symbol sb3("boolean", 0, td);
  table.insert(pair<string, Symbol>("boolean", sb3));
  Symbol sb4("true", 0, td);
  table.insert(pair<string, Symbol>("true", sb4));
  Symbol sb5("false", 0, td);
  table.insert(pair<string, Symbol>("false", sb5));
}

int Env::getTableSize() {
  return table.size();
}


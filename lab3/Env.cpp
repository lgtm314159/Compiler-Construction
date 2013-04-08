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

Env::~Env() {
  map<string, Symbol*>::iterator it;
  for (it = table.begin(); it != table.end(); ++it) {
    delete (*it).second;
    (*it).second = NULL;
  }
}

Env* Env::getPrevEnv() {
  return prev;
}
void Env::setPrevEnv(Env* p) {
  prev = p;
}

Symbol* Env::getSymbol(const string& name) {
  map<string, Symbol*>::iterator it = table.find(name);
  if (it != table.end())
    return table[name];
  return NULL;
}

void Env::setSymbol(const string& name, Symbol* symbol) {
  table.insert(pair<string, Symbol*>(name, symbol));
}

void Env::populateKeywords() {
  TypeDesc* td1 = new TypeDesc("nil");
  Symbol* sb1 = new Symbol("integer", 0, td1);
  table.insert(pair<string, Symbol*>("integer", sb1));
  TypeDesc* td2 = new TypeDesc("nil");
  Symbol* sb2 = new Symbol("string", 0, td2);
  table.insert(pair<string, Symbol*>("string", sb2));
  TypeDesc* td3 = new TypeDesc("nil");
  Symbol* sb3 = new Symbol("boolean", 0, td3);
  table.insert(pair<string, Symbol*>("boolean", sb3));
  TypeDesc* td4 = new TypeDesc("nil");
  Symbol* sb4 = new Symbol("true", 0, td4);
  table.insert(pair<string, Symbol*>("true", sb4));
  TypeDesc* td5 = new TypeDesc("nil");
  Symbol* sb5 = new Symbol("false", 0, td5);
  table.insert(pair<string, Symbol*>("false", sb5));
}

int Env::getTableSize() {
  return table.size();
}


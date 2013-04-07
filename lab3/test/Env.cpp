#include "Env.h"

using namespace std;

Env::Env(Env* p): prev(p) {}

Env::Env(const Env& e) {
  prev = e.prev;
  table = e.table; 
}

Env::~Env() {}

Env* Env::getPrevEnv() {
  return prev;
}

void Env::setPrevEnv(Env* p) {
  prev = p;
}

bool Env::getSymbol(const string& name) {
  if (table.find(name) != table.end())
    return true;
    //Symbol* ptr = &(table[name]);
    //return ptr;
  //} else
    //return NULL;
  return false;
}



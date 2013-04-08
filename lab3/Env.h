#ifndef Env_h
#define Env_h

#include <map>
#include <string>
#include "Symbol.h"

using namespace std;

class Env {
  private:
    Env* prev;
    map<string, Symbol*> table;

  public:
    Env(Env* p);
    Env(const Env& e);
    ~Env();
    Env* getPrevEnv();
    void setPrevEnv(Env* p);
    Symbol* getSymbol(const string& name);
    void populateKeywords();
    void setSymbol(const string& name, Symbol* symbol);
    int getTableSize();
};


#endif


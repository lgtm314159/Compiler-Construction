#ifndef Env_h
#define Env_h

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "Symbol.h"

using namespace std;

class Env {
  private:
    Env* prev;
    string scopeName;
    map<string, Symbol*> table;
    vector<Symbol*> symList;

  public:
    Env(Env* p, const string& scope);
    Env(const Env& e);
    ~Env();
    Env* getPrevEnv();
    void setPrevEnv(Env* p);
    Symbol* getSymbol(const string& name);
    void populateKeywords();
    void setSymbol(const string& name, Symbol* symbol);
    int getTableSize();
    void displayTable();
    void outputSymTable(ofstream& synFile);
};


#endif


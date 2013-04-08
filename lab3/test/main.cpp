// regex_replace example
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <iterator>
#include <sys/time.h>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Symbol.h"
#include "Env.h"

using namespace std;

string func() {
  return NULL;
}

class class1 {
  private:
    string str;

  public:
    class1(const string& s) {
      str = s;
    }

    string& getStr() {
      return str;
    }

    void setStr(const string& s) {
      str = s;
    }
};

int main() {
/*
  TypeDesc td("integer");
  Symbol symbol("a", 0, td);
  TypeDesc td2("float");
  symbol.setTypeDesc(td2);
  Env env(NULL);
  env.setSymbol("a", symbol);
  cout << (env.getSymbol("a"))->getLexime() << endl;
  symbol.setLexime("b");
  cout << (env.getSymbol("a"))->getLexime() << endl;
  cout << env.getTableSize() << endl;
*/
/*
  char arrayStr[] = "array";
  string str(arrayStr); 
  cout << sizeof(arrayStr) << endl;
  cout << str.length() << endl; 
*/

  Env* env = new Env(NULL);
  TypeDesc* td = env->getSymbol("integer")->getTypeDesc(); 
  Symbol* sym = new Symbol("int", 0, td);
  env->setSymbol("int", sym);
  //cout << env->getSymbol("int")->getTypeDesc()->getType() << endl;
/*
  env->getSymbol("integer")->getTypeDesc()->setType("whatever");
  cout << env->getSymbol("int")->getTypeDesc()->getType() << endl;
  cout << env->getSymbol("integer")->getTypeDesc()->getType() << endl;
  cout << env->getTableSize() << endl;
*/
  TypeDesc* td2 = env->getSymbol("integer")->getTypeDesc(); 
  Symbol* sym2 = new Symbol("a", 0, td);
  env->setSymbol("integer", sym2);
  //delete env;
  //delete td;
  delete env;
}


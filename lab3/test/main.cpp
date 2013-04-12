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
  TypeDesc* td = new TypeDesc(*(env->getSymbol("integer")->getTypeDesc())); 
  Symbol* sym = new Symbol("int", 0, td);
  env->setSymbol("int", sym);
  vector<pair<string, TypeDesc*> >* fl = new vector<pair<string, TypeDesc*> >();
  fl->push_back(pair<string, TypeDesc*>("a", new TypeDesc("integer")));
  fl->push_back(pair<string, TypeDesc*>("b", new TypeDesc("integer")));
  TypeDesc* td2 = new TypeDesc("record", fl);
  Symbol* sym2 = new Symbol("c", 0, td2);
  env->setSymbol("c", sym2);

  cout << fl->at(0).second->getType() << endl;
  cout << fl->at(1).second->getType() << endl;
  cout << td2->getTypeDescFromFieldList("a")->getType() << endl;
  cout << td2->getTypeDescFromFieldList("b")->getType() << endl;
  fl->at(0).second->setType("boolean"); 
  fl->at(1).second->setType("string");
  cout << fl->at(0).second->getType() << endl;
  cout << fl->at(1).second->getType() << endl;
  cout << td2->getTypeDescFromFieldList("a")->getType() << endl;
  cout << td2->getTypeDescFromFieldList("b")->getType() << endl;

  for (int i = 0; i < fl->size(); ++i) {
    delete fl->at(i).second;
    fl->at(i).second = NULL;
  }

  delete env;

  //delete env;
  //cout << env->getSymbol("int")->getTypeDesc()->getType() << endl;
/*
  env->getSymbol("integer")->getTypeDesc()->setType("whatever");
  cout << env->getSymbol("int")->getTypeDesc()->getType() << endl;
  cout << env->getSymbol("integer")->getTypeDesc()->getType() << endl;
  cout << env->getTableSize() << endl;
*/
  //delete td;
  //delete env;

  //char* newStr = (char*) malloc(sizeof(str));
  //cout << newStr << endl;

  //string str("array 1 10 string");
  //cout << str << endl;
  //cout << ss << endl;
  //char* var = (char*) malloc(ss.str().length() + 100);
  //strcpy(var, ss.str().c_str());
  //cout << var << endl;
}


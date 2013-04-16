#include "Env.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
using namespace std;

Env::Env(Env* p, const string& scope): prev(p), scopeName(scope) {
  if (prev == NULL) {
    populateKeywords();
  }
}

Env::Env(const Env& e) {
  prev = e.prev;
  table = e.table;
  scopeName = e.scopeName;
  //populateKeywords();
}

Env::~Env() {
  map<string, Symbol*>::iterator it;
  for (it = table.begin(); it != table.end(); ++it) {
    cout << "deleting " << (*it).first << endl;
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
  symList.push_back(symbol);
}

void Env::populateKeywords() {
  TypeDesc* td1 = new TypeDesc("integer");
  Symbol* sb1 = new Symbol("integer", 0, td1);
  table.insert(pair<string, Symbol*>("integer", sb1));
  symList.push_back(sb1);

  TypeDesc* td2 = new TypeDesc("string");
  Symbol* sb2 = new Symbol("string", 0, td2);
  table.insert(pair<string, Symbol*>("string", sb2));
  symList.push_back(sb2);

  TypeDesc* td3 = new TypeDesc("boolean");
  Symbol* sb3 = new Symbol("boolean", 0, td3);
  table.insert(pair<string, Symbol*>("boolean", sb3));
  symList.push_back(sb3);

  TypeDesc* td4 = new TypeDesc("boolean");
  Symbol* sb4 = new Symbol("true", 0, td4);
  table.insert(pair<string, Symbol*>("true", sb4));
  symList.push_back(sb4);

  TypeDesc* td5 = new TypeDesc("boolean");
  Symbol* sb5 = new Symbol("false", 0, td5);
  table.insert(pair<string, Symbol*>("false", sb5));
  symList.push_back(sb5);
}

int Env::getTableSize() {
  return table.size();
}

void Env::displayTable() {
  map<string, Symbol*>::iterator it;
  for (it = table.begin(); it != table.end(); ++it) {
    cout << (*it).first << " " << (*it).second->getTypeDesc()->getType() << endl;
    if ((*it).second->getTypeDesc()->getType().compare("record") == 0)
      (*it).second->getTypeDesc()->displayFieldList();
  }
}

void Env::outputSymTable(ofstream& symFile) {
  //ofstream symFile;
  //symFile.open("symtable.out");
  //map<string, Symbol*>::iterator it;
  symFile << "Symbol table of " << scopeName << ": " << endl;
  stringstream ss; 
  //for (it = table.begin(); it != table.end(); ++it) {
  for (int i = 0; i < symList.size(); ++i) {
    ss.str(string());
    ss << "address: " << i;
    symFile << setw(14) << std::left << ss.str();
    ss.str(string());
    ss << "identifier: " << symList[i]->getLexime();
    symFile << setw(29) << std::left << ss.str();
    ss.str(string());
    ss << "type: " << symList[i]->getTypeDesc()->getType();
    symFile << setw(18) << std::left << ss.str();
    symFile << endl;
  }
}

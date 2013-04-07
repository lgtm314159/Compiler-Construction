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
  TypeDesc td("integer");
  Symbol symbol("a", 0, td);
  cout << symbol.getTypeDesc().getType() << endl;
  TypeDesc td2("float");
  symbol.setTypeDesc(td2);
  cout << symbol.getTypeDesc().getType() << endl;
}



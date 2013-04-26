#ifndef ArrayTypeDesc_H 
#define ArrayTypeDesc_H

#include "BasicTypeDesc.h"

using namespace std;

class ArrayTypeDesc: public BasicTypeDesc {
  private:
    int lower;
    int upper;
    string elementType;

  public:
    ArrayTypeDesc(string t);
    ~ArrayTypeDesc();
    int getLower();
    int getUpper();
    string getElementType();
    void setLower(int l);
    void setUpper(int u);
    void setElementType(string t);
};

#endif


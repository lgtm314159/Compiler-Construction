#ifndef BasicTypeDesc_H
#define BasicTypeDesc_H

#include <string>

using namespace std;

class BasicTypeDesc {
  protected:
    string type;

  public:
    BasicTypeDesc();
    BasicTypeDesc(string t);
    BasicTypeDesc(const BasicTypeDesc& btype);
    virtual ~BasicTypeDesc();
    string getType();
    void setType(string t);
};

#endif


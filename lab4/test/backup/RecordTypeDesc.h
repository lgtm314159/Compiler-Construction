#ifndef RecordTypeDesc_H
#define RecordTypeDesc_H

#include <string>
#include <map>
#include "BasicTypeDesc.h"

using namespace std;

class RecordTypeDesc: public BasicTypeDesc {
  public:
    RecordTypeDesc();
    ~RecordTypeDesc();
};

#endif


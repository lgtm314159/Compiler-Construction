#ifndef TypeDesc_h
#define TypeDesc_h

#include <map>
#include <string>

using namespace std;

class Env;

class TypeDesc {
  private:
    string type;
    // These fields are for array types.
    int lower;
    int upper;
    // This field is for record types.
    Env* recordEnv;
    
  public:
    TypeDesc(const string& t);
    TypeDesc(const string& t, int l, int u);
    TypeDesc(const string& t, Env* re);
    TypeDesc(const TypeDesc& td);
    ~TypeDesc();
    string& getType();
    void setType(const string& t);
    int getLower();
    void setLower(int l);
    int getUpper();
    void setUpper(int u);
    Env* getRecordEnv();
    void setRecordEnv(Env* re); 
};

#endif


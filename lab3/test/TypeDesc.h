#ifndef TypeDesc_h
#define TypeDesc_h

#include <map>
#include <vector>
#include <string>

using namespace std;

class Env;

class TypeDesc {
  private:
    string type;
    // These fields are for array types.
    int lower;
    int upper;
    string arrayEleType;
    // This field is for record types.
    //Env* recordEnv;
    vector<pair<string, TypeDesc*> >* fieldList;
    
  public:
//    TypeDesc();
    TypeDesc(const string& t);
    TypeDesc(const string& t, int l, int u, const string& et);
    //TypeDesc(const string& t, Env* re, vector<pair<string, TypeDesc> >* fl);
    TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fl);
    TypeDesc(const TypeDesc& td);
    ~TypeDesc();
    string& getType();
    void setType(const string& t);
    int getLower();
    void setLower(int l);
    int getUpper();
    void setUpper(int u);
    string& getArrayEleType();
    void setArrayEleType(const string& t);
    Env* getRecordEnv();
    void setRecordEnv(Env* re); 
    vector<pair<string, TypeDesc*> >* getFieldList();
};

#endif


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
    //string arrayEleType;
    TypeDesc* arrayEleType;
    // This field is for record types.
    vector<pair<string, TypeDesc*> >* fieldList;
    // These fields are for function and procedure types.
    vector<pair<string, TypeDesc*> >* formalParamList;
    TypeDesc* resultType;

  public:
//    TypeDesc();
    TypeDesc(const string& t);
    TypeDesc(const string& t, int l, int u, TypeDesc* et);
    //TypeDesc(const string& t, Env* re, vector<pair<string, TypeDesc> >* fl);
    TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fl);
    TypeDesc(const TypeDesc& td);
    TypeDesc(const string& t, vector<pair<string, TypeDesc*> >* fpl,
        TypeDesc* rt);
    ~TypeDesc();
    string& getType();
    void setType(const string& t);
    int getLower();
    void setLower(int l);
    int getUpper();
    void setUpper(int u);
    TypeDesc* getArrayEleType();
    void setArrayEleType(TypeDesc* t);
    Env* getRecordEnv();
    void setRecordEnv(Env* re); 
    vector<pair<string, TypeDesc*> >* getFieldList();
    void displayFieldList();
};

#endif


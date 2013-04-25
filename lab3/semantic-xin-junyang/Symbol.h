#ifndef Symbol_h
#define Symbol_h

#include <string>
#include "TypeDesc.h"

using namespace std;

class Symbol {
  private:
    string lexime;
    int offset;
    TypeDesc* typeDesc;

  public:
//    Symbol();
    Symbol(const string& lex, int off, TypeDesc* td);
    Symbol(const Symbol& sb);
    ~Symbol();
    string& getLexime();
    void setLexime(const string& lex);
    int getOffset();
    void setOffset(int off);
    TypeDesc* getTypeDesc();
    void setTypeDesc(TypeDesc* typeDesc);
};

#endif


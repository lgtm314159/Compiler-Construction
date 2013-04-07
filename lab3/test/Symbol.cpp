#include "Symbol.h"

using namespace std;

Symbol::Symbol(const string& lex, int off, const TypeDesc& td):
    lexime(lex), offset(off), typeDesc(td) {
}

Symbol::Symbol(const Symbol& sb): lexime(sb.lexime), offset(sb.offset),
  typeDesc(sb.typeDesc) {}

Symbol::~Symbol() {}

string& Symbol::getLexime() {
  return lexime;
}

void Symbol::setLexime(const string& lex) {
  lexime = lex;
}

int Symbol::getOffset() {
  return offset;
}

void Symbol::setOffset(int off) {
  offset = off;
}

TypeDesc Symbol::getTypeDesc() {
  return typeDesc;
}

void Symbol::setTypeDesc(const TypeDesc& td) {
  typeDesc = td;
}


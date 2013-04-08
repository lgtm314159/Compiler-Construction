#!/bin/bash

bison -vd parser.y
flex lexicalAnalyzer.l
#g++ parser.tab.c lex.yy.c -lfl -o parser
make

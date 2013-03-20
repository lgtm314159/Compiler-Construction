#!/bin/bash

bison -vd Parser.y
flex lexicalAnalyzer.l
g++ Parser.tab.c lex.yy.c -lfl -o parser

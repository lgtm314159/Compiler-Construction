#!/bin/bash

mck
g++ parser.tab.c lex.yy.c TypeDesc.cpp Env.cpp Symbol.cpp -g -lfl -o parser


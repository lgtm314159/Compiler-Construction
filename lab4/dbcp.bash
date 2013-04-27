#!/bin/bash

mck
g++ parser.tab.c lex.yy.c -g -lfl -o parser


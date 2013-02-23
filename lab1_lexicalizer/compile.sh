#!/bin/bash

flex lexicalAnalyzer.l
gcc lex.yy.c -lfl


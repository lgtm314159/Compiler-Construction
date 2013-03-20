#!/bin/bash

for f in 1 2 3 4 5; do 
	../src/parser test${f}.pas 
	mv rule.out test${f}_rule.out
	 mv symtable.out test${f}_symtable.out; 
done

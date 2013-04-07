ifdef OPT 
  CCFLAGS = -O2 
else
  CCFLAGS = -g
endif

CC=g++
FLEX=flex
BISON=bison
CFLAGS=-lfl
FLEX_SOURCES=lex.yy.c
BISON_SOURCES=parser.tab.c
MY_SOURCES=BasicTypeDesc.cpp ArrayTypeDesc.cpp RecordTypeDesc.cpp
FLEXFILE=lexicalAnalyzer.l
BISONFILE=parser.y
BISONFLAGS=-d
EXECUTABLE=parser
OBJECTS=$(MY_SOURCES:.cpp=.o)

all: run_parser
	
run_parser: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(FLEX_SOURCES) $(BISON_SOURCES) $(OBJECTS)
	$(CC) $(FLEX_SOURCES) $(BISON_SOURCES) $(OBJECTS) $(CFLAGS) -o $(EXECUTABLE)

$(FLEX_SOURCES):
	$(FLEX) $(FLEXFILE)

$(BISON_SOURCES):
	$(BISON) $(BISONFLAGS) $(BISONFILE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(EXECUTABLE) parser.tab.h $(BISON_SOURCES) $(FLEX_SOURCES) *.o

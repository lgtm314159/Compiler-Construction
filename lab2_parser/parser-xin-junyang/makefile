CC=g++
FLEX=flex
BISON=bison
CFLAGS=-lfl
FLEX_SOURCES=lex.yy.c
BISON_SOURCES=parser.tab.c
FLEXFILE=lexicalAnalyzer.l
BISONFILE=parser.y
BISONFLAGS=-d
EXECUTABLE=parser

all: run_parser
	
run_parser: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(FLEX_SOURCES) $(BISON_SOURCES)
	$(CC) $(FLEX_SOURCES) $(BISON_SOURCES) $(CFLAGS) -o $(EXECUTABLE)

$(FLEX_SOURCES):
	$(FLEX) $(FLEXFILE)

$(BISON_SOURCES):
	$(BISON) $(BISONFLAGS) $(BISONFILE)

clean:
	rm -rf $(SOURCES) *.h *.c *.out $(EXECUTABLE)

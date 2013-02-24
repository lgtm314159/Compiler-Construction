CC=gcc
FLEX=flex
CFLAGS=-lfl
SOURCES=lex.yy.c
FLEXFILE=lexicalAnalyzer.l
EXECUTABLE=lexer

all: run_lexer
	
run_lexer: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

$(SOURCES):
	$(FLEX) $(FLEXFILE)

clean:
	rm -rf $(SOURCES) $(EXECUTABLE)
